cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_STANDARD 14)
SET(COMPILE_FLAGS "-std=c++14 -std=gnu++14 -Wall -flto")
SET(LINK_FLAGS "-lgtest -lpthread -flto")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )
include_directories(${GTEST_INCLUDE_DIRS})

project (correctness)
find_package(Gtest)
add_executable(correctness ./tests/correctTests.cpp) 
target_link_libraries(correctness gtest pthread)

project (performance)
find_package(Gtest)
add_executable(performance ./tests/performanceTests.cpp) 
target_link_libraries(performance gtest pthread)

