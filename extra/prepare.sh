#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
mkdir -p "$BIN_DIR"

# sslc compiler
# shellcheck disable=SC2154  # from env.sh
if [[ ! -f "$COMPILE" ]]; then
    wget -q "$SSLC_URL" -O "$COMPILE"
    chmod +x "$COMPILE"
fi

# dat3 packer
# shellcheck disable=SC2154  # from env.sh
if [[ ! -f "$DAT3" ]]; then
    wget -q "$DAT3_URL" -O "$DAT3"
    chmod +x "$DAT3"
fi

# sfall
# shellcheck disable=SC2154  # from env.sh
if [[ ! -f "$SFALL_7Z" ]]; then
    mkdir -p "$DOWNLOADS_DIR"
    # Through a temporary name, so an interrupted download is never taken for a complete one.
    wget -nv "$SFALL_URL" -O "$SFALL_7Z.part"
    mv "$SFALL_7Z.part" "$SFALL_7Z"
fi
