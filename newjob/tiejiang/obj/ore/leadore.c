// Ǧ�տ�ʯ
// tinore.c
// Code by Cheap
// 2001/10/25
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("Ǧ�տ�ʯ", ({"lead ore"," kuang"}));
	set_weight(32000);
        set_color("$HIB$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵ�Ǧ�տ�ʯ��һ���ض���������չ�ԣ�����
�Զ�û�е��Ե� Ǧ�տ��ʯ,һ�����Լ���������߰�������Ǧ��������\n");
                set("unit", "��");
                set("item_id", "lead");
set("material", "lead");
                set("basic_weight",100000);              
set("value",50);
set("ore", "/newjob/tiejiang/obj/ore/tinore.c");
set("strvalue", 19);
set("kuang", 1);
}

}
