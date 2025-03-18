cmake_minimum_required(VERSION 3.10)
project(Q_Learning_3D)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Q_Learning_3D src/main.cpp src/qlearning.cpp src/rendering.cpp)
target_link_libraries(Q_Learning_3D OpenGL::GL GLEW::GLEW glfw)
