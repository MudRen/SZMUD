// Code of ShenZhou
// tytongqun.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("Ͳȹ", ({ "tong qun","qun","skirt" }) );
	set("long", "һ��̨��Ů�Ӱ�������ɫͲȹ���������ס�\n");
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
