#pragma once

#include <string_view>

namespace obs_tv_playout::core {

struct PluginManifest {
  std::string_view id;
  std::string_view display_name;
  std::string_view version;
  std::string_view description;
};

[[nodiscard]] constexpr PluginManifest manifest() noexcept
{
  return {
    .id = "obs-tv-playout-call",
    .display_name = "OBS TV Playout Call",
    .version = OBS_TV_PLAYOUT_VERSION,
    .description = "TV playout automation + call workflows for OBS Studio",
  };
}

} // namespace obs_tv_playout::core
