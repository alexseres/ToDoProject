add_test([=[UserHandlerTest.check_connection]=]  /Users/alexseres/OwnCplusPlusProjects/ToDoProject/test/build/todo_tests [==[--gtest_filter=UserHandlerTest.check_connection]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[UserHandlerTest.check_connection]=]  PROPERTIES WORKING_DIRECTORY /Users/alexseres/OwnCplusPlusProjects/ToDoProject/test/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  todo_tests_TESTS UserHandlerTest.check_connection)
