// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW "��βԧ����" NOR, ({ "yuanyang chai", "chai" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000);
                set("long", "һ֧�԰׽�������ɵķ��Σ����������ӿ��һ���Ҹ��ĸо���\n");
                set("material", "jade");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}
