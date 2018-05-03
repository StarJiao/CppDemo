cmake_minimum_required(VERSION 2.8)

project(cv_demo)

find_package(OpenCV REQUIRED)

#add_executable(demo DisplayImage.cpp)
#add_executable(demo show_color_picture.cpp)
add_executable(demo comb_img.cpp)
#add_executable(demo camera_preview.cpp)

target_link_libraries(demo  ${OpenCV_LIBS})

message("OpenCV_LIBS:${OpenCV_LIBS}")
