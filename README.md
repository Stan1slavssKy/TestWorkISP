To build cmake with all targets:

    cmake .. -DADD_CLANG_TIDY=ON -DADD_SANITIZERS=ON

To use:

    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Release
    make run_pool
    
To run tests:

    make run_pool_test

To run benchmark:

    make run_pool_bench
    