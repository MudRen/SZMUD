// ����ʯ
// tinore.c
// Code by Cheap
// 2001/10/25
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����ʯ", ({"tin ore","xi kuang"}));
set_weight(35000);
        set_color("$BLU$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵ�����ʯ���������׶ϡ�
��������ͭ���ʯ,һ�����Լ�������߰�������ͭ��������\n");
                set("unit", "��");
                set("item_id", "tin");
set("material", "tin");
set("value",60);
set("ore", "/newjob/tiejiang/obj/ore/tinore.c");
set("strvalue", 22);
set("kuang", 1);
        }

}
