// Code of ShenZhou
// weapon: banfu.c �師
// qfy August 19, 1996.

#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(HIW"�師"NOR, ({ "banfu", "fu", "axe" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѽ���ɱ�����İ師�����λεķ���֮����\n");
                set("value", 300);
                set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/banfu.c");
//***** END OF ADDING *****
                set("wield_msg", "$N˫������$n��\n");
                set("unwield_msg", "$N����$n��\n");
        }
        init_axe(30);
        setup();
}

