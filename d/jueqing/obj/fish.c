//  /d/jueqing/obj/fish.c ˮ������ 
//  jiuer---08/15/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"ˮ������"NOR, ({"shuijing miyu","miyu","fish"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"һ������ˮ�����ۣ�ζ����֬�����㡣\n"NOR);
		set("unit", "��");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 80);
	}
}
