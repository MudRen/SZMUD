// ɽ�� chaihu.c
// by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"ɽ��"NOR, ({"shanju"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����ɽ�ϵ�ɽ�գ�ҩ�ģ����\n");
		set("value", 120);
		set("yaocai", 1);
		set("cure_s",1);
		set("cure_d",3);
		set("cure_n",1);
	}
	setup();
}