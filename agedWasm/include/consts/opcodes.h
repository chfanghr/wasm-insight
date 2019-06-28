//
// Created by 31838 on 6/27/2019.
//

#ifndef AGEDWASM_OPCODES_H
#define AGEDWASM_OPCODES_H

#include <datas/str.h>

typedef byte op_code;

const op_code Op_i32 = 0x7f;
const op_code Op_i64 = 0x7e;
const op_code Op_f32 = 0x7d;
const op_code Op_f64 = 0x7c;
const op_code Op_anyfunc = 0x70;
const op_code Op_func = 0x60;
const op_code Op_empty = 0x40;

const op_code Op_unreachable = 0x00;
const op_code Op_nop = 0x01;
const op_code Op_block = 0x02;
const op_code Op_loop = 0x03;
const op_code Op_if = 0x04;
const op_code Op_else = 0x05;
const op_code Op_end = 0x0b;
const op_code Op_br = 0x0c;
const op_code Op_br_if = 0x0d;
const op_code Op_br_table = 0x0e;
const op_code Op_return = 0x0f;

const op_code Op_call = 0x10;
const op_code Op_call_indirect = 0x11;


const op_code Op_drop = 0x1a;
const op_code Op_select = 0x1b;


const op_code Op_get_local = 0x20;
const op_code Op_set_local = 0x21;
const op_code Op_tee_local = 0x22;
const op_code Op_get_global = 0x23;
const op_code Op_set_global = 0x24;


const op_code Op_i32_load = 0x28;
const op_code Op_i64_load = 0x29;
const op_code Op_f32_load = 0x2a;
const op_code Op_f64_load = 0x2b;
const op_code Op_i32_load8_s = 0x2c;
const op_code Op_i32_load8_u = 0x2d;
const op_code Op_i32_load16_s = 0x2e;
const op_code Op_i32_load16_u = 0x2f;
const op_code Op_i64_load8_s = 0x30;
const op_code Op_i64_load8_u = 0x31;
const op_code Op_i64_load16_s = 0x32;
const op_code Op_i64_load16_u = 0x33;
const op_code Op_i64_load32_s = 0x34;
const op_code Op_i64_load32_u = 0x35;
const op_code Op_i32_store = 0x36;
const op_code Op_i64_store = 0x37;
const op_code Op_f32_store = 0x38;
const op_code Op_f64_store = 0x39;
const op_code Op_i32_store8 = 0x3a;
const op_code Op_i32_store16 = 0x3b;
const op_code Op_i64_store8 = 0x3c;
const op_code Op_i64_store16 = 0x3d;
const op_code Op_i64_store32 = 0x3e;
const op_code Op_current_memory = 0x3f;
const op_code Op_grow_memory = 0x40;

const op_code Op_i32_const = 0x41;
const op_code Op_i64_const = 0x42;
const op_code Op_f32_const = 0x43;
const op_code Op_f64_const = 0x44;

const op_code Op_i32_eqz = 0x45;
const op_code Op_i32_eq = 0x46;
const op_code Op_i32_ne = 0x47;
const op_code Op_i32_lt_s = 0x48;
const op_code Op_i32_lt_u = 0x49;
const op_code Op_i32_gt_s = 0x4a;
const op_code Op_i32_gt_u = 0x4b;
const op_code Op_i32_le_s = 0x4c;
const op_code Op_i32_le_u = 0x4d;
const op_code Op_i32_ge_s = 0x4e;
const op_code Op_i32_ge_u = 0x4f;
const op_code Op_i64_eqz = 0x50;
const op_code Op_i64_eq = 0x51;
const op_code Op_i64_ne = 0x52;
const op_code Op_i64_lt_s = 0x53;
const op_code Op_i64_lt_u = 0x54;
const op_code Op_i64_gt_s = 0x55;
const op_code Op_i64_gt_u = 0x56;
const op_code Op_i64_le_s = 0x57;
const op_code Op_i64_le_u = 0x58;
const op_code Op_i64_ge_s = 0x59;
const op_code Op_i64_ge_u = 0x5a;
const op_code Op_f32_eq = 0x5b;
const op_code Op_f32_ne = 0x5c;
const op_code Op_f32_lt = 0x5d;
const op_code Op_f32_gt = 0x5e;
const op_code Op_f32_le = 0x5f;
const op_code Op_f32_ge = 0x60;
const op_code Op_f64_eq = 0x61;
const op_code Op_f64_ne = 0x62;
const op_code Op_f64_lt = 0x63;
const op_code Op_f64_gt = 0x64;
const op_code Op_f64_le = 0x65;
const op_code Op_f64_ge = 0x66;

const op_code Op_i32_clz = 0x67;
const op_code Op_i32_ctz = 0x68;
const op_code Op_i32_popcnt = 0x69;
const op_code Op_i32_add = 0x6a;
const op_code Op_i32_sub = 0x6b;
const op_code Op_i32_mul = 0x6c;
const op_code Op_i32_div_s = 0x6d;
const op_code Op_i32_div_u = 0x6e;
const op_code Op_i32_rem_s = 0x6f;
const op_code Op_i32_rem_u = 0x70;
const op_code Op_i32_and = 0x71;
const op_code Op_i32_or = 0x72;
const op_code Op_i32_xor = 0x73;
const op_code Op_i32_shl = 0x74;
const op_code Op_i32_shr_s = 0x75;
const op_code Op_i32_shr_u = 0x76;
const op_code Op_i32_rotl = 0x77;
const op_code Op_i32_rotr = 0x78;
const op_code Op_i64_clz = 0x79;
const op_code Op_i64_ctz = 0x7a;
const op_code Op_i64_popcnt = 0x7b;
const op_code Op_i64_add = 0x7c;
const op_code Op_i64_sub = 0x7d;
const op_code Op_i64_mul = 0x7e;
const op_code Op_i64_div_s = 0x7f;
const op_code Op_i64_div_u = 0x80;
const op_code Op_i64_rem_s = 0x81;
const op_code Op_i64_rem_u = 0x82;
const op_code Op_i64_and = 0x83;
const op_code Op_i64_or = 0x84;
const op_code Op_i64_xor = 0x85;
const op_code Op_i64_shl = 0x86;
const op_code Op_i64_shr_s = 0x87;
const op_code Op_i64_shr_u = 0x88;
const op_code Op_i64_rotl = 0x89;
const op_code Op_i64_rotr = 0x8a;
const op_code Op_f32_abs = 0x8b;
const op_code Op_f32_neg = 0x8c;
const op_code Op_f32_ceil = 0x8d;
const op_code Op_f32_floor = 0x8e;
const op_code Op_f32_trunc = 0x8f;
const op_code Op_f32_nearest = 0x90;
const op_code Op_f32_sqrt = 0x91;
const op_code Op_f32_add = 0x92;
const op_code Op_f32_sub = 0x93;
const op_code Op_f32_mul = 0x94;
const op_code Op_f32_div = 0x95;
const op_code Op_f32_min = 0x96;
const op_code Op_f32_max = 0x97;
const op_code Op_f32_copysign = 0x98;
const op_code Op_f64_abs = 0x99;
const op_code Op_f64_neg = 0x9a;
const op_code Op_f64_ceil = 0x9b;
const op_code Op_f64_floor = 0x9c;
const op_code Op_f64_trunc = 0x9d;
const op_code Op_f64_nearest = 0x9e;
const op_code Op_f64_sqrt = 0x9f;
const op_code Op_f64_add = 0xa0;
const op_code Op_f64_sub = 0xa1;
const op_code Op_f64_mul = 0xa2;
const op_code Op_f64_div = 0xa3;
const op_code Op_f64_min = 0xa4;
const op_code Op_f64_max = 0xa5;
const op_code Op_f64_copysign = 0xa6;

const op_code Op_i32_wrap_i64 = 0xa7;
const op_code Op_i32_trunc_s_f32 = 0xa8;
const op_code Op_i32_trunc_u_f32 = 0xa9;
const op_code Op_i32_trunc_s_f64 = 0xaa;
const op_code Op_i32_trunc_u_f64 = 0xab;
const op_code Op_i64_extend_s_i32 = 0xac;
const op_code Op_i64_extend_u_i32 = 0xad;
const op_code Op_i64_trunc_s_f32 = 0xae;
const op_code Op_i64_trunc_u_f32 = 0xaf;
const op_code Op_i64_trunc_s_f64 = 0xb0;
const op_code Op_i64_trunc_u_f64 = 0xb1;
const op_code Op_f32_convert_s_i32 = 0xb2;
const op_code Op_f32_convert_u_i32 = 0xb3;
const op_code Op_f32_convert_s_i64 = 0xb4;
const op_code Op_f32_convert_u_i64 = 0xb5;
const op_code Op_f32_demote_f64 = 0xb6;
const op_code Op_f64_convert_s_i32 = 0xb7;
const op_code Op_f64_convert_u_i32 = 0xb8;
const op_code Op_f64_convert_s_i64 = 0xb9;
const op_code Op_f64_convert_u_i64 = 0xba;
const op_code Op_f64_promote_f32 = 0xbb;

const op_code Op_i32_reinterpret_f32 = 0xbc;
const op_code Op_i64_reinterpret_f64 = 0xbd;
const op_code Op_f32_reinterpret_i32 = 0xbe;
const op_code Op_f64_reinterpret_i64 = 0xbf;


#endif //AGEDWASM_OPCODES_H