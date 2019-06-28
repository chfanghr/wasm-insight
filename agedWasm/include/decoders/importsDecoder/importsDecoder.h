#ifndef _IMPORTSDECODER_H
#define _IMPORTSDECODER_H

#include <datas/types.h>
#include <objects/imports/importsObject.h>

importsObject_t* decodeImports(BUFFER* buf);

#endif