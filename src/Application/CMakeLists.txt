qt_add_executable(POS
    MainWindow.cpp
    main.cpp
    Scanner/DummyScanner.cpp
    ProductManagementForm.cpp
    ProductAddDialog.cpp
    BillingForm.cpp
)

target_link_libraries(POS PRIVATE
    core
    Qt6::Widgets
)

set_target_properties(POS PROPERTIES
    WIN32_EXECUTABLE ON
)

add_custom_command(TARGET POS POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/python/scanner.py"
    $<TARGET_FILE_DIR:POS>
)
