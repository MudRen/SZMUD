// Code of ShenZhou
//��ˮ��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIG"��ˮ��"NOR, ({ "bishui jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ��������ˮ�ı�����������һ�ڶϽ�������������\n");
		set("value", 10000);
                set("material", "steel");
		set("wield_msg", "$N����һЦ�����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
	init_sword(45+random(11));
        setup();
	::create();
}
