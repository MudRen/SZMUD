// Code of ShenZhou
// longsword.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("����", ({ "changjian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ľ��ֽ���һ��Ľ��Ͷ�����˽���\n");
		set("value", 250);
		set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/changjian.c");
//***** END OF ADDING *****
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(15);
	setup();
}