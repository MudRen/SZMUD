// Code of ShenZhou
// hundred.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("������Ʊ", ({"cash", "hundred-cash", "hundred-cash_money"}));
        set_color("$HIG$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "hundred-cash");
		set("long", "һ�����ֵһ�������ӵ���Ʊ��\n");
		set("unit", "��");
		set("base_value", 10000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

