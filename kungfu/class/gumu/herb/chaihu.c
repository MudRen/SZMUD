//��� chaihu.c
//Blacko /2001/9
// update by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"���"NOR, ({"chaihu"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����ɽ�ϲ�������ͨҩ�ġ�\n");
		set("value", 80);
		set("yaocai", 1);
		set("cure_s",2);
		set("cure_d",1);
		set("cure_n",1);
	}
	setup();
}