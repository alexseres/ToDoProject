if(EXISTS "/Users/alexseres/OwnCplusPlusProjects/ToDoProject/test/build/user_handler_test[1]_tests.cmake")
  include("/Users/alexseres/OwnCplusPlusProjects/ToDoProject/test/build/user_handler_test[1]_tests.cmake")
else()
  add_test(user_handler_test_NOT_BUILT user_handler_test_NOT_BUILT)
endif()
