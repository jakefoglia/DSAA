cmake_minimum_required(VERSION 3.22)
project(DSAA)

add_library (Sorts src/Sorts/Sorts.cpp)
target_include_directories(Sorts PRIVATE "include/Sorts")

add_library (Graph src/Graph/Graph.cpp)
target_include_directories(Graph PRIVATE "include/Graph")

add_library(DSAA INTERFACE)
target_link_libraries(DSAA
    INTERFACE Sorts
    INTERFACE Graph
)