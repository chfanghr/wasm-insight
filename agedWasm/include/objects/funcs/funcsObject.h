#ifndef _FUNCSOBJECT_H
#define _FUNCSOBJECT_H

#include <datas/str.h>

typedef struct funcsObject_s {
    VECTOR_OF(Idx_type) funcs;
} funcsObject_t;

#endif