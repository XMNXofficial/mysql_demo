cmake_minimum_required(VERSION 3.5)
set(MY_PROJECT mysql_demo)
set(MY_TARGET main)
project("${MY_PROJECT}")
add_executable("${MY_TARGET}" main.cpp)

target_include_directories("${MY_TARGET}" PUBLIC externalLib/mysql/include)#头文件搜索目录
target_link_directories("${MY_TARGET}" PUBLIC externalLib/mysql/lib)#库文件搜索目录
target_link_libraries("${MY_TARGET}" PUBLIC mysqlclient)#mysqlclient是静态库.libmysql是动态库(动态库需要dll)

