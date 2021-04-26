// Code of ShenZhou
// stick.c

#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
	set_name("ľ��", ({ "mu bang", "bang", "walking stick", "stick" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ľ�������Ե�����ɽ�õ����ȡ�\n");
		set("value", 50);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_stick(5);
	setup();
}
