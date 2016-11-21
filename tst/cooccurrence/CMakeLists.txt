#
# @file CMakeLists.txt
# 
# @date Nov 21, 2016
# 
# @author JaroslawWiosna
# 
# @par Licence
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#


project(test-cooccurrence)

file(GLOB src
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${src} )

target_link_libraries(
  ${PROJECT_NAME} 
  ${LINK_FLAGS}
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
