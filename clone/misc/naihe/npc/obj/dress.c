// �ĳ���Ա�������·��� dress.c
// by naihe 2002-05-01

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ȹ", ({"dress"}) );
	set_color("$HIC$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ������ɫ��¶����ȹ��\n");
		set("unit", "��");
		set("value", 10000);
		set("material", "silk");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}
