// Code of ShenZhou
// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name(HIG"Ұ������"NOR, ({"soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������Ұ����������\n");
                set("unit", "��");
                set("value", 0);
        set("max_liquid", 4);
    }


    set("liquid", ([
        "type": "water",
        "name": "Ұ����",
        "remaining": 6,
        "drunk_supply": 15,
    ]));
}
