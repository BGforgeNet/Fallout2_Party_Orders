#!/bin/bash

set -xeu -o pipefail

src="$(realpath source)"
headers_dir="$src/headers"
dst="data/scripts"
mkdir -p "$dst"
dst="$(realpath $dst)"

mkdir -p external
cd external

if [[ -d rp ]]; then
    cd rp
    git pull
    cd ..
else
    git-clone-dir https://github.com/BGforgeNet/Fallout2_Restoration_Project.git rp scripts_src/headers
fi

if [[ -d fo2tweaks ]]; then
    cd fo2tweaks
    git pull
    cd ..
else
    git-clone-dir https://github.com/BGforgeNet/FO2tweaks.git fo2tweaks source/headers
fi

if [[ -d sfall ]]; then
    cd sfall
    git pull
    cd ..
else
    git-clone-dir https://github.com/sfall-team/sfall.git sfall artifacts/scripting/headers
fi

cd ..

# The dependency headers include each other by relative path ("../sfall/sfall.h"), which POSIX resolves
# through a symlink into the clone tree instead of lexically. So these have to be real sibling
# directories - symlinks only ever worked because wine normalized ".." the Windows way.
rm -rf "$headers_dir/rp" "$headers_dir/sfall" "$headers_dir/fo2tweaks"
cp -r external/rp/scripts_src/headers "$headers_dir/rp"
cp -r external/sfall/artifacts/scripting/headers "$headers_dir/sfall"
cp -r external/fo2tweaks/source/headers/fo2tweaks "$headers_dir/fo2tweaks"

cd "$src"
# shellcheck disable=SC2154  # from env.sh
"$COMPILE" -l -O2 -p -s -q -n gl_p_party_orders.ssl -o "$dst/gl_p_party_orders.int"
