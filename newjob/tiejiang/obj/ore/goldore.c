// ���ʯ
// goldore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���ʯ", ({"gold ore","ore"}));

set_weight(50000);
        set_color("$HIY$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵĽ��ʯ�����ֽ���ʯ,һ�����Լ���������������Ĵ��������\n");
                set("unit", "��");

                set("item_id", "gold");
set("value",10000);
set("material", "gold");
set("ore", "/newjob/tiejiang/obj/ore/goldore.c");
set("strvalue", 20);
set("kuang", 1);
        }

}
