// ����ʯ
// aluminiumore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(" ����ʯ", ({"aluminium","jin kuang"}));
        set_weight(37000);
        set_color("$YEL$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵ� ����ʯ����չ�Ժú�������
��������ͭ���ʯ,һ�����Լ���������߰�����������������\n");
                set("unit", "��");
                set("item_id", "aluminium");
set("material", "aluminium");
set("value", 40);
set("ore","/newjob/tiejiang/obj/ore/aluminiumore.c");
set("strvalue", 16);
set("kuang", 1);
        }

}
