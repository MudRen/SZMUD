//Created by Zyu on k1-08-11
// Object: /d/wuguan/obj/shizi.c
#include <ansi.h>
inherit COMBINED_ITEM;
inherit F_COMMAND;

void create()
{
	set_name(GRN"Сʯ��"NOR, ({"xiao shizi", "shizi"}));

	if (clonep())
	set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit","��");
		set("long", "����������洦�ɼ���Сʯ�ӡ�\n");
		set("value", 0);
	}

	set_amount(1+random(2));
	set("no_get", "��ݲƲ�����ɲ����ã�\n");
	set("no_drop", "��ݴ�������������ܶ�����\n");

	setup();
}
