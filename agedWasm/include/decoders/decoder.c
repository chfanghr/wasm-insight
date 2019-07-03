#include "decoder.h"

#include <consts/nums.h>
#include <decoders/magicDecoder/magicDecoder.h>
#include <decoders/typesDecoder/typesDecoder.h>
#include <decoders/funcsDecoder/funcsDecoder.h>
#include <decoders/exportsDecoder/exportsDecoder.h>
#include <decoders/importsDecoder/importsDecoder.h>
#include <datas/readers/readers.h>

#include <buffer/buffer.h>
#include <stdlib.h>

wasmObject_t* decode(array wasm){
    wasmObject_t* r = malloc(sizeof(wasmObject_t));
    
    siz_t pointer = 0;
    BUFFER wasmRAW;
    BUFFER_INIT(wasmRAW,array_size(wasm),0x00);
    BUFFER_FILL(wasmRAW,0,(byte*)array_get_data(wasm),array_size(wasm));

    /* decode magic */
    array magicRAWarr = array_slice(wasm,0,sizeof_magic+sizeof(i32));
    magicObject_t* res = decodeMagic(magicRAWarr);
    debug_out("\nWASM Version: %d\n",res->version);
    free_a(res);
    array_destroy(magicRAWarr);
    pointer += sizeof_magic+sizeof(i32);
    
    /* find segs */
    while (true)
    {
        if(pointer>=BUFFER_SIZE(wasmRAW)) break;
        Seg_id id;
        u32 len;
        id = readByte8(&wasmRAW,&pointer);
        len = readUint32(&wasmRAW,&pointer);
        debug_out("Seg ID: %x ",id);
        debug_out("Seg len: %d ",len);

        BUFFER segRAW;
        BUFFER_INIT(segRAW,len,0x00);
        BUFFER_SLCE(segRAW,0,wasmRAW,pointer,len);
        //TODO: decode seg
        switch (id)
        {
        case Seg_custom:
            debug_out("Seg Type: custom\n");
            break;
        case Seg_type:
            debug_out("Seg Type: type\n");
            r->types = decodeTypes(&segRAW);
            break;
        case Seg_import:
            debug_out("Seg Type: import\n");
            r->imports = decodeImports(&segRAW);
            break;
        case Seg_function:
            debug_out("Seg Type: function\n");
            r->funcs = decodeFuncs(&segRAW);
            break;
        case Seg_table:
            debug_out("Seg Type: table\n");
            break;
        case Seg_memory:
            debug_out("Seg Type: memory\n");
            break;
        case Seg_global:
            debug_out("Seg Type: global\n");
            break;
        case Seg_export:
            debug_out("Seg Type: export\n");
            r->exports = decodeExports(&segRAW);
            break;
        case Seg_start:
            debug_out("Seg Type: start\n");
            break;
        case Seg_element:
            debug_out("Seg Type: element\n");
            break;
        case Seg_code:
            debug_out("Seg Type: code\n");
            break;
        case Seg_data:
            debug_out("Seg Type: data\n");
            break;
        default:
            break;
        }
        BUFFER_FREE(segRAW);
        pointer += len;
    }
    

    BUFFER_FREE(wasmRAW);
    return r;
}