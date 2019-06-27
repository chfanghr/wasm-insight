#include "exportsDecoder.h"

#include <datas/readers/uintReaders/uintReaders.h>
#include <datas/readers/byteReaders/byteReaders.h>
#include <platform/adaptLibs.h>

exportsObject_t* decodeExports(BUFFER* buf){
    siz_t offset = 0;
    u32 exportsCount = readUint32(buf,&offset);
    debug_out("exportsCount: %d\n",exportsCount);

    exportsObject_t* res = malloc_a(sizeof(exportsObject_t));
    VECTOR_INIT(res->exports);

    u32 i=0;
    if(exportsCount>0) for(i=0;i<exportsCount;i++){
        exportObject_t* obj = malloc_a(sizeof(exportObject_t));
        VECTOR_INIT(obj->name);
        
        u32 len = readUint32(buf,&offset);
        u32 j=0;
        if(len>0) for(j=0;j<len;j++){
            VECTOR_PUSH_BACK(obj->name,readByte8(buf,&offset));
        }

        obj->idx = readUint32(buf,&offset);
        debug_out("export idx: %d\n",obj->idx);
        VECTOR_PUSH_BACK(res->exports,obj);
    }

    return res;   
}