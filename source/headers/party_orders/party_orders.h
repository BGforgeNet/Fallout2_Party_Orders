// offsets for get_proto_data
#define PRODATA_PID             (1)
#define PRODATA_TEXTID          (4)

// items
#define PRODATA_IT_FLAGS       (24)
#define PRODATA_IT_TYPE        (32)
#define PRODATA_IT_MATERIAL   (108)
#define PRODATA_IT_SIZE       (112)
#define PRODATA_IT_WEIGHT     (116)
#define PRODATA_IT_COST       (120)

// weapons
#define PRODATA_IT_WP_DMG_MIN     (40)
#define PRODATA_IT_WP_DMG_MAX     (44)
#define PRODATA_IT_WP_RANGE_MIN   (52)
#define PRODATA_IT_WP_RANGE_MAX   (56)
#define PRODATA_IT_WP_MIN_ST      (64)
#define PRODATA_IT_WP_APCOST_1    (68)
#define PRODATA_IT_WP_APCOST_2    (72)
#define PRODATA_IT_WP_BURST       (84)
#define PRODATA_IT_WP_CALIBER     (88)
#define PRODATA_IT_WP_AMMO_PID    (92)
#define PRODATA_IT_WP_MAG_SIZE    (96)
#define PRODATA_IT_WP_ANIM        (36)

// armor
#define PRODATA_IT_AR_AC          (36)
#define PRODATA_IT_AR_DR_NORMAL    (40)
#define PRODATA_IT_AR_DR_LASER     (44)
#define PRODATA_IT_AR_DR_FIRE      (48)
#define PRODATA_IT_AR_DR_PLASMA    (52)
#define PRODATA_IT_AR_DR_ELECTRICAL   (56)
#define PRODATA_IT_AR_DR_EMP       (60)
#define PRODATA_IT_AR_DR_EXPLOSION (64)
#define PRODATA_IT_AR_DT_NORMAL    (68)
#define PRODATA_IT_AR_DT_LASER     (72)
#define PRODATA_IT_AR_DT_FIRE      (76)
#define PRODATA_IT_AR_DT_PLASMA    (80)
#define PRODATA_IT_AR_DT_ELECTRICAL   (84)
#define PRODATA_IT_AR_DT_EMP       (88)
#define PRODATA_IT_AR_DT_EXPLOSION (92)

// ammo
#define PRODATA_IT_AM_CALIBER      (36)
#define PRODATA_IT_AM_PACK_SIZE    (40)
#define PRODATA_IT_AM_AC_MOD       (44)
#define PRODATA_IT_AM_DR_MOD       (48)
#define PRODATA_IT_AM_DMG_MULT     (52)
#define PRODATA_IT_AM_DMG_DIV      (56)

// critters
#define PRODATA_CR_CRITTER_FLAGS  (32)
#define PRODATA_CR_KILL_EXP   (392)
#define PRODATA_CR_KILL_TYPE  (396)

#define actual_ammo_count(crit, obj)   ((obj_is_carrying_obj_pid(crit, obj_pid(obj)) - 1)*get_proto_data(obj_pid(obj), PRODATA_IT_AM_PACK_SIZE) + get_weapon_ammo_count(obj))

procedure set_item_count(variable invenobj, variable item, variable newcount)
begin
	variable begin
		count;
		newitem;
	end
	count := obj_is_carrying_obj_pid(invenobj, obj_pid(item));
	if (newcount > count) then begin
		newitem := create_object_sid(obj_pid(item), 0, 0, -1);
		add_mult_objs_to_inven(invenobj, newitem, newcount - count);
	end else if (newcount < count) then begin
		count := rm_mult_objs_from_inven(invenobj, item, count - newcount);
		destroy_object(item);
	end
end

procedure set_actual_ammo_count(variable invenobj, variable item, variable newcount)
begin
	variable count;
	variable packsize;

	if (newcount < 0) then newcount := 0;
	packsize := get_proto_data(obj_pid(item), PRODATA_IT_AM_PACK_SIZE);
	call set_item_count(invenobj, item, ceil(1.0 * newcount / packsize));
	// if number of items reduced, object reference will be different
	item := obj_carrying_pid_obj(invenobj, obj_pid(item));
	if (item and newcount % packsize > 0) then set_weapon_ammo_count(item, newcount % packsize);
end

// change ammo amount by certain value
procedure inc_ammo_count(variable invenobj, variable ammopid, variable inc)
begin
	variable item;
	item := obj_carrying_pid_obj(invenobj, ammopid);
	if (item == 0) then begin
		item := create_object_sid(ammopid, 0, 0, -1);
    	add_obj_to_inven(invenobj, item);
    end
    call set_actual_ammo_count(invenobj, item, actual_ammo_count(invenobj, item) + inc);
end

