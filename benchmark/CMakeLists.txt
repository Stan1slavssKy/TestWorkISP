cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDART 11)

find_package(benchmark REQUIRED)

set(BENCH_OUT bench)
set(RUN_BENCH run_pool_bench)

add_executable(${BENCH_OUT} pool_bench.cpp ../pool.cpp)
target_link_libraries(${BENCH_OUT} benchmark::benchmark)

add_custom_target(${RUN_BENCH}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${BENCH_OUT}
)

add_dependencies(${RUN_BENCH} ${BENCH_OUT})

if(ADD_SANITIZERS)
    target_compile_options(${BENCH_OUT} PUBLIC -fsanitize=address -g)
    set_target_properties(${BENCH_OUT}  PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()
