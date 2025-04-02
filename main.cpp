#include "configuration.h"
#include "hyprbar-window.h"

#include <CLI/CLI.hpp>
#include <fmt/std.h>
#include <gtkmm/application.h>

#include <filesystem>

using namespace hyprbar;

namespace hyprbar {
std::string full_config_path(std::string const &basePath,
                             std::string const &programName) {
  return basePath + "/hypr/" + programName + ".conf";
}

bool check_config_exists(std::string const &basePath,
                         std::string const &programName) {
  return std::filesystem::exists(full_config_path(basePath, programName));
}

auto find_config_file() -> std::string {
  const auto xdg_config_home{getenv("XDG_CONFIG_HOME")};
  if (xdg_config_home != nullptr) {
    fmt::println("XDG_CONFIG_DIRS: {}", xdg_config_home);
    return xdg_config_home;
  }

  auto const xdg_config_dirs{getenv("XDG_CONFIG_DIRS")};

  if (xdg_config_dirs != nullptr) {
    fmt::println("XDG_CONFIG_DIRS: {}", xdg_config_dirs);
    return xdg_config_dirs;
  }

  return {};
}

} // namespace hyprbar

int main(int argc, char **argv) {
  CLI::App cli11;

  std::filesystem::path config_file;
  cli11.add_option("-c,--config", config_file, "Configuration file")
      ->default_function([]() {
        fmt::println("test");
        return "xxx";
      })
      ->default_val(find_config_file());

  CLI11_PARSE(cli11, argc, argv);

  fmt::println("config file: {}", config_file);

  auto config{Configuration(config_file)};

  auto app{Gtk::Application::create("org.gtkmm.example")};

  // Shows the window and returns when it is closed.
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}
