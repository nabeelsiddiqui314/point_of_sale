qt_add_executable(POS
    MainWindow.cpp
    main.cpp
    Scanner/DummyScanner.cpp
    ScannerDialog/scandialog.cpp
    billDialog/billdialog.cpp
    addItems/addItem.cpp
)

target_link_libraries(POS PRIVATE
    core
    Qt6::Widgets
)

set_target_properties(POS PROPERTIES
    WIN32_EXECUTABLE ON
)
