// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("��������", ({ "pearl necklace", "necklace", "lace" }));
        set_color("$HIM$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ɵ���������Բ��覣�������͵Ĺ�â��\n");
                set("unit", "��");
                set("value", 7000);
                set("material", "pearl");
                set("armor_prop/armor", 5);
        }
        setup();
}       
