#include "magicDecoder.h"

#include <consts/nums.h>
#include <consts/codes.h>
#include <objects/magic/magicObject.h>
#include <buffer/buffer.h>
#include <stdlib.h>

magicObject_t* decodeMagic(array raw){
    buffer buf = buffer_from_array(raw);
    ASSERT_A(buffer_size(buf)==sizeof_magic+sizeof(i32),"magic decode failed!\n");
    i32 i=0;
    for(i=0;i<sizeof_magic;i++){   
        array r = array_init(1,sizeof(byte));
        buffer_read(&r,buf,1);
        debug_out("%d\n",array_size(r));
        ASSERT_A( (( (byte*)array_get_data(r))[0]==magicCode[i]),
        "magic check failed!\n");
        array_destroy(r);
    }
    
        debug_out("hello\n");

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