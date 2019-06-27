cmake_minimum_required (VERSION 2.8)
PROJECT (AGEDWASM)

INCLUDE_DIRECTORIES("includes")
SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(adaptlibs includes/platform/adaptLibs.c)
ADD_LIBRARY(decoder includes/decoders/decoder.c includes/decoders/magicDecoder/magicDecoder.c)
ADD_LIBRARY(readers includes/datas/readers/uintReaders/uintReaders.c includes/datas/readers/byteReaders/byteReaders.c)
ADD_LIBRARY(wasmObjects includes/objects/wasmObjects.c includes/consts/opcodes.h)

ADD_EXECUTABLE(main main.c)
ADD_EXECUTABLE(bufferT tests/bufferTest.c)
ADD_EXECUTABLE(vectorT tests/vectorTest.c)
ADD_EXECUTABLE(decoderT tests/decoderTest.c)
ADD_EXECUTABLE(readersT tests/readersTest.c)

TARGET_LINK_LIBRARIES(decoderT decoder wasmObjects readers adaptlibs)
TARGET_LINK_LIBRARIES(readersT readers adaptlibs)
TARGET_LINK_LIBRARIES(bufferT adaptlibs)
TARGET_LINK_LIBRARIES(vectorT adaptlibs)
TARGET_LINK_LIBRARIES(main adaptlibs)