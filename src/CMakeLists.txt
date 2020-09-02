include_directories(
        ${Qt5Widgets_INCLUDE_DIRS}
        ${Qt5Core_INCLUDE_DIRS}
        ${QtQml_INCLUDE_DIRS}
        ${Qt5Multimedia_INCLUDE_DIRS}
)
add_definitions(
        ${Qt5Widgets_DEFINITIONS}
        ${Qt5Core_DEFINITIONS}
        ${QtQml_DEFINITIONS}
        ${Qt5Quick_DEFINITIONS}
        ${Qt5Multimedia_DEFINITIONS}
)
qt5_add_resources(QT_RESOURCES qml.qrc)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT "Base")

project(${PROJECT})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")

if (NOT DEFINED HEADERS)
    file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/hpp/*.h)
endif ()

if (NOT DEFINED SOURCES)
    file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp)
endif ()

if (NOT DEFINED WINDOW)
    file(GLOB WINDOW ${CMAKE_CURRENT_SOURCE_DIR}/window/*/*.cpp)
endif ()

if (NOT DEFINED WINDOWHEADER)
    file(GLOB WINDOWHEADER ${CMAKE_CURRENT_SOURCE_DIR}/window/*/*.h)
endif ()

if (NOT DEFINED UI)
    file(GLOB UI ${CMAKE_CURRENT_SOURCE_DIR}/window/*/*.ui)
endif ()

if (NOT DEFINED UIHEADER)
    file(GLOB UIHEADER ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.h)
endif ()



source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("Window Files" FILES ${WINDOWHEADER} ${WINDOW})
source_group("Ui Files" FILES ${UI})

add_executable(${PROJECT} ${HEADERS} ${SOURCES} ${UIHEADER} ${WINDOWHEADER} ${WINDOW} ${UI} ${QT_RESOURCES})

target_link_libraries(
        ${PROJECT}
        Qt5::Widgets
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
        Qt5::Multimedia
)