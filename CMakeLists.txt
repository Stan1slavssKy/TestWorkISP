cmake_minimum_required(VERSION 3.8)
project(Test_work)
set(CMAKE_CXX_STANDART 17)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo

    -fno-elide-constructors
    -g3
)

if(ADD_CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY
        clang-tidy;
        --format-style=file;
        --header-filter=*.hpp;
    )
    message("-- [Build with clang tidy]")
endif()

set(EXEC pool)
set(RUN_EXEC run_pool)

add_executable(${EXEC} pool.cpp main.cpp)

if(ADD_SANITIZERS)
    message("-- [Build with sanitizers]")
    target_compile_options(${EXEC} PUBLIC -fsanitize=address -g)
    set_target_properties(${EXEC}  PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

add_custom_target(${RUN_EXEC}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC}
)

add_dependencies(${RUN_EXEC} ${EXEC})
