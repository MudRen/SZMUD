// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("��������", ({ "ivory necklace", "necklace", "lace" }));
        set_color("$HIW$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������������ȫ�����ʽ�Ϊ�������ǳ����\n");
                set("unit", "��");
                set("value", 6000);
                set("material", "ivory");
                set("armor_prop/armor", 4);
        }
        setup();
}       
