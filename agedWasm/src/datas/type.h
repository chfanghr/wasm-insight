#ifndef _TYPE_H
#define _TYPE_H

#include <platform/adaptTypes.h>

typedef size_t_a siz_t;
typedef i32_a i32;
typedef i64_a i64;
typedef f32_a f32;
typedef f64_a f64;
typedef byte_a byte;
typedef u32_a u32;
typedef u64_a u64;
typedef byte chr8;
typedef u8_a u8;

#ifndef bool
#define bool byte
#define true  ((byte)1)
#define false ((byte)0)
#endif

typedef byte Seg_id;
typedef byte Val_type;
typedef u32 Idx_type;
typedef byte Kind_type;

#endif