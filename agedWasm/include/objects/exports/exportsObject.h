#ifndef _EXPORTSOBJECT_H
#define _EXPORTSOBJECT_H

#include <datas/types.h>
#include "exportObject.h"

typedef struct exportsObject_s
{
    VECTOR_OF(exportObject_t*) exports;
} exportsObject_t;

#endif