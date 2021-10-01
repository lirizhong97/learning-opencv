cmake_minimum_required(VERSION 2.8)

project(opencv-template)

# 引入公共脚本文件
include("${PROJECT_SOURCE_DIR}/build.cmake")

include_directories(include)
add_subdirectory(src)
