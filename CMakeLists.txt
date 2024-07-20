cmake_minimum_required(VERSION 3.20)

project(crepl)

add_executable(crepl)

target_sources(crepl PRIVATE
    main.c
)

add_library(crepllib SHARED)

target_sources(crepllib PRIVATE
    crepl.c
)

target_link_libraries(crepl PRIVATE crepllib ${OPENGL_LIBRARIES})

# tests

add_executable(test_ascii)

target_sources(test_ascii PRIVATE
    test_ascii.c
    ascii.c
)

add_test(NAME test_ascii COMMAND test_ascii) 

add_executable(test_token)

target_sources(test_token PRIVATE
    test_token.c
    token.c
)

add_test(NAME test_token COMMAND test_token)


enable_testing()