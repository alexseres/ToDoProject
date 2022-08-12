include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)


add_executable(
  todo_tests
  user_handler_test.cpp
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Utils.cpp
)


target_include_directories(
  todo_tests
  PUBLIC
  /usr/local/include
  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/UserManager
)

# target_link_directories(todo_tests PUBLIC /Users/alexseres/OwnCplusPlusProjects/ToDoProject/build/src/UserManager/libuser_manager.a)

#find_library(ff user_manager)

target_link_libraries(
  todo_tests
  /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib
  user_manager
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(todo_tests)



# enable_testing()
# add_executable(UserHandlerTests UserHandlerTests.cpp ../src/UserManager/UserHandler.cpp)
# add_executable(UserHandlerTests UserHandlerTests.cpp)
# add_executable(UserHandlerTests UserHandlerTests.cpp)
# target_link_libraries(UserHandlerTests gtest_main)
# add_test(NAME UserHandlerTests COMMAND check_connection)
# include(GoogleTest)
# gtest_discover_tests(UserHandlerTests)


# include_directories(UserHandlerTests.cpp PUBLIC /usr/local/include)
# link_libraries(UserHandlerTests.cpp /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib)
# target_link_libraries(UserHandlerTests gtest_main)
# add_test(NAME UserHandlerTests COMMAND check_Connectivity)


