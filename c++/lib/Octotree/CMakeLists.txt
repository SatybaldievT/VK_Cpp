# Добавляем библиотеку
add_library(Octotree STATIC src/Octotree.cpp)

# Добавляем зависимости для библиотеки
target_link_libraries(Octotree glm)

# Добавляем пути для поиска заголовочных файлов
target_include_directories(Octotree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)