cmake_minimum_required(VERSION 3.0.0)
project(uds-syntax-highlighter)

set(BASE_SRC
    main.cpp
    window.cpp
    highlighter.cpp
    repository.cpp
    syntax.qrc
)

set(SRC ${BASE_SRC})

add_executable(uds-syntax-highlighter ${SRC})

target_link_libraries(uds-syntax-highlighter
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Xml
)

