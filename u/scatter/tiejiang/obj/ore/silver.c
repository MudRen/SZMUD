// ����ʯ
// silverore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����ʯ", ({"silver ore","yin kuang"}));
      set_weight(41000);

        set_color("$HIW$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "����һ��ոտ��ɵĴ�����ʯ������չ�Ժ���
�õ����ԡ����ִ������ʯ,һ�����Լ���������߰�����������������\n");
                set("unit", "��");
                set("item_id", "silver");
set("material", "silver");
set("value",1000);
set("ore", "/newjob/tiejiang/obj/ore/silver.c");
                set("basci_unit","��"); 
                set("basic_value", "10000000");  
set("strvalue", 15);
set("kuang", 1);          
        }

}
