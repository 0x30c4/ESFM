#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <math.h>
#include <time.h>

/*----------------------------------------------------------------
    Here I'm defining TRUE and FALSE and typedefing short as bool.
    Which will help me to write code more efficiently.
*/

#define TRUE   1
#define FALSE  0

/*----------------------------------------------------------------
    If a user presses this `EXIT_CHAR` then the game will stop.
*/

#define EXIT_CHAR 'q'

typedef short bool;

typedef struct mapInfo_ {
   int metadata_amount;
   int map_row;
   int map_col;
} mapInfo_t;

#endif
