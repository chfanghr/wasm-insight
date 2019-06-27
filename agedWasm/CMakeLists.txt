cmake_minimum_required (VERSION 2.8)
PROJECT (AGEDWASM)

INCLUDE_DIRECTORIES("includes")
SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(adaptlibs includes/platform/adaptLibs.c)
ADD_LIBRARY(decoder includes/decoders/decoder.c includes/decoders/magicDecoder/magicDecoder.c includes/decoders/typesDecoder/typesDecoder.c)
ADD_LIBRARY(readers includes/datas/readers/uintReaders/uintReaders.c includes/datas/readers/byteReaders/byteReaders.c)
ADD_LIBRARY(wasmObjects includes/objects/wasmObjects.c includes/consts/opcodes.h)
ADD_LIBRARY(unity tests/unity/unity.c tests/unity/unity.h tests/unity/unity_internals.h)

ADD_EXECUTABLE(main main.c)

ADD_EXECUTABLE(tests tests/buffer.h tests/decoder.h tests/readers.h tests/vector.h tests/tests.c)

TARGET_LINK_LIBRARIES(tests unity decoder wasmObjects readers adaptlibs)
TARGET_LINK_LIBRARIES(main adaptlibs)