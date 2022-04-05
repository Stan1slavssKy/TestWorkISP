To build cmake with tests:
    cmake .. -DADD_POOL_TESTS=ON

To build cmake with all targets:
    cmake .. -DADD_POOL_TESTS=ON -DADD_CLANG_TIDY=ON -DADD_SANITIZERS=ON

To run:
    make run_pool
    