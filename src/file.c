#include<file.h>

#define BUF_SIZE 65536 //2^16

/*
 * Function: copy 
 * ----------------------------
 *   Simply copys a file. And returns the EXIT_SUCCESS if
 *   there was no error.
 *
 *   in_path  : the file which will be copyed.
 *   out_path : the new file path/name.
 *
 *   returns: int 
 */

int copy(const char* in_path, const char* out_path){

    // TODO: update the error handeling part.

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


/*
 * Function: append_to_file
 * ----------------------------
 *   This function appends a file to another file. 
 *   source file will be append to the destination file. 
 *
 *   source      : the file which will be apped to the `destination`.
 *   destination : the file to which `source` will be appended to.
 *
 *   returns: void
 */

void append_to_file(char source[], char destination[]){

    int fd1, fd2, n;

    char buffer[1];

    // Checking for error while creating file descriptor for both file's.

    if ((fd1 = open(source, O_RDONLY)) < 0)
        fprintf(stderr, "Unable to open file [%s]\n", source); 
 
    if ((fd2 = open(destination, O_APPEND | O_WRONLY)) < 0)
        fprintf(stderr, "Unable to open file [%s]\n", destination);
               
    // Writing to the `destination`.
    while ((n = read(fd1, buffer, 1)) > 0)
        write(fd2, buffer, 1);

    close(fd1);
    close(fd2);
  

} 

/*
 * Function: check_if_file_exists 
 * ----------------------------
 *   Check if a file exists or not. And also check
 *   if the file is readable. If exists than return
 *   true else false.
 *
 *   file_name: the file name which user will pass 
 *
 *   returns: bool
 */

bool check_if_file_exists(char *file_name){
    if (access(file_name, F_OK | R_OK) == 0)
        return true;
    else
        return false; 
}

/*
 * Function: create_or_update 
 * ----------------------------
 *  First check if the file exists. If exists then 
 *  update it with interpreter line And make it
 *  executable. If not then just create the file with 
 *  `create_file` function.
 *  	 
 *   file_name: the file name which user will pass 
 *   exe_name : the interpreter name
 *
 *   returns: void
 */

void create_or_update(char *file_name, char *exe_name){

    // Checking if the file exists.
    if (!check_if_file_exists(file_name)){
        create_file(file_name, exe_name);
    }else{
        char tmp_file[512]; // Setting up buffer for the tmp file.
        
        sprintf(tmp_file, "%s.tmp_filejlkncnvd", file_name); // Setting the tmp file to a random name.

        // Creating a backup of the file to append the old content to the new
        // file in the future.
        if (copy(file_name, tmp_file) == EXIT_SUCCESS){
            create_file(file_name, exe_name);

            append_to_file(tmp_file, file_name); // appending tmp_file to the original file.

            remove(tmp_file); // removing the tmp_file.

            // TODO: Currently the create_file can't change the file permission of a old file.
            char mode[] = "0755";
            int i;
            i = strtol(mode, 0, 8);
            if (chmod(file_name, i) < 0){
                fprintf(stderr, "Error: can not change file permission!\n"); // print error if can't change file permission.
            }
        }else{
            fprintf(stderr, "Couldn't Update %s\n", file_name);
        }
    }
}

/*
 * Function: create_file 
 * ----------------------------
 *   Creates A file with executable file permission on.
 *   And with the proper interpreter name at the beginning 
 *   of the file.
 *   
 *   file_name: the file name which user will pass 
 *   exe_name : the interpreter name
 *
 *   returns: void
 */

void create_file(char *file_name, char *exe_name){

	int fd = open(file_name, O_WRONLY | O_CREAT, 0755); // Create file with executable permission on.

	char str[32];

	sprintf(str, "#!/usr/bin/env %s\n", exe_name); // Adding the interpreter line at the beginning

    // Writing data to the file.
	for (int i = 0; str[i] != '\0'; i++)
		write(fd, &str[i], 1);

	close(fd);

}
