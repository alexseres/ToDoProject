project(ToDoTest)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
  td_test
  user_handler_test.cpp
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Utils.cpp
)

target_include_directories(
  td_test
  PUBLIC
  /usr/local/include
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/UserManager
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Model
)

target_link_libraries(
  td_test
  /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib
  user_manager
  GTest::gtest_main
)