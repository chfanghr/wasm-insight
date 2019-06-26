#include <stdio.h>
#include <types.h>
#include <buffer.h>

int main(){
    bt8 magic[] = {0x00,0x61,0x73,0x6d};
    bt8 version[] = {0x01,0x00,0x00,0x00};
    int i=0;
    BUFFER buf;
    BUFFER_INIT(buf,8,0x00);
    BUFFER_FILL(buf,0,magic,4);
    BUFFER_FILL(buf,4,version,4);
    for(i=0;i<BUFFER_SIZE(buf);i++) printf("%x ",BUFFER_DATA(buf)[i]);
    printf("\n");
    BUFFER_FREE(buf);
    return 0;
}