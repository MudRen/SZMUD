// 土茯苓 tufuling.c
// by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"土茯苓"NOR, ({"tufuling"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "两");
		set("long","草本植物，补气血，润五脏，是不可多得的上佳药材。\n");
		set("value", 8000);
		set("yaocai", 1);
		set("cure_s",30);
		set("cure_d",20);
		set("cure_n",40);
	}
	setup();
}