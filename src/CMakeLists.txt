cmake_minimum_required(VERSION 3.0.0)
project(uds-syntax-highlighter)

set(BASE_SRC
    main.cpp
    toolbar.cpp
    window.cpp
)

set(SRC ${BASE_SRC})

add_executable(uds-viewer ${SRC})

target_link_libraries(uds-viewer
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Xml
    uds-syntax-highlighter
)

