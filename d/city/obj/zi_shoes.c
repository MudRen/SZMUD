// Code of ShenZhou
// zi_shoes.c ˫���϶���Ь�� 
 
#include <armor.h>
#include <ansi.h>

inherit BOOTS;
 
void create()
{
	set_name(MAG"�϶���Ь��"NOR, ({ "shoes"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
		set("long", "����һ˫�������١��ֵ�˫���϶���Ь�ӡ�\n");
		set("value", 5000);
		set("armor_prop/dodge", 8);
	}
	setup();
}