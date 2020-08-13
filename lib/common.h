#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>                                                                                                                         
#include <sys/stat.h>                                                                                                                          
#include <fcntl.h>                                                                                                                          
#include <limits.h>
#include <time.h>
#include <getopt.h>
#include <string.h>
#include <regex.h>
#include <errno.h>


#define BASH 0
#define SH   1
#define ZSH  2
#define FISH 3
#define PHP  4
#define PY2  5
#define PY3  6
#define RUBY 7
#define PERL 8
#define CUST 9
#define HELP 10

#define FILE_NAME_TYPE_ARRAY_MAX 255
#define BUFSIZE 4096
//Bash colors and other formatting.

//Colors
#define RED            "\e[31m"
#define GREEN          "\e[32m"
#define LIGHTGREEN     "\e[32m"

//Formats.
#define RESETALL       "\e[0m"
#define BOLD           "\e[1m"
#define UNDERLINE      "\e[4m"
#define BLINK          "\e[5m"

const char OPTION_BIO[11][7];
const char EXE_PATH[3][5];

struct FILE_NAME_TYPE{
	short type;
	char  file_name[NAME_MAX + 1];
};

char **split(const char *str, const char *d, int *len);

#endif