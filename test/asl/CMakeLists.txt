add_mp_test(aslexpr-test aslexpr-test.cc no-unordered-map-test.cc)
target_link_libraries(aslexpr-test aslmp)

add_mp_test(aslbuilder-test aslbuilder-test.cc LIBS aslmp)
add_mp_test(aslproblem-test aslproblem-test.cc stderr-redirect.h LIBS aslmp)

add_library(ampltestsolver SHARED
  testsolver.cc ${PROJECT_SOURCE_DIR}/src/solver-c.cc)
target_link_libraries(ampltestsolver aslmp)
target_compile_definitions(ampltestsolver PRIVATE MP_SOLVER=testsolver)

add_mp_test(solver-c-test solver-c-test.cc LIBS ampltestsolver)
