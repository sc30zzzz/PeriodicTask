# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(PeriodicTaskProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(periodic_task 
    main.cpp
    src/Utilities/Utilities_print.cpp
    src/Utilities/PeriodicTask.cpp
)

# 查找线程库
find_package(Threads REQUIRED)

# 链接线程库
target_link_libraries(periodic_task PRIVATE Threads::Threads)

# 添加包含目录
target_include_directories(periodic_task PRIVATE
    include
)
