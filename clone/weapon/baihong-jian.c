// Code of ShenZhou
//�׺罣
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"�׺罣"NOR, ({ "baihong jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ�Ѻ������˵ı��������н�֮һ�㳤���ƺ�Ҫ�Գ�һЩ��\n");
		set("value", 1000);
                set("material", "steel");

//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/baihong-jian.c");
//***** END OF ADDING *****

		set("wield_msg","$N�����һ�����죬�Ѱγ�һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n��ৡ���һ����ؽ��ʡ�\n");
        }
	init_sword(52);
        setup();
}
