cmake_minimum_required(VERSION 3.18)

project(linked_lists_proj)

add_compile_options(-std=c++11)

file(GLOB SOURCE_FILES ./*.cpp ./*.h)
#add_library(wvector SHARED ${SOURCE_VECTOR})

#aux_source_directory(. SOURCE_FILES)
add_executable(linked_lists_run ${SOURCE_FILES})
#target_link_libraries(arrays wvector)