package main

import (
	"flag"
	"fmt"
	wasm "github.com/chfanghr/wasm-insight/fuckWasm"
	"log"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("wasm>> ")

	flag.Parse()

	fname := flag.Arg(0)
	mod, err := wasm.Open(fname)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("module header: %v\n", mod.Header)
	fmt.Printf("#sections: %d\n", len(mod.Sections))
	for _, section := range mod.Sections {
		fmt.Printf("section: %2d (%T)\n", section.ID(), section)
	}
}
