// Code of ShenZhou
// gangbang.c �ְ�
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("�ְ�", ({ "gang bang", "bang" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ִ���ĳ�����\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/gangbang.c");
//***** END OF ADDING *****
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(25);
        setup();
}
