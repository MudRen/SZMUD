// Code of ShenZhou
// gangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("��ս�", ({ "qinggang jian", "jian", "sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ɵĳ����������Ϸ�����ɫ�Ĺ�ã��\n");
		set("value", 400);
		set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/qinggang-jian.c");
//***** END OF ADDING *****
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(120);
	setup();
}