// ľ�� muxiang.c
// by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"ľ��"NOR, ({"muxiang"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����ɽ�ϵ���ͨҩ�ġ�\n");
		set("value", 250);
		set("yaocai", 1);
		set("cure_s",1);
		set("cure_d",2);
		set("cure_n",1);
	}
	setup();
}