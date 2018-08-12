cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "DEBUG")

project(rotation)

include_directories(include)

aux_source_directory(src DIR_SRCS)
message(${DIR_SRCS})

SET(TEST_PATH ${DIR_SRCS})

#EIGEN
find_package(Eigen3)
include_directories(${EIGEN3_INCLUDE_DIRS})
#CERES
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})
#Open CV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(rotation ${TEST_PATH})
target_link_libraries(rotation ${OpenCV_LIBS} ${CERES_LIBRARIES})
