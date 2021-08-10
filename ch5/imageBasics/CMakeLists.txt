cmake_minimum_required(VERSION 3.16)
project(imageBasics)

add_definitions(-std=c++11)

set(CMAKE_BUILD_TYPE "Release")
# 添加c++ 11标准支持
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

# Eigen
include_directories("/usr/include/eigen3")

# 寻找OpenCV库
find_package(OpenCV 4.1 REQUIRED)

# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

message("OpenCV Include Dir is ${OpenCV_INCLUDE_DIRS}\n")
message("OpenCV Library Dir is ${OpenCV_LIBRARY_DIRS}\n")

add_executable(imageBasics imageBasics.cpp)
# 链接OpenCV库
target_link_libraries(imageBasics ${OpenCV_LIBRARIES})

add_executable(undistortImage undistortImage.cpp)
# 链接OpenCV库
target_link_libraries(undistortImage ${OpenCV_LIBRARIES})
