add_test( ExampleTests.Example /home/kretkiew/visualExercises/cavestory/build/tst/CaveStory-test [==[--gtest_filter=ExampleTests.Example]==] --gtest_also_run_disabled_tests)
set_tests_properties( ExampleTests.Example PROPERTIES WORKING_DIRECTORY /home/kretkiew/visualExercises/cavestory/build/tst SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( CaveStory-test_TESTS ExampleTests.Example)
