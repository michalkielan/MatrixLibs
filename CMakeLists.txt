cmake_minimum_required (VERSION 2.6)


option(SANITIZER "Address Sanitizer" OFF)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_BENCH "Build Benchmark" ON)

set(CMAKE_CXX_STANDARD 11)
set(COMPILE_FLAGS "-ffast-math -Wall -flto")
set(GTEST_FLAGS "-lgtest -lpthread")
set(LINK_FLAGS "-flto")


if(SANITIZER)
  set(COMPILE_FLAGS "${COMPILE_FLAGS} -fsanitize=address")
endif()

if(BUILD_TESTS)
  set(LINK_FLAGS "${GTEST_FLAGS} ${LINK_FLAGS}")
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
