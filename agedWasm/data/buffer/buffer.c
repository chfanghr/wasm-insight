//
// Created by 31838 on 7/3/2019.
//

#include "buffer.h"

#include <errno.h>

#define initial_buffer_size 20

struct internal_buffer {
    size_t bytes_per_item;
    int read_pos, write_pos;
    array backend;
};

buffer buffer_init(size_t data_size) {
    struct internal_buffer *init;
    if (data_size == 0)return NULL;
    init = (struct internal_buffer *) malloc(sizeof(struct internal_buffer));
    init->backend = array_init(initial_buffer_size, data_size);
    init->read_pos = init->write_pos = 0;
    init->bytes_per_item = data_size;
    return (buffer) init;
}

int buffer_size(buffer me) {
    return array_size(me->backend);
}

int buffer_read(array *data, buffer me, int n_element) {

}

int buffer_write(buffer me, array data, int n_element) {}

int buffer_read_available(buffer me) {
    if (me->write_pos >= me->read_pos)return me->write_pos - me->read_pos;
    return buffer_size(me) - me->read_pos + me->write_pos;
}

buffer buffer_destroy(buffer me) {
    array_destroy(me->backend);
    free(me);
    return NULL;
}

int buffer_next_n_pos(buffer me, int pos, int n) {
    if (pos >= array_size(me->backend) || pos < 0)return -EINVAL;
    return pos + n >= array_size(me->backend) ? pos + n - array_size(me->backend) : pos + n;
}

int buffer_grow(buffer me) {
    
}

int buffer_shrink(buffer me) {

}
