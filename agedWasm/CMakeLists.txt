cmake_minimum_required(VERSION 2.8)
PROJECT(AGEDWASM)

INCLUDE_DIRECTORIES("includes")
SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(adaptlibs
        includes/platform/adaptLibs.c)

ADD_LIBRARY(decoder
        includes/decoders/decoder.c
        includes/decoders/magicDecoder/magicDecoder.c
        includes/decoders/typesDecoder/typesDecoder.c
        includes/decoders/funcsDecoder/funcsDecoder.c
        includes/decoders/exportsDecoder/exportsDecoder.c
        includes/decoders/importsDecoder/importsDecoder.c
        )

ADD_LIBRARY(readers
        includes/datas/readers/uintReaders/uintReaders.c
        includes/datas/readers/byteReaders/byteReaders.c
        includes/datas/readers/stringReaders/stringReaders.c
        )

ADD_LIBRARY(wasmObjects
        includes/objects/wasmObjects.c
        includes/consts/opcodes.h
        )

ADD_LIBRARY(unity
        tests/unity/unity.c
        tests/unity/unity.h
        tests/unity/unity_internals.h
        )

ADD_LIBRARY(consts
        includes/consts/codes.h
        includes/consts/nums.h
        includes/consts/typecodes.h
        includes/consts/opcodes.h
        includes/consts/consts.c
        )

ADD_LIBRARY(datas
        includes/datas/buffer.h
        includes/datas/type.h
        includes/datas/str.h#TODO remove this file,use type.h instead
        includes/datas/vector.h
        includes/datas/datas.c)

ADD_EXECUTABLE(main main.c)

ADD_EXECUTABLE(tests tests/buffer.h tests/decoder.h tests/readers.h tests/vector.h tests/tests.c tests/fix_msvc.c)

TARGET_LINK_LIBRARIES(tests unity decoder wasmObjects readers adaptlibs)
TARGET_LINK_LIBRARIES(main adaptlibs)