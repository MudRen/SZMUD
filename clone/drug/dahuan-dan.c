//Cracked by Roath
// dahuan-dan.c �󻹵�

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
	set_name("�󻹵�", ({"dahuan dan", "dahuan", "dan"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ϻ쾧���Ĵ󻹵����˵���������ҩ����߹�������Ч�ޱȡ�\n");
		set("value", 10000);
                set("no_sell", 1);
		set("medicine", 1);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("shaolin",1);
	setup();
}

int cure_ob(object me)
{

	if ( (me->query_skill_mapped("force") != "hunyuan-yiqi") )
	{
		if ( me->query( "max_neili" ) > 10 )
		me->add("max_neili", -10);
		else 
			me->set( "max_neili", 1 );

		message_vision(HIR "$N����һ�Ŵ󻹵���ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{  
		me->add("max_neili", -1);
	    message_vision(HIR "$N����һ�Ŵ󻹵���ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else {
		me->add("max_neili", 1);
		message_vision(HIG "$N����һ�Ŵ󻹵���ֻ������������ԴԴ���������Ϲ���������
͸ʮ����¥���鲼��������ȫ������Ȼ��� !\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 60);
	
	destruct(this_object());
	return 1;
}

int do_put(string arg1, string arg2, string arg3)
{
	if( present(arg1, this_player()) == this_object() ) return 1;

	return 0;
}

