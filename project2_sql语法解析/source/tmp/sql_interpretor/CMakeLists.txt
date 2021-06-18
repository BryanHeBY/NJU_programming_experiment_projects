cmake_minimum_required(VERSION 3.17)
project(sql_interpretor)

set(CMAKE_CXX_STANDARD 14)

add_executable(sql_interpretor main.cpp DObject.cpp DObject.h SQLError.h DTable.cpp DTable.h parser.h DFunc.cpp DFunc.h DCol.cpp DCol.h DExpr.cpp DExpr.h)