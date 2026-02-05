#include <obs-module.h>

#include "obs_tv_playout/core/plugin_manifest.hpp"

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("obs-tv-playout-call", "en-US")

namespace {
constexpr auto kModuleAuthor = "OBS TV Playout Team";
}

[[nodiscard]] const char *obs_module_name(void)
{
  return "OBS TV Playout Call";
}

[[nodiscard]] const char *obs_module_description(void)
{
  return obs_module_text("OBSTVPlayoutCall.PluginDescription");
}

bool obs_module_load(void)
{
  const auto metadata = obs_tv_playout::core::manifest();
  blog(LOG_INFO,
       "[%s] Loaded %.*s v%.*s by %s",
       metadata.id.data(),
       static_cast<int>(metadata.display_name.size()),
       metadata.display_name.data(),
       static_cast<int>(metadata.version.size()),
       metadata.version.data(),
       kModuleAuthor);

  return true;
}

void obs_module_unload(void)
{
  const auto metadata = obs_tv_playout::core::manifest();
  blog(LOG_INFO, "[%s] Unloaded cleanly", metadata.id.data());
}
