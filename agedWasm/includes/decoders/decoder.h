#ifndef _DECODER_H
#define _DECODER_H

#include <stdlib.h>

#include <datas/types.h>
#include <objects/wasmObject.h>

WASM_OBJECT * decode(bt8* wasm, size_t len);

#endif