// Code of ShenZhou
//magua.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( "���" , ({ "ma gua", "gown", "magua", "gua" }));
        set_color("$HIR$");
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ӡ������ɽ��ʱ�����·���\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 15000);
		set("wear_msg", HIR "$N����һ����ɫ��������ӣ�����һ���������׼������Ȣ�ס�\n" NOR);
		set("armor_prop/armor", 10);
		set("unequip_msg", HIM "$N��������������������Գ�һ�����¶̹ӡ�\n" NOR);
	}
	setup();
}

