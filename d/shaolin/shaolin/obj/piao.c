// Code of ShenZhou
//ˮư
//xiaojian May 25,2000

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ˮư", ({"shui piao", "piao"}));
	set_weight(100);
	if(clonep())
		set_default_object(__FILE__);

	else {
		set("long", "����һ��Ҩˮ�õ�ˮư��\n");
		set("unit", "��");
		set("material", "wood");
		set("value", 0);
	}
}
void init()
{
        object me = this_player();
         if (!wizardp(me)) {
                set("no_give",  "����������������ˡ�\n");
                set("no_steal", "���������͵������\n");
                }
}
	
