#ifndef _DECODER_H
#define _DECODER_H

#include <datas/str.h>
#include <objects/wasmObjects.h>

wasmObject_t* decode(byte* wasm, siz_t len);

#endif