// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("����", ({ "zhubian", "basket" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ϸ�����ҡ�\n");
                set("value", 200);
                set("material", "steel");
        }
        init_blade(8);
        setup();
}


