// Code of ShenZhou
// ganlu.c ��¶

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(HIM "��¶" NOR, ({"gan lu", "lu"}));
	set_weight(10);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ι��������ĸ�¶����Ө��ˮ��ɢ���������Ĺ�â��\n");
		set("value",0);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	object *inv;
	int i;

	me->clear_condition();

	if ( me->query_temp("sanxiao") ){
		me->delete_temp("sanxiao");
		me->delete_temp("smile");
	}

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("food", (int)me->max_food_capacity());
	me->set("water", (int)me->max_water_capacity());
        
	message_vision(HIG"��¶���ģ�$Nֻ���þ���������Ѫ��ӯ����������ԴԴ������\n"
		+"��ƣ������һɨ���ն������еĶ�Ҳû��! \n"NOR, me);

	destruct(this_object());
	return 1;
}
