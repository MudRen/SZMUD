// Code of ShenZhou
// gold.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("��ʯ", ({"diamond", "zuan", "zuan_money"}));
        set_color("$HIW$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "diamond");
		set("long", "�������������ֵǮ�Ķ���������ʯ�ˣ������һ���Ӷ�û������\n����˽�������Ǯ����ʹ�á�\n");
		set("unit", "Щ");
		set("base_value", 1000000 );
		set("base_unit", "��");
		set("base_weight", 20);
	}
	set_amount(1);
}

