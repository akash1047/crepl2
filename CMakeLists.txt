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


