# 收集源文件
file(GLOB_RECURSE SOURCES *.cpp *.h)

# 添加可执行文件
add_executable(SystemMonitorQt ${SOURCES})

# 链接库
target_link_libraries(SystemMonitorQt 
    PRIVATE 
    Qt5::Widgets
    MonitorInterfaces
)

# 包含目录
target_include_directories(SystemMonitorQt 
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/interfaces/include
)    