// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("ذ��", ({ "bishou", "dagger" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"����һ����ͨ�ľ���ذ�ס�\n");
                set("value", 250);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ػ��\n");
        }
        init_sword(5);
        setup();
}










