// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(YEL "�������" NOR, ({ "amber earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3000);
                set("long", "һ��������׹�Ķ��Σ�ɢ���������Ĺ�ʡ�\n");
                set("material", "amber");
                set("armor_prop/armor", 2);
				set("female_only", 1);
        }
        setup();
}