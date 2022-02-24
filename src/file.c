#include<file.h>

#define BUF_SIZE 65536 //2^16

int copy(const char* in_path, const char* out_path){
	/*
	 * Just simply copys a file
	 */

    size_t n;
    FILE* in = NULL, * out = NULL;
    char* buf = calloc(BUF_SIZE, 1);
    if((in = fopen(in_path, "rb")) && (out = fopen(out_path, "wb")))
        while((n = fread(buf, 1, BUF_SIZE, in)) && fwrite(buf, 1, n, out));
    free(buf);
    if(in) fclose(in);
    if(out) fclose(out);
    return EXIT_SUCCESS;
}

void append_to_file(char source[], char destination[]){

    int fd1, fd2, n;

    char buffer[1];

    if ((fd1 = open(source, O_RDONLY)) < 0)
        fprintf(stderr, "Unable to open file [%s]\n", source);
 
    if ((fd2 = open(destination, O_APPEND | O_WRONLY)) < 0)
        fprintf(stderr, "Unable to open file [%s]\n", destination);
               
    while ((n = read(fd1, buffer, 1)) > 0)
        write(fd2, buffer, 1);
        /* printf("%s", buffer); */

    close(fd1);
    close(fd2);
  

} 

bool checkIfFileExists(char *fileName){
    /*
     * Check if a file exists or not. And also 
     * If the file is readable. If exists than 
     * return TRUE else FALSE.
     */ 
    if (access(fileName, F_OK | R_OK) == 0)
        return true;
    else
        return false; 
}

void create_or_update(char *file_name, char *exe_name){
	/*
	 * First check if the file exists.
	 * If exists then update it with interpreter line
	 * And make it executable.
	 * If not then just create the file
	 */

    if (!checkIfFileExists(file_name)){
        create_file(file_name, exe_name);
    }else{
        char tmp_file[512];
        
        sprintf(tmp_file, "%s.tmp_filejlkncnvd", file_name);

        if (copy(file_name, tmp_file) == EXIT_SUCCESS){
            create_file(file_name, exe_name);

            append_to_file(tmp_file, file_name);

            remove(tmp_file);

            char mode[] = "0755";
            int i;
            i = strtol(mode, 0, 8);
            if (chmod(file_name, i) < 0){
                fprintf(stderr, "Error: can not change file permission!\n");
            }
        }else{
            fprintf(stderr, "Couldn't Update %s\n", file_name);
        }
    }


}

void create_file(char *file_name, char *exe_name){

	/*
	 * Creats a new file with proper permission and interpreter.
	 */

	int fd = open(file_name, O_WRONLY | O_CREAT, 0755);

	char str[32];

	sprintf(str, "#!/usr/bin/env %s\n", exe_name);

	for (int i = 0; str[i] != '\0'; i++)
		write(fd, &str[i], 1);

	close(fd);

}
