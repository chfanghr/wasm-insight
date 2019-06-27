#include "typesDecoder.h"

#include <datas/readers/uintReaders/uintReaders.h>
#include <datas/readers/byteReaders/byteReaders.h>
#include <platform/adaptLibs.h>
#include <consts/typecodes.h>
#include <datas/vector.h>

typesObject_t* decodeTypes(BUFFER* buf){
    siz_t offset = 0;
    u32 typesCount = readUint32(buf,&offset);
    debug_out("typesCount: %d\n",typesCount);

    typesObject_t* res = malloc_a(sizeof(typesObject_t));
    VECTOR_INIT(res->types);

    u32 i = 0;
    if(typesCount>0) for(i=0;i<typesCount;i++){
        ASSERT_A((readByte8(buf,&offset)==Type_func),"decode type failed!\n");
        debug_out("typeIndex: %d\n",i);

        typeObject_t* obj = malloc_a(sizeof(typeObject_t));
        VECTOR_INIT(obj->param);
        VECTOR_INIT(obj->result);

        u32 paramCount = readUint32(buf,&offset);
        u32 j = 0;
        for(j=0;j<paramCount;j++){
            type_code type = readByte8(buf,&offset);
            debug_out("%x ",type);
            VECTOR_PUSH_BACK(obj->param,type);
        }
        debug_out("\n");
        u32 resultCount = readByte8(buf,&offset);
        if(resultCount!=0) for(j=0;j<resultCount;j++){
            type_code type = readByte8(buf,&offset);
            debug_out("%x ",type);
            VECTOR_PUSH_BACK(obj->result,type);
        }
        debug_out("\n");
        VECTOR_PUSH_BACK(res->types,obj);
    }

    return res;
}