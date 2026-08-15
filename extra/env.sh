#!/bin/bash

set -xeu -o pipefail

extra_dir="$(realpath extra)"
export extra_dir
export bin_dir="$extra_dir/bin"
export mods_dir="mods"
export sfall_version=${sfall_version:-4.5}
export mod_name=party_orders

SSLC_VERSION="2026-05-23-12-48-08"
export SSLC_URL="https://github.com/sfall-team/sslc/releases/download/${SSLC_VERSION}/sslc-linux"
export COMPILE="$bin_dir/sslc"

DAT3_VERSION="v0.8.0"
export DAT3_URL="https://github.com/BGforgeNet/dat3/releases/download/${DAT3_VERSION}/dat3"
export DAT3="$bin_dir/dat3"

set +xeu +o pipefail

# git magic to clone a subdirectory, for faster build
function git-clone-dir() {
    url="$1"
    dir="$2"
    subdir="$3"

    git clone -n --depth=1 --filter=tree:0 "$url" "$dir"
    pushd .
    cd "$dir"
    git sparse-checkout set --no-cone "$subdir"
    git checkout
    popd
}
export -f git-clone-dir
