#include "decoder.h"

#include <stdio.h>
#include <datas/types.h>
#include <datas/buffer.h>
#include <datas/vector.h>
#include <consts/nums.h>
#include <decoders/magicDecoder/magicDecoder.h>

wasmObject_t* decode(bt8* wasm, size_t len){
    wasmObject_t* r;
    
    BUFFER wasmRAW;
    BUFFER_INIT(wasmRAW,len,0x00);
    BUFFER_FILL(wasmRAW,0,wasm,len);

    BUFFER magicRAW;
    BUFFER_INIT(magicRAW,sizeof_magic+sizeof(i32),0x00);
    BUFFER_SLCE(magicRAW,0,wasmRAW,0,sizeof_magic+sizeof(i32));
    magicObject_t* res = decodeMagic(&magicRAW);
    printf("WASM Version: %d\n",res->version);

    free(res);
    BUFFER_FREE(magicRAW);
    BUFFER_FREE(wasmRAW);

    return r;
}