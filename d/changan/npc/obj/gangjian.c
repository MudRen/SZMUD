// Code of ShenZhou
// gangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "/clone/weapon/edge_weapon.h"
void create()
{
	set_name("�ֽ�", ({ "gangjian", "jian", "sword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ƴɵĸֽ������ֽ��ڽ���֮��ǳ����С�\n");
		set("value", 300);
		set("material", "steel");
//***** ADDED BY SCATTER *****
                                set("wposition", "/d/city/npc/obj/gangjian.c");
//***** END OF ADDING *****
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(25);
	setup();
}
