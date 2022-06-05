cmake_minimum_required(VERSION 3.10)
project(MoreOrLess)
set(CMAKE_CXX_STANDARD 11)

# SFML preparations
include(FetchContent)
set(SFML_VERSION "2.5.1")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)
message(STATUS "Fetching SFML...")
# Most probably no need to build audio and network modules
set(SFML_BUILD_AUDIO FALSE)
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)
# End of SFML preparations

# Project itself
add_executable(MoreOrLess
    src/main.cpp
)

target_link_libraries(MoreOrLess
    PRIVATE
        sfml-graphics
        sfml-system
        sfml-window
)

# Copy resources near to executable
add_custom_command(TARGET MoreOrLess POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:MoreOrLess>/res
    COMMENT "Created ${PROJECT_BINARY_DIR}/test_base.exe"
)