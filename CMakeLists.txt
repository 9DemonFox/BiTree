cmake_minimum_required (VERSION 2.6)
project (testP)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb -std=c99")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall -std=c99")

set(LIB_LIST testP.c)

#引用源文件
ADD_EXECUTABLE(main ${LIB_LIST})