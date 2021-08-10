cmake_minimum_required(VERSION 3.16)
project(rgbd)

add_definitions(-std=c++11)

set(CMAKE_BUILD_TYPE "Release")
# 添加c++ 11标准支持
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

# Eigen
include_directories("/usr/include/eigen3")


find_package(Sophus REQUIRED)
# 寻找OpenCV库
find_package(OpenCV 4.1 REQUIRED)
find_package(Pangolin REQUIRED)

# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})
include_directories(${Sophus_INCLUDE_DIRS})

find_package(Pangolin REQUIRED)

add_executable(joinMap joinMap.cpp)
target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES})