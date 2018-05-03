#查找当前目录下的所有源文件
#并将名称保存到变量DIR_LIB_SRCS
aux_source_directory(./math DIRL_LIB_SRCS)

#生成静态链接库
#add_library (MathFun ${DIRL_LIB_SRCS})

#生成动态链接库
add_library (MathFun SHARED ${DIRL_LIB_SRCS})

#生成可执行文件
add_executable(demo Demo.cpp)

#生成可执行文件或其他库时链接的目标库、此处是上面生成的
target_link_libraries(demo MathFun)
