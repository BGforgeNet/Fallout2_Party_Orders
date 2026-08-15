#!/bin/bash

set -xeu -o pipefail

short_sha="$(git rev-parse --short HEAD)"
# defaults, local build or github non-tagged
version="git$short_sha"

# tagged build
if [[ -n "${GITHUB_REF-}" ]]; then                 # github build
    if echo "$GITHUB_REF" | grep "refs/tags"; then # tagged
        # shellcheck disable=SC2001  # sed is more readable
        version="$(echo "$GITHUB_REF" | sed 's|refs\/tags\/||')"
    fi
fi

# data
# shellcheck disable=SC2154  # from env.sh
dat="$MOD_NAME.dat"
# shellcheck disable=SC2154  # from env.sh
mkdir -p "$MODS_DIR"

rm -rf data/text/po # gettext translations
# shellcheck disable=SC2154  # from env.sh
"$DAT3" a -c 9 -C data "$MODS_DIR/$dat" '*'

# sfall
# shellcheck disable=SC2154  # from env.sh
wget -q "$SFALL_URL" -O sfall.7z
7zr e sfall.7z ddraw.dll
zip -r "${MOD_NAME}_${version}.zip" ddraw.dll "$MODS_DIR/" # our package
