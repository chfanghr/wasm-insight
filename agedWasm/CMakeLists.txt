cmake_minimum_required(VERSION 2.8)
PROJECT(AGEDWASM)

INCLUDE_DIRECTORIES("include")
SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(adaptlibs
    include/platform/adaptLibs.c
)
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
)
ADD_LIBRARY(wasmObjects
    include/objects/wasmObjects.c
    include/consts/opcodes.h
)
ADD_LIBRARY(unity
    test/unity/unity.c
    test/unity/unity.h
    test/unity/unity_internals.h
)

ADD_EXECUTABLE(main main.c)

ADD_EXECUTABLE(tests
    test/buffer.h
    test/decoder.h
    test/readers.h
    test/vector.h
    test/tests.c
    test/fix_msvc.c)

TARGET_LINK_LIBRARIES(tests unity decoder wasmObjects readers adaptlibs)
TARGET_LINK_LIBRARIES(main adaptlibs)