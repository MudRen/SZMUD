// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIW"��ʯ����"NOR, ({ "diamond necklace", "necklace", "lace" }));
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������ʯΪ�����������׹�ӵ�����ˮ���Σ���Χ����һȦ���꣬��������·��ҡҷ��ڣ�������Ŀ�Ĺ�â��\n");
                set("unit", "��");
                set("value", 28000);
                set("material", "diamond");
                set("armor_prop/armor", 7);
        }
        setup();
}       
