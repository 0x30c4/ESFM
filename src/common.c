#include "common.h"

const char OPTION_BIO[11][7] = {
    "bash\0",
    "sh\0",
    "zsh\0",
    "fish\0",
    "php\0",
    "py2\0",
    "py3\0",
    "ruby\0",
    "perl\0",
    "custom\0",
    "help\0"
};

const char EXE_PATH[3][5] = {
    "#!\0",
    "bin/\0",
    "usr/\0"
};

// splits a string every time it finds a specific character. and returns a string array.  
char **split(const char *str, const char *d, int *len){
    char _str[BUFSIZE];
    char** result = 0;
    char *rest = NULL;
    char *token;
    int count = 0;
    bzero(&_str, BUFSIZE);
    strncpy(_str, str, strlen(str));

    for (token = strtok_r(_str, d, &rest);
        token != NULL;
        token = strtok_r(NULL, d, &rest)){
        // printf("%s\n", token);
        count++;
    }   

    strncpy(_str, str, strlen(str));
    result = malloc(sizeof(char*) * count + 1);

    if (result){
        size_t idx  = 0;

        // *(result + idx++) = "hello";

        for (token = strtok_r(_str, d, &rest);
            token != NULL;
            token = strtok_r(NULL, d, &rest)){
            
            if (idx < count){
                *(result + idx++) = strdup(token);
            }
        }

    }
    *len = count;
    return result;
}
