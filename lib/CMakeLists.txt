set(BASE_SRC
    highlighter.cpp
    repository.cpp
    syntax.qrc
)

set(SRC ${BASE_SRC})

add_library(uds-syntax-highlighter SHARED ${SRC})

target_link_libraries(uds-syntax-highlighter
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Xml
)

