#!/bin/bash

set -xeu -o pipefail

# Constants are deliberately not readonly: this file is meant to be sourced, and a second source in the same shell
# would abort on the re-assignment.
EXTRA_DIR="$(realpath extra)"
export BIN_DIR="$EXTRA_DIR/bin"
export MODS_DIR="mods"
export MOD_NAME=party_orders

SSLC_VERSION="2026-09-17-13-26-18"
export SSLC_URL="https://github.com/sfall-team/sslc/releases/download/${SSLC_VERSION}/sslc-linux"
export COMPILE="$BIN_DIR/sslc"

DAT3_VERSION="v0.11.1"
export DAT3_URL="https://github.com/BGforgeNet/dat3/releases/download/${DAT3_VERSION}/dat3"
export DAT3="$BIN_DIR/dat3"
# zlib level for every .dat: 6 packs in under half the time of 9, for archives about 1% larger.
export DAT3_LEVEL=6

SFALL_VERSION="4.5.1"
export SFALL_URL="https://sourceforge.net/projects/sfall/files/sfall/sfall_${SFALL_VERSION}.7z/download"
# Release archives, fetched only when missing; CI caches this directory.
export DOWNLOADS_DIR="$EXTRA_DIR/downloads"
export SFALL_7Z="$DOWNLOADS_DIR/sfall_$SFALL_VERSION.7z"

# Header sources fetched by buildall.sh, each pinned to a commit or tag so a build is reproducible.
export RP_HEADERS_REF="8cfc4a09de10338fafcb8c2c987e23239f3d5c82"
export FO2TWEAKS_HEADERS_REF="6c9172a0ac566f4972700803835630c2ed2ff810"
export SFALL_HEADERS_REF="v${SFALL_VERSION}"

set +xeu +o pipefail

# Sparse, shallow checkout of one subdirectory at a pinned commit or tag. A checkout whose HEAD is already the pin
# is reused; anything else is fetched afresh.
function git-clone-dir() {
    local url="$1"
    local dir="$2"
    local subdir="$3"
    local ref="$4"
    local pin="refs/pins/$ref"

    if [[ -d "$dir" && "$(git -C "$dir" rev-parse HEAD)" == "$(git -C "$dir" rev-parse -q --verify "$pin^{commit}")" ]]; then
        return
    fi
    rm -rf "$dir"
    git init -q "$dir"
    git -C "$dir" remote add origin "$url"
    git -C "$dir" sparse-checkout set --no-cone "$subdir"
    git -C "$dir" fetch -q --depth=1 --filter=tree:0 origin "$ref:$pin"
    git -C "$dir" checkout -q "$pin"
}
export -f git-clone-dir
