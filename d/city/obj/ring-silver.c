// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("����ָ", ({ "silver ring", "ring" }));
        set_color("$HIW$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ƵĽ�ָ��һ�����װ�Ρ�\n");
                set("unit", "��");
                set("value", 3500);
                set("material", "silver");
                set("armor_prop/armor", 2);
        }
        setup();
}       
