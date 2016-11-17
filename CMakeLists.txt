cmake_minimum_required (VERSION 2.6)


option(SANITIZER "Address Sanitizer" OFF)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_BENCH "Build Benchmark" ON)
option(ENABLE_LTO "Enable LTO" OFF)

set(CMAKE_CXX_STANDARD 11)
set(COMPILE_FLAGS "-ffast-math -Wall -flto")
set(GTEST_FLAGS "-lgtest")
set(LINK_FLAGS "-lpthread")

if(BUILD_TESTS)
  set(LINK_FLAGS "${LINK_FLAGS} ${GTEST_FLAGS}")
endif()


if(SANITIZER)
  set(COMPILE_FLAGS "${COMPILE_FLAGS} -fsanitize=address")
endif()

if(ENABLE_LTO)
  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(LTO_FLAG "${COMPILE_FLAGS} -flto=thin")
  else()
   set(LTO_FLAG "${COMPILE_FLAGS} -flto")
  endif()
  set(COMPILE_FLAGS "${COMPILE_FLAGS} ${LTO_FLAG}")
  set(LINK_FLAGS "${LINK_FLAGS} ${LTO_FLAG}")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )

include_directories(matrix)

include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
find_package(Gtest)

if(BUILD_TESTS)
  add_subdirectory(tst)
endif()

if(BUILD_BENCH)
  add_subdirectory(bench)
endif()
