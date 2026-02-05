#!/usr/bin/env bash
set -euo pipefail

OBS_REF="${OBS_REF:-30.1.2}"
TARGET_DIR="${1:-third_party/obs-studio}"

if ! command -v git >/dev/null 2>&1; then
  echo "[ERROR] git is required." >&2
  exit 1
fi

if [[ -d "${TARGET_DIR}/.git" ]]; then
  echo "[INFO] OBS repository already exists at ${TARGET_DIR}."
  echo "[INFO] Fetching latest refs and checking out ${OBS_REF}."
  git -C "${TARGET_DIR}" fetch --tags --prune
else
  echo "[INFO] Cloning OBS Studio into ${TARGET_DIR}."
  git clone https://github.com/obsproject/obs-studio.git "${TARGET_DIR}"
fi

git -C "${TARGET_DIR}" checkout "${OBS_REF}"
git -C "${TARGET_DIR}" submodule update --init --recursive

echo "[OK] OBS Studio source is ready at ${TARGET_DIR} (ref: ${OBS_REF})."
