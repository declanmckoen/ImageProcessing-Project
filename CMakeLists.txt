cmake_minimum_required(VERSION 3.25)
project(ImageProcessing)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImageProcessing main.cpp image.h image.cpp functions.h)
