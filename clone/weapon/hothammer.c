// Code of ShenZhou
// hammer.c

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("�պ������", ({ "hot hammer" }) );
        set_color("$RED$");
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص�������������൱��ʵ��\n");
		set("value", 250);
		set("material", "iron");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/hothammer.c");
//***** END OF ADDING *****
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

        init_hammer(25);
	setup();
}
