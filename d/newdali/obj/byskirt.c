// Code of ShenZhou
// byskirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���Ķ�ȹ", ({ "duan qun","qun","skirt" }) );
	set("long", "������Ů��ϲ�����ֳ�����ϥ�İ�ɫ˿֯�Ķ�ȹ��\n");
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
