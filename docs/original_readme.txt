Party Orders add-on for [(sfall v2.0) Fallout 2 v1.02 US] by pelicano

Version 1.0d





Summary of HotKeys:



F: Heal

G: Loot

H: Holster weapon

R: Regroup

X: Scatter



T: (Dude) Pick up items or auto-loot Bodies



0: Switch behavior of T key between Pick up items and Loot Bodies



Introduction

-------------



This is just a little script add-on that will allow the player to give common orders to party members on the 'fly', using keyboard hotkeys, in any given moment outside combat mode. This add-on can be configured through the "party_op.ini" file.





Compatibility

--------------



This add-on should be compatible with any fo2 modification. For reference, this mod uses the following sfall globals:



"p_looter"

"p_corpse"

"p_gitem0"

"p_opti01"





Installation

-------------



- Extract the contents to fallout2's root directory. "party_op.ini" must be in the same directory as fallout2.exe and "GL_ptyop.int" in the DATA\scripts directory.





- sfall (v2.0 or newer) is required. This add-on uses sfall's script features and global scripts. Make sure Input is enabled and script Extender is set to 1 in "ddraw.ini". Both options are enabled by default. Last sfall version can be downloaded from http://sourceforge.net/projects/sfall





Instructions

-------------



As soon as Party Orders add-on is installed, the player can give orders to the party and any member will follow it if s/he's able. All order's hotkeys are configurable via "party_op.ini". 



The following orders are currently implemented:



- Heal yourself ([F] key): Any party member injured with more that 10 hit points of damage will attempt to heal herself. If heavily injured s/he'll use(*) a super stimpak. If s/he doesn't carry any or if s/he's under 75% total hitpoints s/he'll attempt to heal the wounds using her/his medic skills (first aid or doctor, whichever is higher). Finally, if s/he's still injured s/he will use(*) any stimpak s/he may have. In combat mode only (super) stimpaks will be used. Only a healing order per turn.



- Holster weapons ([H] key): Any armed party member will put her/his weapon away immediately.



- Regroup party ([R] key): Any party member away more than 2 hexes from the PC will regroup next to the PC



- Loot bodies ([G] key): The party member with the most carry capacity will go and try to loot the corpses near her/him and the PC. s/he will pick up any item near bodies (up to 3 hexes) as well (**). If the loot bodies hotkey [G] is pressed again while a party member is looting, this will cancel the loot order, calling back the party member. If the dude PC is looting (following [T] order) when the [G] order is issued the PC will cancel the looting and the NPC will continue, if s/he is able.





- (v1.0c). PC pick up nearby items ([T] key(***)): Uppon pressing the T key your PC will pick up from the ground nearby items (in a 3 hex radius). Used only for convinience. The dude PC will stop picking up stuff whenever combat starts, s/he can't carry more stuff or there are no more items to pick up.



- NEW (v1.0d). Scatter party ([X] key): Party members within 5 hex radius from the PC will run 4-6 tiles away, causing the party to spread out. NPCs with the default distance settings to follow_close will run back almost immediately, though. Also, don't expect cleverness from NPCs, specially if the destination is blocked.



- NEW (v1.0d). PC loot bodies ([T] key(***)): The dude PC will attemp to loot bodies automatically as the NPCs. Only one member of the party (NPC or dude) may loot bodies at a time. Using this order while an NPC is already looting will cause the callback of the NPC, the dude PC resuming the looting if s/he is able. To stop the dude and cancel the order, press again [T].



(*): sfall global scripts doesn't seem to like the function use_obj_on_obj() and/or I've not been able to make it work properly so I've 'emulated' the use of super and regular stimpaks. That means that if a mod changes the behavior of those two items, this add-on will not note the difference and will still use the scripted (vanilla) version of the stimpaks. No big deal.



(**): This option can be turned on and off in the "party_op.ini" file (PLootNearbyItems=1).



(***): The 0 key (main keyboard) changes the functionality of the [T] order. When the auto-loot option is OFF, the [T] order causes the PC to pick up nearby items.





Important Notes

----------------



- There is a little delay between orders that depends on the last order given. Vary from 1 to 5 seconds.



- When a party member is away looting bodies s/he's temporary removed from the party to avoid the regular distance bounds with the PC. So DO NOT initiate dialogue with that party member or change area while the party member is looting. If you have to do so then press again the looting hotkey (default G) to cancel the loot order, or wait until the looting is done. Also, if there's a body the npc can't reach you may have to cancel the loot order yourself. Always make sure if an npc is done with looting or not to avoid losing party members in the wasteland, or worse.



- Only non overloaded party members can follow the loot bodies order.



- Once a party member starts looting bodies, s/he will not stop until there are no more bodies in her/or dude's range, combat starts or the PC cancels the loot order.



- If PLootNearbyItems is set to 1 (pick up items next to corpses), the party member will not pick up stuff heavier than what s/he can carry. If s/he found a corpse with a heavy inventory, s/he will drop all the stuff to the ground and will pick up only what s/he can carry. If PLootNearbyItems is set to 0, then the party member will loot every body regardless of the inventory weight, but will not pick up items.



- In the "party_op.ini" file there are two lists with party member PIDs. The first list, [NPC], contains all the possible party members that will try to follow all the PC's orders (if they are currently in the party) with the exception of Loot Bodies. The second list, [LOOTER], contains the PIDs of the possible party members that will be checked when the loot order is given.



- The source code is provided to be revised, modified, whatever. It's a fairly simple script which can be modified easily to suit any mod or whim if needed. Hopefully the script's comments will be helpful.





How to Uninstall

-----------------



- Simply delete the files "party_op.ini" and "GL_ptyop.int" from the fallout2 directory and DATA\scripts directory, respectively.





Acknowledgements

-----------------



- Timeslip: for the creation of sfall. Without Timeslip's sfall, this add-on wouldn't be possible.

- Nirran: for his mods and, more importantly, the source coded provided with them (I actually don't use his mods ;P), which encouraged me to start scripting fallout 2 again after so many years.

- The fallout modding community in general: for the endless support to the fallout games through the years, despite the darkest fallout times...





That is all. To contact me for whatever reason send me (pelicano) a PM at No Mutants Allowed Forums. Enjoy.





- pelicano -







Version History

----------------

v1.0d

- Added Scatter Order [X]. Party members within 5 hexes from the PC will run 4-6 tiles away.

- Added the option for the PC to auto-loot bodies [T]. Can be turned on/off pressing "0".

- Minor changes in the code. Now looters provides feedback if they can't loot everything.

- Fixed an irrelevant bug. Oh well.



v1.0c

- Added a pick up key for the dude PC. Uppon pressing "T" the PC dude will pick up items from the ground in a 3 hex radius.

- Added support for three party members from Killap's Restoration Project Mod v2.0 (hopefully).



v1.0b

- Minor change: now all the speech text is out in the ini file to allow a complete translation of the add-on for localized versions, including names of party members.





v1.0a



- Made it possible to use the healing command while in combat, once per turn. Only (super) stimpaks will be used in combat mode, not healing skills.



v1.0



- Initial version.