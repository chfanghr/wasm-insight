#ifndef _EXPORTOBJECT_H
#define _EXPORTOBJECT_H

#include <datas/types.h>
#include <datas/vector.h>

typedef struct exportObject_s
{
    VECTOR_OF(byte) name;
    Idx_type idx;
} exportObject_t;


#endif