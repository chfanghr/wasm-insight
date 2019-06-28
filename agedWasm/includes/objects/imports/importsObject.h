#ifndef _IMPORTSOBJECT_H
#define _IMPORTSOBJECT_H

#include <datas/str.h>
#include <objects/imports/importObject.h>

typedef struct importsObject_s
{
    VECTOR_OF(importObject_t*) imports;
} importsObject_t;

#endif