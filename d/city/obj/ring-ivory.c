// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("������ָ", ({ "ivory ring", "ring" }));
        set_color("$HIW$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ʵĽ�ָ������������а�ĸо���\n");
                set("unit", "��");
                set("value", 4500);
                set("material", "ivory");
                set("armor_prop/armor", 3);
        }
        setup();
}       
