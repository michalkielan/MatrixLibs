project(test-zeros)

file(GLOB src
  "*.cpp"
)

add_executable(${PROJECT_NAME} ${src} )

target_link_libraries(
  ${PROJECT_NAME} 
  ${LINK_FLAGS}
)


add_test(tst ${PROJECT_NAME})
