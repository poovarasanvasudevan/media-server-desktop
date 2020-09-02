cmake_minimum_required(VERSION 3.17)
project("OfficeApp")

set (CMAKE_PREFIX_PATH "/home/poovarasan/Qt5.14.2/5.14.2/gcc_64/lib/cmake")
find_package(Qt5 COMPONENTS Widgets Qml Quick Core Multimedia REQUIRED)
add_subdirectory(src)