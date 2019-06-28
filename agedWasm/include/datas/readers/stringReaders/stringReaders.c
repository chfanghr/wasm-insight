#include "stringReaders.h"

#include <datas/readers/byteReaders/byteReaders.h>
#include <datas/readers/uintReaders/uintReaders.h>
#include <platform/adaptLibs.h>

chr8* readString(BUFFER* buf, siz_t* offset){
    ASSERT_A(!(BUFFER_SIZE(*buf)<1),"read string failed!\n");

    u32 len = readUint32(buf,offset);
    ASSERT_A((BUFFER_SIZE(*buf)-(*offset)>=len),"read string overflow!\n");
    chr8* res = malloc_a(len+1);

    u32 i=0;
    if(len>0) for(i=0;i<len;i++) res[i] = readByte8(buf,offset);
    res[len]='\0';

    return res; 
}