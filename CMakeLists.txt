cmake_minimum_required(VERSION 3.0)

project(helloworld)

add_executable(helloworld main.cpp)

install(TARGETS helloworld RUNTIME DESTINATION bin)
