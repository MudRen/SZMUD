// Code of ShenZhou
// shortsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�̽�", ({ "duanjian", "jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ľ��ֽ���һ��Ľ��Ͷ�����˽���\n");
		set("value", 150);
		set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/duanjian.c");
//***** END OF ADDING *****
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(15);
	setup();
}