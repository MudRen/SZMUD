// Code of ShenZhou
// wyskirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���ĳ�ȹ", ({ "chang qun","qun","skirt" }) );
	set("long", "����һ�����ĸ�Ů������˿֯��ɫ��ȹ���䳤ҷ�ء�\n");
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
