// ͭ��ʯ
// silverore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ͭ��ʯ", ({"copper ore","tong kuang"}));
        set_weight(30000);
        set_color("$YEL$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵ���ͭ��ʯ������չ�Ժ�չ��
��������ͭ���ʯ,һ�����Լ���������߰�������ͭ��������\n");
                set("unit", "��");
                set("item_id", "copper");
set("ore", "/newjob/tiejiang/obj/ore/copperore.c");
set("material", "copper");
set("value", 45);
set("strvalue", 14);
set("kuang", 1);
        }

}
