cmake_minimum_required(VERSION 3.15)
project(grep_homework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0 -Wshadow -D GOLIKOV -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

set(QT_BIN "${PROJECT_SOURCE_DIR}/QtBinDebug")

set(QT5_LIB_DIR $/usr/lib/x86_64-linux-gnu/cmake)
set(QT5_CORE ${QT_LIB_DIR}/Qt5Core)
set(QT5_WIDGETS ${QT_LIB_DIR}/Qt5Widgets)
set(QT5_GUI ${QT_LIB_DIR}/Qt5Gui)
set(QT_LIBRARIES Qt5::Core Qt5::Widgets Qt5::Gui)
set(QT_LIBRARIES_REQUIRED Qt5Core Qt5Widgets Qt5Gui)
foreach(QT_LIBRARIES_REQUIRED ${QT_LIBRARIES_REQUIRED})
    find_package( ${QT_LIBRARIES_REQUIRED} REQUIRED )
endforeach()

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

add_custom_target(qtMakefile COMMAND make -C ${QT_BIN})

include_directories(${QT_BIN})
set(SOURCE_FILES main.cpp background_thread.cpp mainwindow.cpp
        background_thread.h mainwindow.h mainwindow.ui ui_mainwindow.h)

add_executable(grep_homework ${SOURCE_FILES})
target_link_libraries(grep_homework ${QT_LIBRARIES} -lpthread)
