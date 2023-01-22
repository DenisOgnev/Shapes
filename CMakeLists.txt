cmake_minimum_required(VERSION 3.0.0)
project(shapes_library)

file(GLOB SRC
    "${PROJECT_SOURCE_DIR}/src/circle.cpp"
    "${PROJECT_SOURCE_DIR}/src/ellipse.cpp"
    "${PROJECT_SOURCE_DIR}/src/helix.cpp"
)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif(MSVC)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(/W4)

find_package(OpenMP REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

add_executable(shapes_binary ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(shapes_binary shapes_library)
target_link_libraries(shapes_binary OpenMP::OpenMP_CXX)