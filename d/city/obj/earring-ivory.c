// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW "��������" NOR, ({ "ivory earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("long", "һ�����������ɵĶ��Σ���״�ǳ��޴�\n");
                set("material", "ivory");
                set("armor_prop/armor", 4);
				set("female_only", 1);
        }
        setup();
}