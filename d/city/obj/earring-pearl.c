// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIM "�������" NOR, ({ "pearl earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 6000);
                set("long", "һ����������С�������ɵĶ��Σ�������ʱ��ɢ�������˵Ĺ�ʡ�\n");
                set("material", "pearl");
                set("armor_prop/armor", 5);
				set("female_only", 1);
        }
        setup();
}