// Code of ShenZhou
// tyxiaoao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("Բ��С��", ({ "xiao ao", "ao", "cloth" }) );
	set("long", "һ��̨�����Ӵ���Բ��С����\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
