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


project(bench-inv)

file(GLOB src
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${src} )

target_link_libraries(
  ${PROJECT_NAME} 
  benchmark
  pthread
)