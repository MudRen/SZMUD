// Code of ShenZhou
// tytoujin.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("̨��ͷ��", ({ "tou jin","toujin","jin" }) );
	set("long", "һ��̨����������ͷ��һ������ϴ��Ķ�ȹͬɫ��\n");
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
