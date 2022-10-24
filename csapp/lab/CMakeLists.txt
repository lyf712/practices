cmake_minimum_required(VERSION 3.23)
project(lab)
set(CMAKE_CXX_STANDARD 14)
add_executable(test2 look_bytes.cpp ../cmakes/demo/main.cpp ../cmakes/demo/math/math.cpp ../cmakes/demo/math/math.h)