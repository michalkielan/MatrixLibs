cmake_minimum_required (VERSION 2.6)

set(COMPILE_FLAGS "-std=c++14 -std=gnu++14 -ffast-math -Wall -flto")

option(SANITIZER "Address Sanitizer" OFF)

if(SANITIZER)
  set(COMPILE_FLAGS "${COMPILE_FLAGS} -fsanitize=address")
endif()

set(GTEST_FLAGS "-lgtest -lpthread")
set(LINK_FLAGS "${GTEST_FLAGS} -flto")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS} ${GTEST_FLAGS}" )

include_directories(matrix)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
find_package(Gtest)

add_subdirectory(tst)
add_subdirectory(bench)

