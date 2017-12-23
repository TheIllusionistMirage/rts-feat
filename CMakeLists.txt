cmake_minimum_required(VERSION 2.6)
project(rtsfeat)

add_executable(rtsfeat main.cpp)

install(TARGETS rtsfeat RUNTIME DESTINATION bin)
