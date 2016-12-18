cmake_minimum_required(VERSION 3.6)
project(multiset_vs_colony)

set(CMAKE_CXX_STANDARD 14)

include_directories(plf_colony plf_benchmark)

set(SOURCE_FILES multiset_vs_colony.cpp)

add_executable(multiset_vs_colony ${SOURCE_FILES})

#target_link_libraries(lmudcd util libtigoutil tigopublish libtigommu libsysconfig libtigoconfig messenger)
