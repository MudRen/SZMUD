// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("��������", ({ "amber necklace", "necklace", "lace" }));
        set_color("$YEL$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������ɵ���������������֭�Ľᾧ�����˸о����̲������ص�������\n");
                set("unit", "��");
                set("value", 5000);
                set("material", "amber");
                set("armor_prop/armor", 3);
        }
        setup();
}       
