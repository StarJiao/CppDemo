#设置cmake最低版本
cmake_minimum_required (VERSION	2.8.8)

#工程名
project (demo)

#设置可执行文件的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  

#添加下层的CMakeLists.txt
add_subdirectory(src)

#输出源文件目录、二进制文件（构建过程文件）目录、可执行文件目录
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message("EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")
