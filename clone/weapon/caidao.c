// Code of ShenZhou
// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�˵�", ({ "cai dao", "dao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����������ķ����˵���\n");
		set("value", 30);
		set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/caidao.c");
//***** END OF ADDING *****
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
	init_blade(3);
	setup();
}
