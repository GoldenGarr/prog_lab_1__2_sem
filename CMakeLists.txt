cmake_minimum_required(VERSION 3.20)
project(lab1_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1_cpp main.cpp figures/Point.cpp figures/Point.h figures/PolyLine.cpp figures/PolyLine.h figures/ClosedPolyLine.cpp figures/ClosedPolyLine.h figures/Polygon.cpp figures/Polygon.h polynomial/Polynomial.cpp figures/Triangle.cpp figures/Triangle.h figures/Trapezoid.cpp figures/Trapezoid.h figures/RegularPolygon.cpp figures/RegularPolygon.h)
