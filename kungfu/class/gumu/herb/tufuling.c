// ������ tufuling.c
// by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"������"NOR, ({"tufuling"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�ݱ�ֲ�����Ѫ�������࣬�ǲ��ɶ�õ��ϼ�ҩ�ġ�\n");
		set("value", 8000);
		set("yaocai", 1);
		set("cure_s",30);
		set("cure_d",20);
		set("cure_n",40);
	}
	setup();
}