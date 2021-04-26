// Code of ShenZhou
// xiaohuan-dan.c С����

#include <ansi.h>

inherit ITEM;

void setup()
{}
int cure_ob(string);
void init()
{
	add_action("do_put", "put");
}

void create()
{
	set_name("С����", ({"xiaohuan dan", "xiaohuan", "dan"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ө����Բ��С�������˵���������ҩ��������������Ч�ޱȡ�\n");
		set("value", 5000);
                set("no_sell", 1);
		set("medicine", 1);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("shaolin",1);
	setup();
}

int cure_ob(object me)
{
	if ( me->query("neili") >= me->query("max_neili")*2 )
	return notify_fail("������û��Ҫ��С������\n");

	if ( me->query_skill_mapped("force") != "hunyuan-yiqi" )
	{
		me->set("neili", 0);
		message_vision(HIR "$N����һ��С������ֻ�����������ѣ�ԭ�������ڹ�����������������Ϊ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("neili", -200);
		message_vision(HIR "$N����һ��С������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("neili", 200);
		message_vision(HIY "$N����һ��С������ֻ�����������࣬��֫�ٺ�������ӯ�ޱȣ��������ڶ�����\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 30);

	destruct(this_object());
	return 1;
}

int do_put(string arg1, string arg2, string arg3)
{
	if( present(arg1, this_player()) == this_object() ) return 1;

	return 0;
}

