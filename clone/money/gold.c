// Code of ShenZhou
// gold.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("�ƽ�", ({"gold", "ingot", "gold_money"}));
        set_color("$HIY$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
		set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n");
		set("unit", "Щ");
		set("base_value", 10000 );
		set("base_unit", "��");
		set("base_weight", 333);
	}
	set_amount(1);
}

