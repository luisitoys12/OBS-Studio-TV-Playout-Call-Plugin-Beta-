# instrucciones.md

## Cambios realizados en esta versión

1. Se agregaron previews visuales en `README.md` para mostrar cómo se vería el panel broadcast y la arquitectura inicial del plugin.
2. Se crearon dos recursos gráficos SVG en `docs/images/`:
   - `preview-ui.svg` (mockup visual de operación en vivo).
   - `architecture-overview.svg` (diagrama de componentes y flujo inicial).
3. Se mantuvo la base de compilación CMake + C++20 y el flujo de bootstrap de OBS SDK.

## Requisitos o dependencias nuevas

- No se añadieron dependencias nuevas de runtime/build para el código.
- Solo se incorporaron assets SVG estáticos para documentación visual en README.

## Guía paso a paso para probar la funcionalidad

1. Abrir visualmente la documentación:

   ```bash
   cat README.md
   ```

   O abrir el README en tu editor/visor Markdown para ver las imágenes incrustadas desde `docs/images/*.svg`.

2. Verificar estructura de archivos de preview:

   ```bash
   ls -la docs/images
   ```

3. Validar script de bootstrap:

   ```bash
   bash -n scripts/setup_obs_sdk.sh
   ```

4. Probar configuración de build (requiere SDK libobs instalado):

   ```bash
   cmake -S . -B build
   ```

5. Compilar plugin:

   ```bash
   cmake --build build
   ```
