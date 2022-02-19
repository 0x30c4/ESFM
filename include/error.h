#ifndef _ERROR_H_
#define _ERROR_H_

#include "common.h"

void useage(char **);
void tooManyArg(int *, char **);
void tooFewArg(char **);
bool checkIfFileExists(char *);

#endif
