// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(HIW"��ʯ��ָ"NOR, ({ "diamond ring", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һö����Ϊ������ʯΪ�壬�ɶ���������ĥ�ɰ˱߲���εĻ�����ʯ��ָ��\n");
                set("unit", "��");
                set("value", 18000);
                set("material", "diamond");
                set("armor_prop/armor", 5);
        }
        setup();
}       
