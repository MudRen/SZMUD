// Code of ShenZhou
// bamboo_stick.c

#include <ansi.h>
#include <weapon.h>
//#include "/clone/unique/special_weapon.h"
inherit F_UNIQUE;

inherit STICK;

void create()
{
	set_name(HIG"�򹷰�"NOR, ({"dagou bang", "bang", "stick"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIG"һ��������������������\n"NOR);
		set("value", 8000000);
		set("material", "bamboo");
		set("rigidity", 3000);
		set("wield_msg", "$N���һ�����������������ץ�����С�\n");
		set("unwield_msg", "$N�����еĴ򹷰�������С�\n");
	}
	init_stick(130);
	setup();
	::create();
}	
