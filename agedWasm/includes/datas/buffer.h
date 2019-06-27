#ifndef _BUFFER_H
#define _BUFFER_H

#include <datas/types.h>
#include <platform/adaptLibs.h>

typedef struct BUFFER_s {
    byte *buffer;
    siz_t size;
} BUFFER;

/* Initialize `BUF` with `SIZE` in size and `FILL` to fill with*/
#define BUFFER_INIT(BUF, SIZE, FILL) do {\
    (BUF).buffer = malloc_a((SIZE)*sizeof(byte));\
    ASSERT_A((BUF).buffer,"malloc failed!\n");\
    (BUF).size = (SIZE);\
    memset_a(BUFFER_DATA((BUF)),(FILL),BUFFER_SIZE((BUF)));\
} while(0)

/* Free a buffer */
#define BUFFER_FREE(BUF) do {\
    if((BUF).size>0)free_a((BUF).buffer);\
    (BUF).size = 0;\
} while(0)

/* Fill data in size of `SIZ` from `PTR` to buffer `BUF` with offset of buffer`OFFS`*/
#define BUFFER_FILL(BUF,OFFS,PTR,SIZ) do {\
    ASSERT_A(!((OFFS)+(SIZ)>BUFFER_SIZE(BUF) || (SIZ)<0),"fill failed!\n");\
    i32 i;\
    for(i=0;i<(i32)(SIZ);i++) BUFFER_DATA(BUF)[(OFFS)+i] = (PTR)[i];\
} while(0)

/* Fill data in size of `SIZ` from buffer `ORI` with offset `OFF` to buffer `BUF` with offset `OFFS` */
#define BUFFER_SLCE(BUF,OFFS,ORI,OFF,SIZ) do {\
    ASSERT_A(!((OFF)+(SIZ)>BUFFER_SIZE(ORI) || (OFFS)+(SIZ)>BUFFER_SIZE(BUF)),"slice failed!\n");\
    BUFFER_FILL(BUF,OFFS,(byte*)(BUFFER_DATA(ORI)+OFF),SIZ);\
} while(0)

/* Read data in size of `SIZ` from buffer `BUF` with offset `OFFS` to `PTR` */
#define BUFFER_READ(BUF,OFFS,PTR,SIZ) do {\
    ASSERT_A(!((OFFS)+(SIZ)>BUFFER_SIZE(BUF) || (SIZ)<0),"read failed!\n");\
    i32 i=0;\
    for(i=0;i<(SIZ);i++) ((byte*)PTR)[i]=BUFFER_DATA(BUF)[(OFFS)+i];\
} while(0)

/* Get the pointer to buffer `BUF`'s data */
#define BUFFER_DATA(BUF) (BUF).buffer

/* Get the size of buffer `BUF` */
#define BUFFER_SIZE(BUF) (BUF).size

#endif