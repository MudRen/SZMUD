//Cracked by Roath
// caidao2.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("�˵�", ({ "cai dao", "dao" }));
        set_color("$HIW$");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������ķ����˵���\n");
                set("value", 60);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������\n");
        }
        init_blade(6);
        setup();
}
