cmake_minimum_required(VERSION 3.20)
project(wayland-top-bar VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard to C++26
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)
pkg_check_modules(GTK4LAYERSHELL REQUIRED IMPORTED_TARGET gtk4-layer-shell-0)
pkg_check_modules(GTK4MM REQUIRED IMPORTED_TARGET gtkmm-4.0)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 11.1.4

)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.5.0
)

FetchContent_MakeAvailable(cli11_proj)

FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

# Add the executable
add_executable(wayland-top-bar
    configuration.cpp
    hyprbar-window.cpp
    main.cpp
)

# Link libraries
target_link_libraries(wayland-top-bar PRIVATE
    fmt::fmt
    CLI11::CLI11
    PkgConfig::GTK4
    PkgConfig::GTK4MM
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

