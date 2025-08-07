cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(geometric_shapes)

add_executable(GeometricShapes src/main.cpp src/GeometricShape.cpp src/GeometricShape.h src/Square.cpp src/Square.h src/Rectangle.cpp 
src/Rectangle.h src/Triangle.cpp src/Triangle.h src/Point.cpp src/Point.h src/ShapeCalculationHandler.h src/ShapeCalculationHandler.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra")
