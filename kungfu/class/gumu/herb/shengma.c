// ���� shengma.c
// by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"����"NOR, ({"shengma"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����ɽ�ϵ���ͨҩ�ġ�\n");
		set("value", 180);
		set("yaocai", 1);
		set("cure_s",1);
		set("cure_d",1);
		set("cure_n",2);
	}
	setup();
}