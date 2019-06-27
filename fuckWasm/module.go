package fuckWasm

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

type Module struct {
	Header   ModuleHeader
	Sections []Section
}

func Open(name string) (Module, error) {
	f, err := os.Open(name)
	if err != nil {
		return Module{}, err
	}
	defer f.Close()

	dec := decoder{r: f}
	return dec.readModule()
}

type ModuleHeader struct {
	Magic   [4]byte
	Version uint32
}

func (hdr ModuleHeader) String() string {
	return fmt.Sprintf("ModuleHeader{Magic=%q Version=0x%x}", hdr.Magic, hdr.Version)
}

type Section interface {
	ID() SectionID
}

type SectionID byte

const (
	UnknownID  SectionID = 0
	TypeID               = 1
	ImportID             = 2
	FunctionID           = 3
	TableID              = 4
	MemoryID             = 5
	GlobalID             = 6
	ExportID             = 7
	StartID              = 8
	ElementID            = 9
	CodeID               = 10
	DataID               = 11
)

func (TypeSection) ID() SectionID     { return TypeID }
func (ImportSection) ID() SectionID   { return ImportID }
func (FunctionSection) ID() SectionID { return FunctionID }
func (TableSection) ID() SectionID    { return TableID }
func (MemorySection) ID() SectionID   { return MemoryID }
func (GlobalSection) ID() SectionID   { return GlobalID }
func (ExportSection) ID() SectionID   { return ExportID }
func (StartSection) ID() SectionID    { return StartID }
func (ElementSection) ID() SectionID  { return ElementID }
func (CodeSection) ID() SectionID     { return CodeID }
func (DataSection) ID() SectionID     { return DataID }
func (NameSection) ID() SectionID     { return UnknownID }

type TypeSection struct {
	types []FuncType
}

func (s *TypeSection) readWasm(r io.Reader) error {
	var err error
	return err
}

type ImportSection struct {
	imports []ImportEntry
}

type ImportEntry struct {
	module string
	field  string
	kind   ExternalKind

	typ interface{}
}

type FunctionSection struct {
	types []uint32
}

type TableSection struct {
	tables []TableType
}

type MemorySection struct {
	memories []MemoryType
}

type GlobalSection struct {
	globals []GlobalVariable
}

type GlobalVariable struct {
	Type GlobalType
	Init InitExpr
}

type ExportSection struct {
	exports []ExportEntry
}

type ExportEntry struct {
	field string
	kind  ExternalKind
	index uint32
}

type StartSection struct {
	Index uint32
}

type ElementSection struct {
	elements []ElemSegment
}

type ElemSegment struct {
	Index  uint32
	Offset InitExpr
	Elems  []uint32
}

type CodeSection struct {
	Bodies []FunctionBody
}

type DataSection struct {
	segments []DataSegment
}

type DataSegment struct {
	Index  uint32
	Offset InitExpr
	Data   []byte
}

type NameSection struct {
	name  string
	funcs []FunctionNames
}

type FunctionNames struct {
	name   string
	locals []LocalName
}

type LocalName struct {
	name string
}

type FunctionBody struct {
	BodySize   uint32
	LocalCount varuint32
	Locals     []LocalEntry
	Code       Code
}

type Param interface{}

type Operation struct {
	Instruction Opcode
	Params      []Param
}

type Code struct {
	Code       []byte
	End        byte
	Operations []Operation
}

func (o Opcode) parse(r io.Reader) ([]Param, error) {
	switch o {
	case Op_i32_const:
		p, _, err := varint(r)
		return []Param{p}, err
	default:
		return nil, nil
	}
}

func (c *Code) parse() error {
	buf := bytes.NewBuffer(c.Code)

	for {
		op, err := buf.ReadByte()
		if err != nil {
			if err == io.EOF {
				return nil
			}
			return err
		}

		ps, err := Opcode(op).parse(buf)
		if err != nil {
			return err
		}
		c.Operations = append(c.Operations, Operation{Opcode(op), ps})
	}
}

type LocalEntry struct {
	Count uint32
	Type  ValueType
}
