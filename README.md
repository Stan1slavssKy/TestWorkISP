To build cmake with tests:
    
    cmake ..

To build cmake with all targets:

    cmake .. -DADD_CLANG_TIDY=ON -DADD_SANITIZERS=ON

To run:

    make run_pool
    