project(test_all)

file(GLOB src
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${src} )

target_link_libraries(
  ${PROJECT_NAME} 
  gtest 
  pthread
)


add_test(tst ${PROJECT_NAME})
