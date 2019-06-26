package fuckWasm

import (
	"encoding/binary"
	"errors"
	"io"
)

var order = binary.LittleEndian

type (
	varuint32 uint32
	varuint7 uint32
	varuint1 uint32

	varint64 int64
	varint32 int32
	varint7 int32
)

func (v *varuint32) read(r io.Reader) (int, error) {
	vv, n, err := uvarint(r)
	if err != nil {
		return n, err
	}
	*v = varuint32(vv)
	return n, nil
}

func (v *varuint7) read(r io.Reader) (int, error) {
	vv, n, err := uvarint(r)
	if err != nil {
		return n, err
	}
	*v = varuint7(vv)
	return n, nil
}

func uvarint(r io.Reader) (uint32, int, error) {
	var x uint32
	var s uint
	var buf = make([]byte, 1)
	for i := 0; ; i++ {
		_, err := r.Read(buf)
		if err != nil {
			return 0, i, err
		}
		b := buf[0]
		if b < 0x80 {
			if i > 9 || i == 9 && b > 1 {
				return 0, i, errors.New("wasm: overflow")
			}
			return x | uint32(b)<<s, i, nil
		}
		x |= uint32(b&0x7f) << s
		s += 7
	}
	panic("unreachable")
}

func varint(r io.Reader) (int32, int, error) {
	uv, n, err := uvarint(r)
	v := int32(uv >> 1)
	if uv&1 != 0 {
		v = ^v
	}
	return v, n, err
}

type ValueType int32

type BlockType varint7
type ElemType varint7

type FuncType struct {
	form    uint32
	params  []ValueType
	results []ValueType
}

type GlobalType struct {
	ContentType ValueType
	Mutability  varuint1
}

type TableType struct {
	ElemType ElemType
	Limits   ResizableLimits
}

type MemoryType struct {
	Limits ResizableLimits
}

type ExternalKind byte

const (
	FunctionKind ExternalKind = 0
	TableKind                 = 1
	MemoryKind                = 2
	GlobalKind                = 3
)

type ResizableLimits struct {
	Flags   uint32
	Initial uint32
	Maximum uint32
}

type InitExpr struct {
	Expr []byte
	End  byte
}
