// Code of ShenZhou
// kandao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
#include "/clone/weapon/edge_weapon.h"

void create()
{
	set_name("����", ({ "kan dao", "dao" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��С�����������Ŀ�û�л��֣���С������ǰ����һ�ع����ʺ�������ľ֦����\n");
		set("value", 250);
		set("material", "steel");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
        }
	init_blade(10);
	setup();
}
