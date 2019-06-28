#include "stringReaders.h"

#include <datas/readers/byteReaders/byteReaders.h>
#include <datas/readers/uintReaders/uintReaders.h>
#include <platform/adaptLibs.h>

str_t* readString(BUFFER* buf, siz_t* offset){
    ASSERT_A(!(BUFFER_SIZE(*buf)<1),"read string failed!\n");
    str_t* res = malloc_a(sizeof(str_t));
    VECTOR_INIT(*res);

    u32 len = readUint32(buf,offset);
    u32 i=0;
    if(len>0) for(i=0;i<len;i++) VECTOR_PUSH_BACK(*res, readByte8(buf,offset));

    return res; 
}