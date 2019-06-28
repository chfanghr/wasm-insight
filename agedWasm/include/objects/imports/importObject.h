#ifndef _IMPORTOBJECT_H
#define _IMPORTOBJECT_H

#include <datas/types.h>

typedef struct importObject_s
{
    chr8*         module;
    chr8*         field;
    Kind_type     kind;
} importObject_t;


#endif