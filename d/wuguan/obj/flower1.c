//Created by Zyu on k1-08-11
// Object: /d/wuguan/obj/flower.c
#include <ansi.h>
inherit COMBINED_ITEM;
inherit F_COMMAND;

void create()
{
	int clr = random(13) + 1;

	if ( clr==1 ) set_name(RED"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==2 ) set_name(HIR"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==3 ) set_name(GRN"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==4 ) set_name(HIG"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==5 ) set_name(YEL"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==6 ) set_name(HIY"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==7 ) set_name(BLU"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==8 ) set_name(HIB"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==9 ) set_name(MAG"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==10 ) set_name(HIM"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==11 ) set_name(CYN"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==12 ) set_name(HIC"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==13 ) set_name(WHT"野花"NOR, ({"wide flower", "ye hua", "hua"}));
	else set_name(HIW"野花"NOR, ({"wide flower", "ye hua", "hua"}));

	if (clonep())
	set_default_object(__FILE__);
	else {
		set("unit", "束");
		set("base_unit","朵");
		set("long", "这是花园里随处可见的野花。\n");
		set("value", 0);
	}

	set_amount(1+random(2));
	set("no_get", "保护环境，人人有责！\n");

	setup();
}
