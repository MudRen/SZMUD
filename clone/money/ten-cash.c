// Code of ShenZhou
// ten.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("ʮ����Ʊ", ({"cash", "ten-cash", "ten-cash_money"}));
        set_color("$HIG$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "ten-cash");
		set("long", "һ�����ֵʮ�����ӵ���Ʊ��\n");
		set("unit", "��");
		set("base_value", 1000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

