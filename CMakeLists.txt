cmake_minimum_required(VERSION 3.10)
project(OGL_3DScene)

set(CMAKE_PREFIX_PATH "C:/msys64")
set(MINGW_BIN C:/msys64/mingw64/bin)

set(WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/Workdir)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${WORKING_DIRECTORY})

set(CMAKE_EXE_LINKER_FLAGS "-static")
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
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${WORKING_DIRECTORY}")

add_library(Window STATIC src/Window.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES} SFML::Graphics SFML::Window SFML::System)
target_link_libraries(Window PRIVATE ${OPENGL_LIBRARIES} SFML::Graphics SFML::Window SFML::System)

foreach(dll libgcc_s_seh-1.dll libstdc++-6.dll libwinpthread-1.dll)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MINGW_BIN}/libgcc_s_seh-1.dll"
            ${WORKING_DIRECTORY}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MINGW_BIN}/libstdc++-6.dll"
            ${WORKING_DIRECTORY}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${MINGW_BIN}/libwinpthread-1.dll"
            ${WORKING_DIRECTORY}
    )
endforeach()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:${PROJECT_NAME}>
            ${WORKING_DIRECTORY}
)
