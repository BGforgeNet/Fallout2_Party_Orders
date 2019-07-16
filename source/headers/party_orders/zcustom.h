#ifndef ZCUSTOM_H
#define ZCUSTOM_H

// critter_state States //
#define CRITTER_IS_NORMAL (0)
#define CRITTER_IS_DEAD   (1)
#define CRITTER_IS_PRONE  (2)

/*   Item subtypes */
#define item_type_armor        (0)
#define item_type_container    (1)
#define item_type_drug         (2)
#define item_type_weapon       (3)
#define item_type_ammo         (4)
#define item_type_misc_item    (5)
#define item_type_key_item     (6)

/*   Item data_members   */
#define it_pid              (0)
#define it_name             (1)
#define it_description      (2)
#define it_fid              (3)
#define it_light_distance   (4)
#define it_light_intensity  (5)
#define it_flags            (6)
#define it_flags_ext        (7)
#define it_sid              (8)
#define it_type             (9)
#define it_data            (10)
#define it_material        (11)
#define it_size            (12)
#define it_weight          (13)
#define it_cost            (14)
#define it_inv_fid         (15)
#define it_weapon_range   (555)

// Trait defines //
#define TRAIT_PERK  	(0)
#define TRAIT_OBJECT (1)
#define TRAIT_TRAIT  (2)

// Object Trait Subtypes
#define OBJECT_AI_PACKET  (5)
#define OBJECT_TEAM_NUM   (6)
#define OBJECT_CUR_ROT    (10)
#define OBJECT_VISIBILITY (666)
#define OBJECT_CUR_WEIGHT (669)

//*  Critter Stats  *//
#define STAT_st              (0)
#define STAT_pe              (1)
#define STAT_en              (2)
#define STAT_ch              (3)
#define STAT_iq              (4)
#define STAT_ag              (5)
#define STAT_lu              (6)

#define STAT_max_hit_points     (7)
#define STAT_max_move_points    (8)
#define STAT_ac                 (9)
#define STAT_unused             (10)
#define STAT_melee_dmg          (11)
#define STAT_carry_amt          (12)
#define STAT_sequence           (13)
#define STAT_heal_rate          (14)
#define STAT_crit_chance        (15)
#define STAT_better_crit        (16)

#define STAT_dmg_thresh            (17)
#define STAT_dmg_thresh_laser      (18)
#define STAT_dmg_thresh_fire       (19)
#define STAT_dmg_thresh_plasma     (20)
#define STAT_dmg_thresh_electrical (21)
#define STAT_dmg_thresh_emp        (22)
#define STAT_dmg_thresh_explosion  (23)

#define STAT_dmg_resist            (24)
#define STAT_dmg_resist_laser      (25)
#define STAT_dmg_resist_fire       (26)
#define STAT_dmg_resist_plasma     (27)
#define STAT_dmg_resist_electrical (28)
#define STAT_dmg_resist_emp        (29)
#define STAT_dmg_resist_explosion  (30)
#define STAT_rad_resist            (31)
#define STAT_poison_resist         (32)
#define STAT_age                   (33)
#define STAT_gender                (34)
#define STAT_current_hp            (35)
#define STAT_current_poison        (36)
#define STAT_current_rad           (37)

#define SKILL_SMALL_GUNS                                                        (0)
#define SKILL_BIG_GUNS                                                          (1)
#define SKILL_ENERGY_WEAPONS                                                    (2)
#define SKILL_UNARMED_COMBAT                                                    (3)
#define SKILL_MELEE                                                             (4)
#define SKILL_THROWING                                                          (5)
#define SKILL_FIRST_AID                                                         (6)
#define SKILL_DOCTOR                                                            (7)
#define SKILL_SNEAK                                                             (8)
#define SKILL_LOCKPICK                                                          (9)
#define SKILL_STEAL                                                             (10)
#define SKILL_TRAPS                                                             (11)
#define SKILL_SCIENCE                                                           (12)
#define SKILL_REPAIR                                                            (13)
#define SKILL_CONVERSANT                                                        (14)
#define SKILL_BARTER                                                            (15)
#define SKILL_GAMBLING                                                          (16)
#define SKILL_OUTDOORSMAN                                                       (17)

/* Critical Table Flags */
#define DAM_KNOCKED_OUT        1
#define DAM_KNOCKED_DOWN       2
#define DAM_CRIP_LEG_LEFT      4
#define DAM_CRIP_LEG_RIGHT     8
#define DAM_CRIP_ARM_LEFT     16
#define DAM_CRIP_ARM_RIGHT    32
#define DAM_BLIND             64
#define DAM_DEAD             128
#define DAM_HIT              256
#define DAM_CRITICAL         512
#define DAM_ON_FIRE         1024
#define DAM_BYPASS          2048
#define DAM_EXPLODE         4096
#define DAM_DESTROY         8192
#define DAM_DROP           16384
#define DAM_LOSE_TURN      32768
#define DAM_HIT_SELF       65536
#define DAM_LOSE_AMMO     131072
#define DAM_DUD           262144
#define DAM_HURT_SELF     524288
#define DAM_RANDOM_HIT   1048576
#define DAM_CRIP_RANDOM  2097152
#define DAM_BACKWASH     4194304

#define DAM_CRIP_LEG		(DAM_CRIP_LEG_LEFT BWOR DAM_CRIP_LEG_RIGHT)
#define DAM_CRIP_ARM		(DAM_CRIP_ARM_LEFT BWOR DAM_CRIP_ARM_RIGHT)

#define DMG_normal_dam   0
#define DMG_laser        1
#define DMG_fire         2
#define DMG_plasma       3
#define DMG_electrical   4
#define DMG_emp          5
#define DMG_explosion    6
// These are BWOR'd into the above damage type
#define DMG_BYPASS_ARMOR  (256)
#define DMG_NOANIMATE     (512)

/* Critter Flags */
#define CFLG_BARTER			    2		//0x00000002 - Barter (can trade with)
#define CFLG_STEAL			   32		//0x00000020 - Steal (cannot steal from)
#define CFLG_DROP			   	64		//0x00000040 - Drop (doesn't drop items)
#define CFLG_LIMBS			  128		//0x00000080 - Limbs (can not lose limbs)
#define CFLG_AGES		  	  	  256		//0x00000100 - Ages (dead body does not disappear)
#define CFLG_HEAL			  	  512		//0x00000200 - Heal (damage is not cured with time)
#define CFLG_INVULN			 1024		//0x00000400 - Invulnerable (cannot be hurt)
#define CFLG_FLATTN			 2048		//0x00000800 - Flatten (leaves no dead body)
#define CFLG_SPECIAL			 4096		//0x00001000 - Special (there is a special type of death)
#define CFLG_RANGE			 8192		//0x00002000 - Range (melee attack is possible at a distance)
#define CFLG_KOCK				16384		//0x00004000 - Knock (cannot be knocked down)

// critter proto elements (offsets from PROTO file -12)
#define ce_cflag				(32)
#define ce_exp_val			(392)
#define ce_kill_type			(396)

/* Time Information  (in Ticks) */
#define ONE_GAME_SECOND             (10)
#define ONE_GAME_MINUTE             (60*ONE_GAME_SECOND)
#define ONE_GAME_HOUR               (60*ONE_GAME_MINUTE)
#define ONE_GAME_DAY                (24*ONE_GAME_HOUR)
#define ONE_GAME_WEEK               (7*ONE_GAME_DAY)
#define ONE_GAME_MONTH              (30*ONE_GAME_DAY)

// float_msg defines //
#define FLOAT_MSG_WARNING    (-2)
#define FLOAT_MSG_SEQUENTIAL (-1)
#define FLOAT_MSG_NORMAL      (0)
#define FLOAT_MSG_BLACK       (1)
#define FLOAT_MSG_RED         (2)
#define FLOAT_MSG_GREEN       (3)
#define FLOAT_MSG_BLUE        (4)
#define FLOAT_MSG_PURPLE      (5)
#define FLOAT_MSG_NEAR_WHITE  (6)
#define FLOAT_MSG_LIGHT_RED   (7)
#define FLOAT_MSG_YELLOW      (8)
#define FLOAT_MSG_WHITE       (9)
#define FLOAT_MSG_GREY       (10)
#define FLOAT_MSG_DARK_GREY  (11)
#define FLOAT_MSG_LIGHT_GREY (12)

#define face_critter(y,x)		anim(y,1000,rotation_to_tile(tile_num(y),tile_num(x)))
#define obj_get_rot(obj)		(has_trait(TRAIT_OBJECT, obj, OBJECT_CUR_ROT))
#define is_party_member(x)		party_member_obj(obj_pid(x))
#define not_party_member(x)	not(party_member_obj(obj_pid(x)))
#define is_armed(x)				(((obj_item_subtype(critter_inven_obj(x,1))) == item_type_weapon) or \
								((obj_item_subtype(critter_inven_obj(x,2))) == item_type_weapon))
#define is_injured(x)			(get_critter_stat(x, STAT_current_hp) < get_critter_stat(x, STAT_max_hit_points))
#define injured_how_much(x)	(get_critter_stat(x, STAT_max_hit_points) - get_critter_stat(x, STAT_current_hp))
#define current_hp_per(x)		\
	floor(get_critter_stat(x, STAT_current_hp) * 100/get_critter_stat(x, STAT_max_hit_points))

#define is_weapon(x)				(obj_item_subtype(x) == item_type_weapon)
// added by phobos2077:
#define is_ammo(x)						(obj_item_subtype(x) == item_type_ammo)
// end;

#define is_lootable(x)			not(get_proto_data(obj_pid(x),ce_cflag) BWAND CFLG_DROP) //(CFLG_STEAL+CFLG_DROP)?
#define set_non_lootable(x)		\
	set_proto_data(obj_pid(x),ce_cflag,(get_proto_data(obj_pid(x),ce_cflag) BWOR CFLG_DROP))

// Inventory Management stuff
#define max_carry(x)					get_critter_stat(x,STAT_carry_amt)
#define carry_amount(x)				has_trait(TRAIT_OBJECT, x, OBJECT_CUR_WEIGHT)
#define inven_free_amt(x)			(max_carry(x) - carry_amount(x))

// not an active item
#define item_not_active_pid(x)	not((x>=205)and(x<=210))
#define item_not_active(x)			item_not_active_pid(obj_pid(x))

// melee weapon with KO chance (club-like)
#define is_club_weapon_pid(x)	((x==5) or (x==20) or (x==384) or (x==386))
#define is_club_weapon(x)		is_club_weapon_pid(obj_pid(x))

// any unarmed (no rocks) or melee (no throwing) weapon
#define is_melee_weapon_pid(x)	(((x>=4) and (x<=7)) or (x==20) or (x==21) or (x==45) or (x==115) or 		\
								(x==116) or (x==160) or (x==234) or (x==235) or (x==236) or (x==280) or 	\
								(x==292) or (x==293) or (x==319) or (x==320) or (x==383) or (x==384) or 	\
								(x==386) or (x==399) or (x==407) or (x==496) or (x==497) or (x==517) or 	\
								(x==522) or (x==280) or (x==-1))
#define is_melee_weapon(x)		is_melee_weapon_pid(obj_pid(x))

// any equipable (no unarmed) weapon
#define droppable_weapon_pid(x)		(((x>=4) and (x<=13)) or (x==15) or (x==16) or (x==18) or (x==20) or 		\
									((x>=22) and (x<=28)) or (x==45) or (x==94) or (x==115) or (x==116) or 		\
									(x==118) or (x==120) or (x==122) or (x==143) or (x==159) or (x==160) or		\
									(x==161) or (x==162) or (x==233) or (x==236) or (x==241) or (x==242) or		\
									(x==261) or (x==268) or (x==280) or (x==287) or (x==296) or (x==299) or 	\
									(x==300) or (x==313) or (x==319) or (x==320) or (x==283) or (x==332) or 	\
									((x>=350) and (x<=355)) or ((x>=383) and (x<=406)) or (x==500) or 			\
									(x==517) or (x==522))
#define is_droppable_weapon(x)		droppable_weapon_pid(obj_pid(x))

#define not_armor_worn(x)		not(critter_inven_obj(x, 0))

#define attacker_behind_target(oA, oT)																			\
		((tile_distance(tile_num(oA),tile_behind_obj_rng(oT, 2))<=2) and (tile_distance_objs(oA,oT)<=2))
#define tile_behind_obj_rng(who, rng)																			\
		(tile_num_in_direction(tile_num(who),((has_trait(1,who,10) + 3) % 6), rng))


#define doctor_skill_higher(x)	(has_skill(x,SKILL_DOCTOR)>has_skill(x,SKILL_FIRST_AID))
#define medic_skill(x)			(has_skill(x,SKILL_FIRST_AID+doctor_skill_higher(x)))

#define melee_skill_higher(x)	(has_skill(x,SKILL_MELEE)>has_skill(x,SKILL_UNARMED_COMBAT))
#define hth_skill(x)			(has_skill(x,SKILL_UNARMED_COMBAT + melee_skill_higher(x)))

/* Sneak Attacks */
#define is_sneak_attack(oA, oT, oW)																				\
	(is_melee_weapon(oW) and ((using_skill(oA,SKILL_SNEAK) and attacker_behind_target(oA, oT)) or 				\
	is_critter_prone(oT)))
#define can_sneak_attack(x)			(has_skill(x,SKILL_SNEAK)>=50)
#define calc_sneak_damage_perc(x)	floor((hth_skill(x)* 0.5)+(has_skill(x,SKILL_SNEAK)* 1.5))

#endif

