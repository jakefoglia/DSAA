cmake_minimum_required(VERSION 3.22)
project(DSAA)


add_library (Sorts src/Sorts/Sorts.cpp)
target_include_directories(Sorts PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/Sorts"                          
)

add_library (Graph src/Graph/Graph.cpp)
target_include_directories(Graph PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/Graph"                          
)
