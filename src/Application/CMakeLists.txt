qt_add_executable(POS
    MainWindow.ui
    MainWindow.cpp
    main.cpp
)

target_link_libraries(POS PRIVATE
    core
    Qt6::Widgets
)

set_target_properties(POS PROPERTIES
    WIN32_EXECUTABLE ON
)
