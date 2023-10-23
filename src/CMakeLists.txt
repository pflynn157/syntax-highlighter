set(BASE_SRC
    main.cpp
    toolbar.cpp
    window.cpp
)

set(SRC ${BASE_SRC})

add_executable(uds-viewer ${SRC})

target_link_libraries(uds-viewer
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Xml
    uds-syntax-highlighter
)

