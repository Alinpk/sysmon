# 设置插件名称
set(PLUGIN_NAME CPUMonitor)

# 收集源文件
file(GLOB_RECURSE SOURCES *.cpp *.h)

# 添加共享库
add_library(${PLUGIN_NAME} SHARED ${SOURCES})

# 链接库
target_link_libraries(${PLUGIN_NAME}
    PRIVATE
    Qt5::Widgets
    MonitorInterfaces
)

# 包含目录
target_include_directories(${PLUGIN_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/interfaces/include
)

# 设置输出目录
set_target_properties(${PLUGIN_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)    