cmake_minimum_required(VERSION 3.23)
project(practice)

aux_source_directory(. PRACTICE_SRC)
# add_subdirectory(lang)
add_subdirectory(typecast)
add_subdirectory(lang)

add_executable(practice ${PRACTICE_SRC} main.cpp)
# target_link_libraries(practice type_cast)