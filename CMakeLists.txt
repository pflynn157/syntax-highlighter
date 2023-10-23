cmake_minimum_required(VERSION 3.10.0)
project(syntax-highlighter)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_compile_options(-std=c++17)

include_directories(lib)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Gui
    Xml
)

add_subdirectory(lib)
add_subdirectory(src)

#if (UNIX)
#	install(FILES share/my-app.desktop DESTINATION /usr/share/applications)
#	install(CODE "execute_process(COMMAND update-desktop-database)")
#endif()

