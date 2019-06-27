cmake_minimum_required (VERSION 2.8)
PROJECT (AGEDWASM)

INCLUDE_DIRECTORIES("includes")
SET(EXECUTABLE_OUTPUT_PATH ./bin/)
SET(LIBRARY_OUTPUT_PATH ./lib/)

ADD_LIBRARY(decoder includes/decoders/decoder.c includes/decoders/magicDecoder/magicDecoder.c)
ADD_LIBRARY(wasmObjects includes/objects/wasmObjects.c)

ADD_EXECUTABLE(main main.c)
ADD_EXECUTABLE(bufferT tests/bufferTest.c)
ADD_EXECUTABLE(vectorT tests/vectorTest.c)
ADD_EXECUTABLE(decoderT tests/decoderTest.c)

TARGET_LINK_LIBRARIES(decoderT decoder wasmObjects)