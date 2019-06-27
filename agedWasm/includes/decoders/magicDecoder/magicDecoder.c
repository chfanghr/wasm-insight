#include "magicDecoder.h"

#include <datas/types.h>
#include <datas/buffer.h>
#include <consts/nums.h>
#include <consts/codes.h>
#include <objects/magic/magicObject.h>

#include <platform/adaptLibs.h>

magicObject_t* decodeMagic(BUFFER* buf){
    ASSERT_A((BUFFER_SIZE(*buf)!= sizeof_magic+sizeof(i32)),"magic decode failed!\n");
    i32 i=0;
    for(i=0;i<sizeof_magic;i++){
        ASSERT_A((BUFFER_DATA(*buf)[i]!=magicCode[i]),"magic check failed!\n");
    }
    i32 version;
    BUFFER_READ(*buf,sizeof_magic,&version,sizeof(i32));
    magicObject_t* magicObject = malloc_a(sizeof(magicObject_t));
    ASSERT_A((!magicObject),"malloc failed!\n");
    magicObject->version = version;
    return magicObject;
}