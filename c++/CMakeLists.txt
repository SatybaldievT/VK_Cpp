cmake_minimum_required(VERSION 3.0.0)
project(Box VERSION 0.1.0)



# Добавляем подпроект Octotree
add_subdirectory(lib/Octotree)


add_executable(Box main.cpp)


add_subdirectory(glfw)
target_link_libraries(Box glfw)
add_subdirectory(glm)
target_link_libraries(Box glm)
# Связываем Octotree с my_executable
target_link_libraries(Box Octotree)