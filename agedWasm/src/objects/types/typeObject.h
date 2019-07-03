#ifndef _TYPEOBJECT_H
#define _TYPEOBJECT_H

#include "../../datas/types.h"

typedef struct typeObject_s
{
    VECTOR_OF(Val_type) param;
    VECTOR_OF(Val_type) result;
} typeObject_t;


#endif