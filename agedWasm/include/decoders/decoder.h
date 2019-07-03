#ifndef _DECODER_H
#define _DECODER_H

#include <datas/types.h>
#include <objects/wasmObjects.h>

#include <array/array.h>

wasmObject_t* decode(array wasm);

#endif