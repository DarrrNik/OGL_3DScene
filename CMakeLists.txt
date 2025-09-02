cmake_minimum_required(VERSION 3.10)
project(OGL_3DScene)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(OpenGL REQUIRED)
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

include_directories(
    ${OPENGL_INCLUDE_DIRS} 
    ${SFML_INCLUDE_DIRS} 
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} main.cpp)

add_library(Window STATIC src/Window.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES} SFML::Graphics SFML::Window SFML::System Window)
target_link_libraries(Window PRIVATE ${OPENGL_LIBRARIES} SFML::Graphics SFML::Window SFML::System)
