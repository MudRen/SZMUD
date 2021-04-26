// Code of ShenZhou
// /d/xueshan/obj/suyou.c
//su you, butter

#include <ansi.h>

inherit "/d/xueshan/inherit/liquid_content.c";


void set_amount(int v)
{
        if (v >= 0) {
            set("value", v * (int)query("base_value"));
        }
        ::set_amount(v);
}

void add_amount(int v) { set_amount((int)query_amount()+v); }

void create()
{
        set_name(YEL "����" NOR, ({"su you", "butter", "you"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�Ƴγε�����\n");
                set("base_value", 100);
                set("base_unit", "��");
                set("base_weight", 10);
        }
		set("no_get",1);
		// mark it as liquid
		set("liquid/status",1);
        set_amount(1);
        setup();


}


