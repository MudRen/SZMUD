// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("��������", ({ "silver necklace", "necklace", "lace" }));
        set_color("$HIW$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������Ƴɵ�����������ഫ����������������һЩ��ħ��\n");
                set("unit", "��");
                set("value", 4000);
                set("material", "silver");
                set("armor_prop/armor", 2);
        }
        setup();
}       
