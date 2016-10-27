cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_STANDARD 14)

set(COMPILE_FLAGS "-std=c++14 -std=gnu++14 -Wall -flto")
set(LINK_FLAGS "-lgtest -lpthread -flto")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )

include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
find_package(Gtest)

add_subdirectory(tst)

