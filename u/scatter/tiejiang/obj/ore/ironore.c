#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("����ʯ", ({"iron ore","tie kuang"}));
set_weight(450000);


        set_color("$HIW$");
        if( clonep() )set_default_object(__FILE__);
        else {
set ("long", " ����һ��ոտ��ɵ��������ʯ���������൱�ḻ,��Ӳ�ĳ����ҡ������������ʯ,һ�����Լ���������빫���������������\n");

set("unit", "��");


                set("item_id", "iron");
set("material", "iron");
set("value",45);
set("ore", "/newjob/tiejiang/obj/ore/ironore.c");
set("strvalue", 16);
set("kuang", 1);
setup();
}





setup();

        }
