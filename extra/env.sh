#!/bin/bash

set -xeu -o pipefail

# Constants are deliberately not readonly: this file is meant to be sourced, and a second source in the same shell
# would abort on the re-assignment.
EXTRA_DIR="$(realpath extra)"
export BIN_DIR="$EXTRA_DIR/bin"
export MODS_DIR="mods"
export MOD_NAME=party_orders

SSLC_VERSION="2026-05-23-12-48-08"
export SSLC_URL="https://github.com/sfall-team/sslc/releases/download/${SSLC_VERSION}/sslc-linux"
export COMPILE="$BIN_DIR/sslc"

DAT3_VERSION="v0.8.0"
export DAT3_URL="https://github.com/BGforgeNet/dat3/releases/download/${DAT3_VERSION}/dat3"
export DAT3="$BIN_DIR/dat3"

SFALL_VERSION="4.5"
export SFALL_URL="https://sourceforge.net/projects/sfall/files/sfall/sfall_${SFALL_VERSION}.7z/download"

set +xeu +o pipefail

# git magic to clone a subdirectory, for faster build
function git-clone-dir() {
    local url="$1"
    local dir="$2"
    local subdir="$3"

    git clone -n --depth=1 --filter=tree:0 "$url" "$dir"
    pushd .
    cd "$dir"
    git sparse-checkout set --no-cone "$subdir"
    git checkout
    popd
}
export -f git-clone-dir
