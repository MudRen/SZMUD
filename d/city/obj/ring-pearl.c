// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("�����ָ", ({ "pearl ring", "ring" }));
        set_color("$HIM$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ɵĽ�ָ����������һ��ָͷ��С�����飬���������⡣\n");
                set("unit", "��");
                set("value", 5500);
                set("material", "pearl");
                set("armor_prop/armor", 3);
        }
        setup();
}       
