#ifndef _IMPORTSOBJECT_H
#define _IMPORTSOBJECT_H

#include "../../datas/types.h"
#include "importObject.h"

typedef struct importsObject_s
{
    VECTOR_OF(importObject_t*) imports;
} importsObject_t;

#endif