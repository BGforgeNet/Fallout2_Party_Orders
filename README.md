# Party Orders addon for Fallout 2

[![Build status](https://github.com/BGforgeNet/Fallout2_Party_Orders/actions/workflows/build.yml/badge.svg)](https://github.com/BGforgeNet/Fallout2_Party_Orders/actions/workflows/build.yml)
[![Translation status](https://hive.bgforge.net/widgets/fallout/-/party-orders/svg-badge.svg)](https://hive.bgforge.net/projects/fallout/party-orders/)

[![Telegram](https://img.shields.io/badge/telegram-join%20%20%20%20%E2%9D%B1%E2%9D%B1%E2%9D%B1-darkorange?logo=telegram)](https://t.me/bgforge)
[![Discord](https://img.shields.io/discord/420268540700917760?logo=discord&label=discord&color=blue&logoColor=FEE75C)](https://discord.gg/4Yqfggm)
[![IRC](https://img.shields.io/badge/%23IRC-join%20%20%20%20%E2%9D%B1%E2%9D%B1%E2%9D%B1-darkorange)](https://bgforge.net/irc)

[**Download**](https://github.com/BGforgeNet/Fallout2_Party_Orders/releases/latest)
| [**Installation**](#installation)
| [**Usage**](#usage)
| [**Bug reports**](#bug-reports-feature-requests)

This mod allows to give orders to the companions using hotkeys.
It was originally written by [pelicano](https://www.nma-fallout.com/members/pelicano.55013/),
then expanded by [phobos2077](https://github.com/phobos2077/),
finally this version includes some [further fixes](docs/changelog.md).

Also see [mod thread](https://www.nma-fallout.com/threads/party-orders-add-on-and-npcs-loot-bodies-mod.190599/) on NMA
and its [wiki page](https://falloutmods.fandom.com/wiki/Party_Orders_add-on).
Notes for modders are [here](docs/modder_notes.md).

## Installation

- Download the [latest release](https://github.com/BGforgeNet/Fallout2_Party_Orders/releases/latest), unzip into Fallout 2 directory.
  Overwriting `ddraw.dll` is not necessary.

## Usage

Hotkeys are configured in `mods/party_orders.ini`. Default keys:

- F: Heal
- G: Loot
- H: Holster weapon
- R: Regroup
- X: Scatter
- T: (Dude) Pick up items or auto-loot bodies
- 0: Switch behavior of T key between pick up items and loot bodies
- Ctrl-B: Switch ammo type (AP/JHP)
- D: Allow/forbid party members to use burst attacks.
  - When allowed, it doesn't mean that they will always use burst, only that they _may_.
  - However, if equipped with a weapon which has only burst mode, such as a minigun, this order will be ignored by this particular party member.

## Bug reports, feature requests

Go to [github issues](https://github.com/BGforgeNet/Fallout2_Party_Orders/issues) or [forums](https://forums.bgforge.net/viewforum.php?f=34).

## Additional info

[**Changelog**](docs/changelog.md)
