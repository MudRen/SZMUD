// Code of ShenZhou
// gangdao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�ֵ�", ({ "blade", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λεĸֵ�����ͨ�ٱ��ĳ���������\n");
		set("value", 200);
		set("material", "steel");

//***** ADDED BY SCATTER *****
                                set("wposition", "/d/city/npc/obj/gangdao.c");
//***** END OF ADDING *****

		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(25);
	setup();
}