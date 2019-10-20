## Party Orders addon for Fallout 2

[![Translation status](https://tra.bgforge.net/widgets/fallout/-/party-orders/svg-badge.svg)](https://tra.bgforge.net/projects/fallout/party-orders/)
[![Build Status](https://travis-ci.org/BGforgeNet/Fallout2_Party_Orders.svg?branch=master)](https://travis-ci.org/BGforgeNet/Fallout2_Party_Orders)

[__Download__](https://github.com/BGforgeNet/Fallout2_Party_Orders/releases/latest)
 | [__Installation__](#installation)
 | [__Usage__](#usage)
 | [__Report issues__](https://github.com/BGforgeNet/Fallout2_Party_Orders/issues)

This mod allows to give orders to the companions using hotkeys.
It was originally written by [pelicano](http://www.nma-fallout.com/members/pelicano.55013/),
then expanded by [phobos2077](https://github.com/phobos2077/),
finally this version includes some [further fixes](doc/version_history.md).

Also see [mod thread](http://www.nma-fallout.com/threads/party-orders-add-on-and-npcs-loot-bodies-mod.190599/) on NMA
and its [wiki page](https://falloutmods.fandom.com/wiki/Party_Orders_add-on).
Notes for modders are [here](doc/modder_notes.md).

## Instalation
* Download the [latest release](https://github.com/BGforgeNet/fallout2-party-orders/releases/latest), unzip into Fallout 2 directory.
  Overwriting `ddraw.dll` is not necessary.

## Usage
Hotkeys are configured in `mods/party_orders.ini`. Default keys:
* F: Heal
* G: Loot
* H: Holster weapon
* R: Regroup
* X: Scatter
* T: (Dude) Pick up items or auto-loot bodies
* 0: Switch behavior of T key between pick up items and loot bodies
* Ctrl-B: Switch ammo type (AP/JHP)
* D: Allow/forbid party members to use burst attacks. Forbidden by default.
When allowed, it doesn't mean that they will always use burst, only that they *may*.
However, if equipped with a weapon which has only burst mode, such as a minigun, this order will be ignored by this particular party member.
