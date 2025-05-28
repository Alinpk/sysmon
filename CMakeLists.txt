cmake_minimum_required(VERSION 3.16)
project(SystemMonitorQt VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置Qt路径（如果需要）
# set(Qt5_DIR /path/to/Qt5/lib/cmake/Qt5)

# 查找Qt组件
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 启用GUI应用
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 添加子目录
add_subdirectory(src)
add_subdirectory(interfaces)
add_subdirectory(plugins)    