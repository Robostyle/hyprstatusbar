cmake_minimum_required(VERSION 3.20)
project(wayland-top-bar VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++26
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)
pkg_check_modules(GTK4LAYERSHELL REQUIRED IMPORTED_TARGET gtk4-layer-shell-0)

include(FetchContent)
FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.5.0
)

FetchContent_MakeAvailable(cli11_proj)

# Add the executable
add_executable(wayland-top-bar
    topbar.cpp
)

# Link libraries
target_link_libraries(wayland-top-bar PRIVATE
    CLI11::CLI11
    PkgConfig::GTK4
    PkgConfig::GTK4LAYERSHELL
)

# Installation rules
install(TARGETS wayland-top-bar
        RUNTIME DESTINATION bin)

# Add compile options for warnings
target_compile_options(wayland-top-bar PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    # -Werror
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# Print GTK4 and GTK4-Layer-Shell information
message(STATUS "GTK4 found: ${GTK4_FOUND}")
message(STATUS "GTK4 version: ${GTK4_VERSION}")
message(STATUS "GTK4 include dirs: ${GTK4_INCLUDE_DIRS}")
message(STATUS "GTK4 library dirs: ${GTK4_LIBRARY_DIRS}")

message(STATUS "GTK4-Layer-Shell found: ${GTK4LAYERSHELL_FOUND}")
message(STATUS "GTK4-Layer-Shell version: ${GTK4LAYERSHELL_VERSION}")
