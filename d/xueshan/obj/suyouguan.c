// Code of ShenZhou
// /d/xueshan/obj/suyouguan.c
//su you guan


#include <ansi.h>

inherit ITEM;
inherit "/d/xueshan/inherit/liquid_container.c";


void create()
{
		object suyou;

        set_name("���͹�", ({"suyou guan", "guan", "bottle"}));
        set_max_encumbrance(2000);
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������װ���͵Ĺ���\n");
                set("value", 1);
        }

		// mark it as a liquid container
		set("liquid/container",1);
		set_max_liquid(50);
		set_current_liquid(0);

		setup();

        carry_liquid("/d/xueshan/obj/suyou", 50);

}


