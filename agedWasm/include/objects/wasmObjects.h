#ifndef _WASMOBJECT_H
#define _WASMOBJECT_H

#include <objects/types/typesObject.h>
#include <objects/funcs/funcsObject.h>
#include <objects/tables/tablesObject.h>
#include <objects/mems/memsObject.h>
#include <objects/globals/globalsObject.h>
#include <objects/elem/elemObject.h>
#include <objects/data/dataObject.h>
#include <objects/start/startObject.h>
#include <objects/imports/importsObject.h>
#include <objects/exports/exportsObject.h>
#include <objects/magic/magicObject.h>

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