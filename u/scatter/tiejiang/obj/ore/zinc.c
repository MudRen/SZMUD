// п��ʯ
// tinore.c
// Code by Cheap
// 2001/10/25
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("п��ʯ", ({"zinc ore","xin kuang"}));
	set_weight(37800);
        set_color("$HIB$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵ�п��ʯ��һ�����Լ���������߰�������п��������\n");
                set("unit", "��");
                set("item_id", "zinc");
set("material", "zinc");
set("value",100);
set("ore", "/newjob/tiejiang/obj/ore/tinore.c");
set("strvalue", 14);
set("kuang", 1);
        }

}
