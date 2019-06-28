#include <datas/str.h>
#include <platform/adaptLibs.h>

void test_buffer() {
    BUFFER buf;
    BUFFER ori;
    byte magic[] = {0x5f,0x61,0x73,0x6d};

    BUFFER_INIT(buf,4,0x5f);
    BUFFER_INIT(ori,8,0x5f);

    BUFFER_FILL(ori,4,magic,4);

    BUFFER_SLCE(buf,1,ori,5,3);
    debug_out("%s\n",BUFFER_DATA(buf));

    BUFFER_FILL(buf,1,"eagic",2);
    debug_out("%s\n",BUFFER_DATA(buf));

    BUFFER_FILL(buf,0,magic,4);
    i32 read;
    BUFFER_READ(buf,0,&read,sizeof(i32));
    debug_out("%d\n", read);

    BUFFER_FREE(buf);
    BUFFER_FREE(ori);
}