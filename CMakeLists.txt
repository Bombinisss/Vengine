cmake_minimum_required(VERSION 3.29)
project(Vengine)

set(CMAKE_CXX_STANDARD 20)

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Find GLFW and GLM packages
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Add the executable
add_executable(Vengine src/main.cpp
        src/ven-window.cpp
        src/ven-window.h
        src/app-controller.cpp
        src/app-controller.h
)

# Link libraries
target_link_libraries(Vengine
        PRIVATE
        Vulkan::Vulkan
        glfw
        glm::glm
)

# Include directories (not always necessary as `find_package` should handle it)
target_include_directories(Vengine
        PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)