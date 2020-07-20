#cmake_minimum_required(VERSION 3.16)
project(PythonAPI)

set(CMAKE_CXX_STANDARD 14)


# 添加Python.h头文件路径
include_directories(/Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m)
# 添加python动态链接库文件目录
link_directories(/Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/config-3.6m-darwin)

add_executable(PythonAPI example/P2/Python2_Var.cpp)
target_link_libraries(PythonAPI libpython3.6m.a)
target_link_libraries(PythonAPI ${CMAKE_DL_LIBS})