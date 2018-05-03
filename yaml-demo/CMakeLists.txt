cmake_minimum_required (VERSION 2.8.8)

project(yaml_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(yaml-cpp REQUIRED)

add_executable(yaml_demo yaml_demo.cpp)
#add_executable(yaml_emitt yaml_emitt.cpp)

#target_link_libraries(yaml_emitt ${yaml-cpp_LIBS})

if (yaml-cpp_FOUND)
	message("YAML_CPP_INCLUDE_DIR:${YAML_CPP_INCLUDE_DIR}")
	message("YAML_CPP_LIBRARIES:${YAML_CPP_LIBRARIES}")
	include_directories(${YAML_CPP_INCLUDE_DIR})
	target_link_libraries (yaml_demo ${YAML_CPP_LIBRARIES})
else()
	message("yaml-cpp not found")
endif ()

