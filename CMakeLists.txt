cmake_minimum_required(VERSION 3.17)
project(c_compiler)
set(CMAKE_CXX_STANDARD 20)

add_executable(c_compiler main.cpp src/CodeGen.cpp src/Lexer.cpp src/Parser.cpp src/AstNode.cpp src/PrintVisitor.cpp src/driver.c)