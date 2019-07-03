#include "magicDecoder.h"

#include <consts/nums.h>
#include <consts/codes.h>
#include <objects/magic/magicObject.h>
#include <buffer/buffer.h>
#include <stdlib.h>

magicObject_t* decodeMagic(array raw){
    buffer buf = buffer_init(sizeof(byte));
    ASSERT_A(array_size(raw)==sizeof_magic+sizeof(i32),"magic decode failed!\n");
    i32 i=0;
    for(i=0;i<sizeof_magic;i++){
        ASSERT_A((((byte*)array_get_data(raw))[i]==magicCode[i]),"magic check failed!\n");
    }
    BUFFER buff;
    BUFFER_INIT(buff,array_size(raw),0x00);
    BUFFER_FILL(buff,0,(byte*)array_get_data(raw),array_size(raw));
    i32 version;
    BUFFER_READ(buff,sizeof_magic,&version,sizeof(i32));
    magicObject_t* magicObject = malloc(sizeof(magicObject_t));
    ASSERT_A(magicObject,"malloc failed!\n");
    magicObject->version = version;
    return magicObject;
}