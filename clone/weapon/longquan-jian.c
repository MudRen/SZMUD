// Code of ShenZhou
//��Ȫ��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC"��Ȫ��"NOR, ({ "longquan jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "�����Ȫ�������ɺ��˷��ƣ�Զ�������Ϲ��������Ҳ�ǿ�������\n");
		set("value", 10000);
                set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���뽣�ʡ�\n");
        }
	init_sword(44);
        setup();
}
