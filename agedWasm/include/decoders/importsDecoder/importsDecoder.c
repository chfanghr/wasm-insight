#include "importsDecoder.h"

#include <datas/readers/readers.h>
#include <platform/adaptLibs.h>

importsObject_t* decodeImports(BUFFER* buf){
    siz_t offset = 0;
    u32 importsCount = readUint32(buf,&offset);
    debug_out("importsCount: %d\n",importsCount);

    importsObject_t* res = malloc_a(sizeof(importsObject_t));
    VECTOR_INIT(res->imports);

    u32 i=0;
    if(importsCount>0) for(i=0;i<importsCount;i++){
        importObject_t* obj = malloc_a(sizeof(importObject_t));
        obj->module = readString(buf,&offset);
        obj->field = readString(buf,&offset);
        obj->kind = readByte8(buf,&offset);
        debug_out("import module: %s field: %s kind: %x\n",obj->module,obj->field,obj->kind);
        VECTOR_PUSH_BACK(res->imports,obj);
        break;
    }

    return res;
}