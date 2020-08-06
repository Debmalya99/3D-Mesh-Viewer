cmake_minimum_required(VERSION 3.11.2)
project(3D_Mesh_Viewer)

#file(OpenGL_Test_SOURCES main.cpp classes/Opengl.cpp)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SFML REQUIRED COMPONENTS graphics window system)
#find_package(GLM REQUIRED)
find_package(ASSIMP REQUIRED)

#sources
file(GLOB SOURCES "classes/*.cpp" "*.cpp" "SFML-backend/*.cpp")

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${ASSIMP_INCLUDE_DIRS})
#include_directories(${GLM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${ASSIMP_LIBRARIES})
