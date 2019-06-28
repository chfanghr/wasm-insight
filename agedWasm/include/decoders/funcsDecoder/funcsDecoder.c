#include "funcsDecoder.h"

#include <datas/readers/readers.h>
#include <platform/adaptLibs.h>

funcsObject_t* decodeFuncs(BUFFER* buf){
    siz_t offset = 0;
    u32 funcsCount = readUint32(buf,&offset);
    debug_out("funcsCount: %d\n",funcsCount);

    funcsObject_t* res = malloc_a(sizeof(funcsObject_t));
    VECTOR_INIT(res->funcs);

    u32 i = 0;
    if(funcsCount>0) for(i=0;i<funcsCount;i++){
        Idx_type idx = readUint32(buf,&offset);
        debug_out("funcs %d -> types %d\n",i,idx);
        VECTOR_PUSH_BACK(res->funcs,idx);
    }

    return res;
}