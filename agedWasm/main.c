#include <stdio.h>

#include <datas/types.h>
#include <datas/buffer.h>
#include <datas/vector.h>
#include <addExample.h>

int main(){
    byte magic[] = {0x00,0x61,0x73,0x6d};
    byte version[] = {0x01,0x00,0x00,0x00};
    int i=0;
    
    BUFFER buf;
    BUFFER_INIT(buf,sizeof_addExample,0x00);
    BUFFER_FILL(buf,0,addExample,sizeof_addExample);

    for(i=0;i<BUFFER_SIZE(buf);i++) printf("%#04x ",BUFFER_DATA(buf)[i]);
    printf("\n");
    
    BUFFER_FREE(buf);
    return 0;
}