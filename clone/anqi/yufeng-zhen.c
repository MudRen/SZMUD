// yufeng-zhen.c 古墓玉蜂针
// by April 2001.09.28

#include <ansi.h>
#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

void create()
{
	set_name("玉蜂针", ({ "yufeng zhen", "zhen", "needle" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枚细如牛毛的金针，针尖散发着异样的光芒。\n");
		set("unit", "簇");
		set("base_unit", "枚");
		set("value", 0);
		set("damage", 5);
		set("armor_type", "embed");
		set("armor_prop/armor",1);
		set("armor_prop/attack", -30);
		set("armor_prop/defense", -30);
		set("armor_prop/unarmed", -30);
		set("no_sell", 1);
		set("unequip_msg", HIR"$N一咬牙将$n从伤口上拔了下来，一股鲜血猛地涌了出来。\n"NOR);
	}
	set_amount(15);
	setup();
}

int wear() { return 0; }

int do_embed()
{
	::wear();
	set("no_drop", 1);
	set("no_get", 1);
	environment()->apply_condition("embedded", 100);
	environment()->apply_condition("yf_zhen_poison", 20);
	return 1;
}

int unequip()
{
	::unequip();
	set("no_drop", 0);
	set("no_get", 0);
	set("embedded", 0);
	environment()->apply_condition("embedded", 0);
	environment()->receive_damage("qi", 200+random(1000));
	return 1;
}

string query_autoload() 
{ 
	if( query("equipped") )
	return query_amount() + ""; 
}

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
	set("embedded", 1);
	set("no_drop", 1);
	set("no_get", 1);
	::wear();
}
