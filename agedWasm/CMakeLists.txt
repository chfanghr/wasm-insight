cmake_minimum_required(VERSION 2.8)
PROJECT(AGEDWASM)

INCLUDE_DIRECTORIES("include")
INCLUDE_DIRECTORIES("data")
SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(adaptlibs
        include/platform/adaptLibs.c)

ADD_LIBRARY(decoder
        include/decoders/decoder.c
        include/decoders/magicDecoder/magicDecoder.c
        include/decoders/typesDecoder/typesDecoder.c
        include/decoders/funcsDecoder/funcsDecoder.c
        include/decoders/exportsDecoder/exportsDecoder.c
        include/decoders/importsDecoder/importsDecoder.c
        )

ADD_LIBRARY(readers
        include/datas/readers/uintReaders/uintReaders.c
        include/datas/readers/byteReaders/byteReaders.c
        include/datas/readers/stringReaders/stringReaders.c
        include/datas/readers/uintReaders/u8.h include/datas/readers/uintReaders/u8.c include/datas/readers/uintReaders/reader.c include/datas/readers/uintReaders/reader.h)

ADD_LIBRARY(wasmObjects
        include/objects/wasmObjects.c
        include/consts/opcodes.h
        )

ADD_LIBRARY(unity
        test/unity/unity.c
        test/unity/unity.h
        test/unity/unity_internals.h
        )

ADD_LIBRARY(consts
        include/consts/codes.h
        include/consts/nums.h
        include/consts/typecodes.h
        include/consts/opcodes.h
        include/consts/consts.c
        )

ADD_LIBRARY(datas
        include/datas/types.h
        include/datas/datas.c)

ADD_EXECUTABLE(main main.c)

ADD_EXECUTABLE(tests test/buffer.h test/decoder.h test/readers.h test/vector.h test/tests.c test/fix_msvc.c test/array.h)

ADD_SUBDIRECTORY(data)

TARGET_LINK_LIBRARIES(tests unity decoder wasmObjects readers adaptlibs data datas)
TARGET_LINK_LIBRARIES(main adaptlibs)