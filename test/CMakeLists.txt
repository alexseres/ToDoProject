project(ToDoTest)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
  td_test
  user_handler_test.cpp
  data_sql_test.cpp
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Utils/Utils.cpp
)

target_include_directories(
  td_test
  PUBLIC
  /usr/local/include
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Data
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Model
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/View
)

target_link_libraries(
  td_test
  /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib
  data_manager
  models
  GTest::gtest_main
)