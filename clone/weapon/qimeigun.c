// Code of ShenZhou
// qimeigun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("��ü��", ({ "qimei gun", "gun" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ����ľ���������ٿ���ü�����غ��ˣ��ɹ�����Ƭ���ˡ�\n");
                set("value", 150);
                set("material", "wood");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
		set("shaolin",1);
        }
        init_club(15);
        setup();
}

