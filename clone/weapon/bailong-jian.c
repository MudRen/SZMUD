// Code of ShenZhou
//������
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"������"NOR, ({ "bailong jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ�Ѻ������˵ı��������н�֮һ�㳤���ƺ�Ҫ�Գ�һЩ��\n");
		set("value", 1000);
                set("material", "steel");
		set("wield_msg","$N�����һ�����죬�Ѱγ�һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n��ৡ���һ����ؽ��ʡ�\n");
        }
	init_sword(45+random(11));
        setup();
	::create();
}
