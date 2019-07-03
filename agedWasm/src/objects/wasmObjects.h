#ifndef _WASMOBJECT_H
#define _WASMOBJECT_H

#include "types/typesObject.h"
#include "funcs/funcsObject.h"
#include "tables/tablesObject.h"
#include "mems/memsObject.h"
#include "globals/globalsObject.h"
#include "elem/elemObject.h"
#include "data/dataObject.h"
#include "start/startObject.h"
#include "imports/importsObject.h"
#include "exports/exportsObject.h"
#include "magic/magicObject.h"

typedef struct wasmObject_s {
    typesObject_t*       types;
    funcsObject_t*       funcs;
    tablesObject_t*      tables;
    memsObject_t*        mems;
    globalsObject_t*     globals;
    elemObject_t*        elem;
    dataObject_t*        data;
    startObject_t*       start;
    importsObject_t*     imports;
    exportsObject_t*     exports;
    magicObject_t*       magic;
} wasmObject_t;

#endif