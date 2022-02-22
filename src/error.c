#include<error.h>

/*
 * All the fprintf functions are writing to STDERR.
 */

void useage(char **argv){
    fprintf(stderr, "Usage:\n  %s: <map_file_name>\n", argv[0]);
}

void tooManyArg(int *argc, char **argv){
    int i;
    fprintf(stderr, "Error: %s -> Too many arguments ‘", argv[0]);
    for (i = 1; i < (*argc); i++)
        fprintf(stderr, "%s ", argv[i]);
    fprintf(stderr, "’\n");

    useage(argv);
}

void tooFewArg(char **argv){
    fprintf(stderr, "Error: %s -> Too few arguments.\n", argv[0]);
    useage(argv);
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

