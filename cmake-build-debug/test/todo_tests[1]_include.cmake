if(EXISTS "/Users/alexseres/OwnCplusPlusProjects/ToDoProject/cmake-build-debug/test/todo_tests[1]_tests.cmake")
  include("/Users/alexseres/OwnCplusPlusProjects/ToDoProject/cmake-build-debug/test/todo_tests[1]_tests.cmake")
else()
  add_test(todo_tests_NOT_BUILT todo_tests_NOT_BUILT)
endif()
