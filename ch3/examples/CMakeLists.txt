project(ch3_example)
cmake_minimum_required(VERSION 3.16)

include_directories("/usr/include/eigen3")


find_package(Pangolin REQUIRED)
find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Pangolin_INCLUDE_DIRS})
add_definitions(${OpenCV_DEFINITIONS})


link_directories(${OpenCV_LIBRARY_DIRS})

add_executable(plotTrajectory plotTrajectory.cpp)
add_executable(coordinateTransform coordinateTransform.cpp)

target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})
target_link_libraries(plotTrajectory ${OpenCV_LIBRARIES})