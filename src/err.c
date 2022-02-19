#include "err.h"

void print_usage(const char *PN){
    // "Specify document root <docroot> for built-in web server"
    fprintf(stderr, "usage: %s -p port -P password -S special_dir [-t docroot]\n", PN);
    exit(EXIT_FAILURE);
}

int check(int exp, const char *msg){
	if (exp == -1){
		fprintf(stderr, "%s%s%s", RED, UNDERLINE, BOLD);
		perror(msg);
		fprintf(stderr, "%s", RESETALL);
		exit(EXIT_FAILURE);
	}
	return exp;
}
