#include "decoder.h"

#include <datas/types.h>
#include <datas/buffer.h>
#include <datas/vector.h>
#include <consts/nums.h>
#include <decoders/magicDecoder/magicDecoder.h>
#include <datas/readers/byteReaders/byteReaders.h>
#include <datas/readers/uintReaders/uintReaders.h>
#include <platform/adaptLibs.h>

wasmObject_t* decode(byte* wasm, siz_t len){
    wasmObject_t* r;
    
    siz_t pointer = 0;
    BUFFER wasmRAW;
    BUFFER_INIT(wasmRAW,len,0x00);
    BUFFER_FILL(wasmRAW,0,wasm,len);

    /* decode magic */
    BUFFER magicRAW;
    BUFFER_INIT(magicRAW,sizeof_magic+sizeof(i32),0x00);
    BUFFER_SLCE(magicRAW,0,wasmRAW,0,sizeof_magic+sizeof(i32));
    magicObject_t* res = decodeMagic(&magicRAW);
    debug_out("WASM Version: %d\n",res->version);
    free_a(res);
    BUFFER_FREE(magicRAW);
    pointer += sizeof_magic+sizeof(i32);
    
    /* find segs */
    while (true)
    {
        if(pointer>=BUFFER_SIZE(wasmRAW)) break;
        byte id;
        u32 len;
        id = readByte8(&wasmRAW,&pointer);
        len = readUint32(&wasmRAW,&pointer);
        debug_out("Seg ID: %x\n",id);
        debug_out("Seg len: %d\n",len);
        pointer += len;
    }
    

    BUFFER_FREE(wasmRAW);
    return r;
}