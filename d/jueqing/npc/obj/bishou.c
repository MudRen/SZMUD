// jiuer 09.15.2001

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
"����һ��ССذ�ף������������ۺ˰��С��һ�����ӣ��������Ө�⡣\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ػ��\n");
        }
        init_sword(5);
        setup();
}










