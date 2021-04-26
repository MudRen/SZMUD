//bahuang.c   
//by Xuanyuan

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	int skill, dur, drop, age;
	int bili, wuxing, gengu;
	int sum, num1, num2, num3, num4;
	string arg;

	skill = (int)me->query_skill("bahuang-gong", 1);
	dur = (int)me->query("neili");
	age = me->query("age") - 30;
	if (age < 0)
	age = 0;

//	if (! wizardp(me)) 
//		return notify_fail("Ŀǰ�⹦�ܻ������ţ�\n");

	if( target != me ) 
		return notify_fail("��ֻ���ð˻�����Ψ�Ҷ�����ǿ�Լ�������\n");

	if( skill < 150 )
		return notify_fail("��İ˻�����Ψ�Ҷ��𹦹����������\n");

	if( (int)me->query_skill("force") < 150 )
		return notify_fail("��Ļ����ڹ���Ϊ���δ�㣬�޷�ʹ�ð˻�����Ψ�Ҷ��𹦣�\n");

	if( me->query("max_neili") <= 2000 )
		return notify_fail("���������������޷�ʹ�ð˻�����Ψ�Ҷ��𹦣�\n");

	if ( me->query("gender") == "����" )
		return notify_fail("���޸����ԣ������������������ð˻�����Ψ�Ҷ��𹦡�\n");

	if ( me->query("bahuang_age") > age )
		return notify_fail("�˻�����Ψ�Ҷ���ֻ��ÿ��ʮ����һ�Ρ�\n");

	if( (int)me->query("neili") < me->query("max_neili")*2 - 100  ) 
		return notify_fail("�˻�����Ψ�Ҷ���Ҫ����������ȫ���ʱ��ſ�ʹ�ã��������������\n");

	if( (int)me->query_temp("bahuang") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if (dur < 1)
		return notify_fail("��������������ð˻�����Ψ�Ҷ��𹦡�\n");

	message_vision(HIR "$N��ϥ���£�����ʳָָ�죬����ʳָָ�أ����кٵ�һ�����ǿ����������������������\n" NOR, me);

	me->set("bahuang/temp_age", me->query("age"));
	if(me->query("bahuang_age")){
	me->set("age", me->query("bahuang_age"));
	}
	me->set("bahuang/temp_exp",me->query("combat_exp"));
	if(me->query("bahuang_exp")){
	me->set("combat_exp", me->query("bahuang_exp"));
	}

	me->apply_condition("bahuang", dur);
	me->set_temp("bahuang", 1);
	me->start_busy(10+random(30));
	call_out("checking", 1, me, target,skill);
	return 1;
}
int checking(object me)
{
	if( me->query_temp("bahuang") && me->query_skill_mapped("force") != "bahuang-gong")
	{
		tell_object(me,HIR"��İ˻�����Ψ�Ҷ�������ͻȻ��ʧȴ���ƣ������ˮ���ģ���ʱҪ���̶�����\n"NOR);
		message_vision(HIR"ͻȻֻ��$Nȫ���������ָ��ץ�Լ���գ���ʱѪ�۰߰ߡ�\n\n"NOR,me);
		tell_object(me,"��Ϊ�����˹�ʱ�����ڹ������¹�������\n");

		me->clear_condition("bahuang");
		me->delete_temp("bahuang");

		me->set("age",me->query("bahuang/temp_age"));
		me->delete("bahuang/temp_age");
			if(!me->query("bahuang_age")){
				me->set("bahuang_age", me->query("age"));
			}
		me->set("combat_exp",me->query("bahuang/temp_exp"));
		me->delete("bahuang/temp_exp");
			if(!me->query("bahuang_exp")){
				me->set("bahuang_exp", me->query("combat_exp"));
			}
		me->add("combat_exp", -(int)me->query("combat_exp",1)/10);
		me->add("max_neili", -200);
		me->add("max_jingli", -150);
		me->add("eff_jingli", -150);

		return 1;
	}
	if(!me->query_temp("bahuang") && me->query("bahuang_age") == me->query("age") )
	{
		tell_object(me, HIR"��İ˻�����Ψ�Ҷ���������ϡ�\n"NOR);
		return 1;
	}
	else call_out("checking", 1, me);
	return 1;
}
