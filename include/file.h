#ifndef _FILE_H_
#define _FILE_H_

#include "common.h"

int copy(const char *, const char *);
void append_to_file(char [], char []);
void create_file(char *, char *);
void create_or_update(char *, char *);
bool checkIfFileExists(char *);

#endif
