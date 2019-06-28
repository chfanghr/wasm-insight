#include "exportsDecoder.h"

#include <datas/readers/readers.h>
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
        obj->name = readString(buf,&offset);
        obj->type = readByte8(buf,&offset);
        obj->idx = readUint32(buf,&offset);
        debug_out("export name: %s idx: %d\n",obj->name,obj->idx);
        VECTOR_PUSH_BACK(res->exports,obj);
    }

    return res;   
}