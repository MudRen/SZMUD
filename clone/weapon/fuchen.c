// Code of ShenZhou
// Jay May 27, 96

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("����", ({ "fuchen" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������������ϸ���Ǻ������ı�����\n");
                set("value", 500);
                set("material", "leather");
		set("rigidity", 100000);
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/fuchen.c");
//***** END OF ADDING *****
                set("wield_msg", "$N��ৡ���һ���Ӿ��г��һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؾ��С�\n");
        }
        init_whip(30);
        setup();
}

