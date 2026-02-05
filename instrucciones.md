# instrucciones.md

## Cambios realizados en esta versión

1. Se reconstruyó la base del plugin nativo para OBS Studio con CMake y C++20.
2. Se agregó el punto de entrada del módulo (`src/plugin-main.cpp`) con logs de carga y descarga.
3. Se añadió manifiesto tipado (`include/obs_tv_playout/core/plugin_manifest.hpp`) para metadatos.
4. Se añadió localización base en `data/locale/en-US.ini`.
5. Se añadió `scripts/setup_obs_sdk.sh` para clonar/actualizar OBS Studio y submódulos.
6. Se actualizó `README.md` con pasos de bootstrap y compilación.

## Requisitos o dependencias nuevas

- Git
- CMake 3.24+
- Compilador compatible con C++20
- SDK/libobs disponible para resolver `find_package(libobs REQUIRED)`

## Guía paso a paso para probar la funcionalidad

1. Descargar la base de OBS Studio:

   ```bash
   ./scripts/setup_obs_sdk.sh
   ```

2. Configurar build:

   ```bash
   cmake -S . -B build
   ```

3. Compilar:

   ```bash
   cmake --build build
   ```

4. Verificar que se genere el módulo `obs-tv-playout-call`.
