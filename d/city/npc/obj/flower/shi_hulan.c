// Code of ShenZhou
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIC "ʯ����" NOR, ({"shihu lan", "shi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�仨���ƽ������޾��׵�ʯ�����������������Ѥ����\n"
			"������������īɫ�Ļ��Σ������š����������䡱��\n");
		set("unit", "��");
		set("value", 45);
		set("base_unit", "��");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"