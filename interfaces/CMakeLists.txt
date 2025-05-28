# 收集接口头文件
file(GLOB_RECURSE INTERFACE_HEADERS include/*.h)

# 创建接口库（STATIC）
add_library(MonitorInterfaces STATIC ${INTERFACE_HEADERS})

# 设置为接口库
set_target_properties(MonitorInterfaces PROPERTIES LINKER_LANGUAGE CXX)

# 包含目录
target_include_directories(MonitorInterfaces
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接Qt库
target_link_libraries(MonitorInterfaces
    PUBLIC
    Qt5::Core
    Qt5::Widgets
)    