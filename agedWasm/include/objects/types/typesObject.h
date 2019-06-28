#ifndef _TYPESOBJECT_H
#define _TYPESOBJECT_H

#include <datas/types.h>
#include "typeObject.h"

typedef struct typesObject_s
{
    VECTOR_OF(typeObject_t*) types;
} typesObject_t;


#endif