// Code of ShenZhou
// skeleton.c ���ù�

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("���ù�", ({"skeleton", "kulou", "gu"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"���ù������·��������߰˳ɣ���Ȼ�пɼ����Ǹ����Ρ�\n");
                set("material", "steel");
		set("value", 100);
        }
}
