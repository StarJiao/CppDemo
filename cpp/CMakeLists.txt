#设置cmake最低版本
cmake_minimum_required (VERSION	2.8.8)

#使用C++ 11 特性
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#工程名
project (demo)

#添加下层的CMakeLists.txt
#add_subdirectory(src)

#查找所有源文件并存入变量ALL_SRCS
#aux_source_directory(. ALL_SRCS)

#生成静态链接库
#add_library (SOME_LIB ${ALL_SRCS})

#生成动态链接库
#add_library (SOME_LIB SHARED ${ALL_SRCS})

#生成可执行文件
add_executable(demo Demo.cpp)
#add_executable(exam exam.cpp)

#生成可执行文件或其他库时链接的目标库、此处是上面生成的
#target_link_libraries(demo SOME_LIB)
