// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("�����ָ", ({ "jade ring", "ring" }));
        set_color("$HIG$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ָ����������ĳЩ�ط����в��������쳣���ء�\n");
                set("unit", "��");
                set("value", 6500);
                set("material", "jade");
                set("armor_prop/armor", 4);
        }
        setup();
}       
