cmake_minimum_required(VERSION 3.24)

project(obs_tv_playout_call_plugin
  VERSION 0.1.0
  DESCRIPTION "OBS TV Playout + Call automation plugin"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(OBS_TV_PLAYOUT_ENABLE_WERROR "Treat warnings as errors" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)
include(compiler-options)

find_package(libobs REQUIRED)

add_library(${PROJECT_NAME} MODULE
  src/plugin-main.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    include
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    OBS_TV_PLAYOUT_VERSION="${PROJECT_VERSION}"
)

set_project_warnings(${PROJECT_NAME} ${OBS_TV_PLAYOUT_ENABLE_WERROR})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    OBS::libobs
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  PREFIX ""
  OUTPUT_NAME "obs-tv-playout-call"
)

install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/obs-plugins"
  RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/obs-plugins")

install(FILES data/locale/en-US.ini
  DESTINATION "${CMAKE_INSTALL_DATADIR}/obs/obs-plugins/obs-tv-playout-call/locale")
