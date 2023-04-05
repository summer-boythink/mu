cmake_minimum_required(VERSION 3.0.0)
project(MU VERSION 0.1.0)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(main example/main.cc EventLoop.cc EventLoop.h)
add_executable(main2 example/main2.cc EventLoop.cc EventLoop.h)

find_package(glog CONFIG REQUIRED)
target_link_libraries(main PRIVATE glog::glog)
target_link_libraries(main2 PRIVATE glog::glog)
