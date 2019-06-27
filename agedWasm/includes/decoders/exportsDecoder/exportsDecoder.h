#ifndef _EXPORTSDECODER_H
#define _EXPORTSDECODER_H

#include <datas/buffer.h>
#include <objects/exports/exportsObject.h>

exportsObject_t* decodeExports(BUFFER* buf);

#endif