// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW "��ʯ����" NOR, ({ "diamond earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 24000);
                set("long", "һ�Խ��ʶ��Σ����ϴ��������״����׹����˸�������ƻð�Ĺ�ʡ�\n");
                set("material", "diamond");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}