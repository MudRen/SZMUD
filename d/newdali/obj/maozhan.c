// Code of ShenZhou
// maozhan.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("ëձ", ({ "mao zhan","zhan" }) );
	set("long", "��һ�Ű��������Ӿ����������ö���Ƥë��֯�ɵ�ëձ��\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
