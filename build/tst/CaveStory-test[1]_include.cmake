if(EXISTS "/home/kretkiew/visualExercises/cavestory/build/tst/CaveStory-test[1]_tests.cmake")
  include("/home/kretkiew/visualExercises/cavestory/build/tst/CaveStory-test[1]_tests.cmake")
else()
  add_test(CaveStory-test_NOT_BUILT CaveStory-test_NOT_BUILT)
endif()