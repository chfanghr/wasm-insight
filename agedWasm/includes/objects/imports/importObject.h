#ifndef _IMPORTOBJECT_H
#define _IMPORTOBJECT_H

#include <datas/types.h>

typedef struct importObject_s
{
    str_t*              module;
    str_t*              field;
    ImportKind_type     kind;
} importObject_t;


#endif