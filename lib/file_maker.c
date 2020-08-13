#include "file_maker.h"
/*
	need to modify the:
		* file writing part, if the file exist then it should just add the
		  executable path in the beginning.
		* add more detail to the error massages.
		* make the chmod efficient by reading the umask and setting the file 
		  reading and writing permissions according to that. 
*/
int file_maker(char *file_name, short type){
	char int_path[PATH_MAX + 1];
	bzero(&int_path, sizeof(int_path));
	
	if (type == CUST){
		// if the type is costume then processing the argument
		int len = 0;
		char **fn_path = split(file_name, ";", &len);
        if (len != 2){
            printf("invalid argument for '--custom' option\n");
            exit(0);
        }
    	printf("%s | %s\n", fn_path[0], fn_path[1]);
    	memcpy(int_path, fn_path[0], strlen(fn_path[0]));
		file_name = fn_path[1];
     }

	if (type != CUST){
		if (type <= SH)
			sprintf(int_path, "/%s%s", EXE_PATH[1], OPTION_BIO[type]);
		else{
			if (type == PY2 || type == PY3)
				sprintf(int_path, "/%s%spython%s", EXE_PATH[2], EXE_PATH[1], 
					(type == PY2) ? "2" : "3");
			else
				sprintf(int_path, "/%s%s%s", EXE_PATH[2], EXE_PATH[1], OPTION_BIO[type]);
		}	

	}

	char r_path[PATH_MAX + 1];
	bzero(&r_path, PATH_MAX);
	realpath(file_name, r_path);
	
	// checking if the file is a exiting directory.
	if (isDir(r_path)){
		sprintf(r_path, "\"%s\" is a directory that already exits.", file_name);
		check(ERROR, r_path);
	}

	// opening/creating the file
	int fd = open(r_path, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);

	// adding the executable 
	dprintf(fd, "%s%s\n", EXE_PATH[0], int_path);
	// printf("%s\n", realpath(int_path, NULL));
	close(fd);
	// making the file a executable.
    if (chmod (r_path, strtol("0755", 0, 8)) < 0){
        fprintf(stderr, "%s: error in chmod(%s, %s) - %d (%s)\n",
                "scriptBoy", file_name, "0755", errno, strerror(errno));
    }
	return 1;
}

bool isDir(const char* target){
   struct stat statbuf;
   stat(target, &statbuf);
   return S_ISDIR(statbuf.st_mode);
}

// int main(int argc, char **argv)
// {
//     char mode[] = "0777";
//     char buf[100] = "/home/hello.t";
//     int i;
//     i = strtol(mode, 0, 8);
//     return(0);
// }

