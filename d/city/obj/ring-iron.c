// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("����ָ", ({ "iron ring", "ring" }));
        set_color("$HIC$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ѱ���Ľ�ָ����Ϊһ������װ��Ʒ������Ϊ����\n");
                set("unit", "��");
                set("value", 2500);
                set("material", "iron");
                set("armor_prop/armor", 1);
        }
        setup();
}       
