// Code of ShenZhou
// shuanggou.c ˫��

#include <ansi.h>
#include <weapon.h>
inherit HOOK;

void create()
{
	set_name(HIW"˫��"NOR, ({ "shuang gou", "gou","hook" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ĸֹ�����һ����������\n");
		set("value", 250);
		set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/hook.c");
//***** END OF ADDING *****
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
	}
	init_hook(35);
	setup();
}
