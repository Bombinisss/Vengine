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
        src/ven-pipeline.cpp
        src/ven-pipeline.h
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

# Ensure shaders directory exists in build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)

# Compile vertex shader
add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/shaders/simple_shader.vert.spv
        COMMAND glslc ${CMAKE_CURRENT_SOURCE_DIR}/shaders/simple_shader.vert -o ${CMAKE_BINARY_DIR}/shaders/simple_shader.vert.spv
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/simple_shader.vert
)

# Compile fragment shader
add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/shaders/simple_shader.frag.spv
        COMMAND glslc ${CMAKE_CURRENT_SOURCE_DIR}/shaders/simple_shader.frag -o ${CMAKE_BINARY_DIR}/shaders/simple_shader.frag.spv
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/simple_shader.frag
)

# Combine both shader compilation commands into a custom target
add_custom_target(compile_shaders
        DEPENDS ${CMAKE_BINARY_DIR}/shaders/simple_shader.vert.spv
        ${CMAKE_BINARY_DIR}/shaders/simple_shader.frag.spv
)

# Make sure the Vengine executable depends on the compiled shaders
add_dependencies(Vengine compile_shaders)