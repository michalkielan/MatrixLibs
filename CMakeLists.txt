#
# @file CMakeLists.txt
# 
# @date Oct 26, 2016
# 
# @author Michal Kielan
# 
# @par Licence
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#


cmake_minimum_required (VERSION 2.6)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
else()
  message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support")
endif()

option(SANITIZER "Address Sanitizer" OFF)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_BENCH "Build Benchmark" ON)
option(ENABLE_LTO "Enable LTO" OFF)

set(CMAKE_CXX_STANDARD 11)
set(COMPILE_FLAGS "-Wall -Wno-missing-braces")
set(GTEST_FLAGS "-lgtest")
set(LINK_FLAGS "-lpthread")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(COMPILE_FLAGS  "${COMPILE_FLAGS} -stdlib=libstdc++")
endif()

if(BUILD_TESTS)
  set(LINK_FLAGS "${GTEST_FLAGS} ${LINK_FLAGS}")
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
