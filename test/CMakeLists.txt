cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)

#=========================================================================================

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#=========================================================================================

set(TEST_OUT pool_test)

add_executable(${TEST_OUT} pool_test.cpp ../pool.cpp)
target_link_libraries(${TEST_OUT} gtest_main)

include(GoogleTest)
gtest_discover_tests(${TEST_OUT})

if(ADD_SANITIZERS)
    message("-- [Build test with sanitizers]")
    target_compile_options(${TEST_OUT} PUBLIC -fsanitize=address -g)
    set_target_properties(${TEST_OUT}  PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

add_custom_target(run_${TEST_OUT}
    COMMENT "Running tests"
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${TEST_OUT}
)

add_dependencies(run_${TEST_OUT} ${TEST_OUT})
