add_test([=[MyLibTest.AddFunction]=]  /home/awe/Desktop/clion/large_project_template/build/tests/unit_tests [==[--gtest_filter=MyLibTest.AddFunction]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MyLibTest.AddFunction]=]  PROPERTIES WORKING_DIRECTORY /home/awe/Desktop/clion/large_project_template/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  unit_tests_TESTS MyLibTest.AddFunction)
