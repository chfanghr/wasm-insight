cmake_minimum_required(VERSION 2.8)
PROJECT(AGEDWASM)

INCLUDE_DIRECTORIES("src")
INCLUDE_DIRECTORIES("src/data")

SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(adaptlibs
        src/platform/adaptLibs.c)

ADD_LIBRARY(decoder
        src/decoders/decoder.c
        src/decoders/magicDecoder/magicDecoder.c
        src/decoders/typesDecoder/typesDecoder.c
        src/decoders/funcsDecoder/funcsDecoder.c
        src/decoders/exportsDecoder/exportsDecoder.c
        src/decoders/importsDecoder/importsDecoder.c
        )

ADD_LIBRARY(readers
        src/datas/readers/uintReaders/uintReaders.c
        src/datas/readers/byteReaders/byteReaders.c
        src/datas/readers/stringReaders/stringReaders.c
        src/datas/readers/uintReaders/u8.h src/datas/readers/uintReaders/u8.c src/datas/readers/uintReaders/reader.c src/datas/readers/uintReaders/reader.h)

ADD_LIBRARY(wasmObjects
        src/objects/wasmObjects.c
        src/consts/opcodes.h
        )

ADD_LIBRARY(unity
        test/unity/unity.c
        test/unity/unity.h
        test/unity/unity_internals.h
        )

ADD_LIBRARY(consts
        src/consts/codes.h
        src/consts/nums.h
        src/consts/typecodes.h
        src/consts/opcodes.h
        src/consts/consts.c
        )

ADD_LIBRARY(datas
        src/datas/types.h
        src/datas/datas.c)

ADD_EXECUTABLE(main main.c)

ADD_EXECUTABLE(tests test/buffer.h test/decoder.h test/readers.h test/vector.h test/tests.c test/fix_msvc.c test/array.h)

ADD_SUBDIRECTORY(src/data)

TARGET_LINK_LIBRARIES(tests unity decoder wasmObjects readers adaptlibs data datas)
TARGET_LINK_LIBRARIES(main adaptlibs)