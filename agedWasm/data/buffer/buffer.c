//
// Created by 31838 on 7/3/2019.
//

#include "buffer.h"

struct internal_buffer {
    int read_pos, write_pos;
    array backend;
};

buffer buffer_init(int buffer_size, size_t data_size) {}

int buffer_size(buffer me) {}

int buffer_read(array *data, buffer me) {}

int buffer_write(buffer me, array *data) {}

int buffer_read_available(buffer me) {}

buffer buffer_destroy(buffer me) {}