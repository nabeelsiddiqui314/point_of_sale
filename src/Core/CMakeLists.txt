qt_add_library(core STATIC
    # cpp files here
)

target_link_libraries(core PRIVATE Qt6::Core)

# makes it easier to include core header files
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
