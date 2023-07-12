qt_add_library(core STATIC
    Scanner/Scanner.h
    Scanner/CameraScanner.cpp
    Database/ProductDatabase.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Sql)

target_link_libraries(core PRIVATE
    Qt6::Core
    Qt6::Sql
    pybind11::embed
)

# makes it easier to include core header files
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
