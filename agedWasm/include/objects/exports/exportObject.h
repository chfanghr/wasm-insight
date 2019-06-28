#ifndef _EXPORTOBJECT_H
#define _EXPORTOBJECT_H

#include <datas/types.h>

typedef struct exportObject_s
{
    chr8* name;
    Kind_type type;
    Idx_type idx;
} exportObject_t;


#endif