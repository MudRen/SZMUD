// Code of ShenZhou
// lotus.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
          set_name(HIW "�ɻ�" NOR, ({"he hua", "lotus"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
                  set("long", "����һ�����׺�ɢ���ŵ���������,�����ϻ���һ�������״������.��\n");
		set("unit", "��");
		set("value", 50);
		set("base_unit", "��");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}

