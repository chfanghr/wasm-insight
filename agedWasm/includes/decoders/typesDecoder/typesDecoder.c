#include "typesDecoder.h"

#include <datas/readers/uintReaders/uintReaders.h>
#include <datas/readers/byteReaders/byteReaders.h>
#include <platform/adaptLibs.h>

typesObject_t* decodeTypes(BUFFER* buf){
    siz_t offset = 0;
    u32 typesCount = readUint32(buf,&offset);
    debug_out("typesCount: %d\n",typesCount);

    u32 i = 0;
    for(i=0;i<typesCount;i++){
        ASSERT_A((readByte8(buf,&offset)==0x60),"decode type failed!\n");
        break;
    }
}