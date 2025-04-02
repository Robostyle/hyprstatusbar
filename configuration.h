#pragma once

#include <filesystem>

namespace hyprbar {

class Configuration {
public:
  Configuration(std::filesystem::path const &config_file);

private:
};

} // namespace hyprbar
