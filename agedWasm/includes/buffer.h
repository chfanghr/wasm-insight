#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

#define BUFFER struct {\
    bt8 *buffer;\
    size_t size;\
}

#define BUFFER_INIT(BUF,SIZE,FILL) do {\
    (BUF).buffer = malloc((SIZE)*sizeof(bt8));\
    if(!(BUF).buffer){\
        fputs("malloc failed!\n", stderr);\
        abort();\
    }\
    (BUF).size = (SIZE);\
    memset(BUFFER_DATA((BUF)),(FILL),BUFFER_SIZE((BUF)));\
} while(0)

#define BUFFER_FREE(BUF) do {\
    (BUF).size = 0;\
    free((BUF).buffer);\
} while(0)

#define BUFFER_FILL(BUF,OFFS,PTR,SIZ) do {\
    if((OFFS)+(SIZ)>BUFFER_SIZE(BUF) || (SIZ)<0){\
        fputs("fill failed!\n", stderr);\
        abort();\
    }\
    int i;\
    for(int i=0;i<(SIZ);i++) BUFFER_DATA(BUF)[(OFFS)+i] = PTR[i];\
} while(0)

#define BUFFER_SLCE(BUF,OFFS,ORI,OFF,SIZ) do {\
    if((OFF)+(SIZ)>BUFFER_SIZE(ORI) || (OFFS)+(SIZ)>BUFFER_SIZE(BUF)){\
        fputs("slice failed!\n", stderr);\
        abort();\
    }\
    BUFFER_FILL(BUF,OFFS,(bt8)(BUFFER_DATA(ORI)+OFF),SIZ);\
} while(0)

#define BUFFER_DATA(BUF) (BUF).buffer

#define BUFFER_SIZE(BUF) (BUF).size