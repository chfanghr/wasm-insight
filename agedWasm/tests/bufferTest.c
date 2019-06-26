#include <stdio.h>
#include <buffer.h>

int main(){
    BUFFER buf;
    BUFFER ori;

    BUFFER_INIT(buf,4,0x5f);
    BUFFER_INIT(ori,8,0x5f);

    BUFFER_DATA(ori)[7] = '\0';
    BUFFER_DATA(ori)[4] = 0x61;
    BUFFER_DATA(ori)[5] = 0x73;
    BUFFER_DATA(ori)[6] = 0x6d;

    BUFFER_SLCE(buf,1,ori,5,3);
    printf("%s\n",BUFFER_DATA(buf));

    BUFFER_FILL(buf,1,"eagic",2);
    printf("%s\n",BUFFER_DATA(buf));

    BUFFER_FREE(buf);
    BUFFER_FREE(ori);
    return 0;
}