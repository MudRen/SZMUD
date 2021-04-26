//Cracked by Roath
// neiheal.c
// By Xuanyuan

#include <ansi.h>

int exert(object me, object target)
{
	int mode, duration_hot1, level, duration_hot2, duration_cold1, duration_cold2;
	if( target == me ) mode = 1;
	else mode = 2;

   	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("ս�����޷��˹����ˣ�\n");

   	if ( mode == 1 ) {
		if ( (int)me->query_condition("hot_poison") < 0 )
			return notify_fail("�㲢δ�ܺ�÷ů�������ˣ�\n");

		if ( (int)me->query_condition("cold_poison") < 0 )
			return notify_fail("�㲢δ�ܻ캮÷ů�����ˣ�\n");

		if ( (int)me->query_skill("bahuang-gong", 1) < 80 ) 
			return notify_fail("��˻�����Ψ�Ҷ��𹦵�����̫ǳ�����ܻ��⺮÷ů�����ˣ�\n");

		if( (int)me->query("neili") < 350 )
			return notify_fail("�������������\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

		message_vision(RED"$N��ϥ�����˶��˻�����Ψ�Ҷ��𹦣�ֻ��ͷ���������ڣ��³�һ��������Ѫ����ɫ�Ե�ʮ�ֲ԰ס�\n"NOR, me);
        	me->apply_condition("hot_damage", 0);
			me->apply_condition("cold_damage", 0);
        	me->add("neili", -200);
		me->receive_damage("qi", 100, "����͸֧��������");
	}	
	else {
		if ( (int)target->query_condition("hot_poison") < 0 )
			return notify_fail("���˲�δ�ܺ�÷ů�����ˣ�\n");

		if ( (int)target->query_condition("cold_poison") < 0 )
			return notify_fail("���˲�δ�ܺ�÷ů�����ˣ�\n");

		if ( (int)me->query_skill("bahuang-gong", 1) < 100 )
			return notify_fail("��˻�����Ψ�Ҷ��𹦵�����̫ǳ������Ϊ���˻��⺮÷ů�����ˣ�\n");

		if( (int)me->query("max_neili") < 1000 )
			return notify_fail("���������Ϊ������\n");

		if( (int)me->query("neili") < 500 )
			return notify_fail("�������������\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

		if( !living(target) )
			return notify_fail("�����ѻ��������ˣ����ܾ��Σ�\n");

		message_vision(RED"$N��������˻�����Ψ�Ҷ��𹦣������İ�$n�������Ŵ�Ѩ������ؽ���������$n����....\n"
				  "���ã�$N��ͷ�ϴ����죬ͷ�ϰ������ڣ��Ե�ʮ��ƣ�롣\n"
				  "ֻ��$n�³�һ��������Ѫ����ɫȴ�Ե�ʮ�ֲ԰ס�\n" NOR, me, target );

		tell_object(target,GRN"��е�һ������һ�����������������������ߣ�������\n"
				      "�ڻ���������ˣ����ʱ��ʱ���ĸо���\n"NOR);

		if( (int)target->query_skill("bahuang-gong", 1) > 20 ) {
			tell_object(target,GRN"�㺮÷ů�����˱������ˡ�\n"NOR);
			target->apply_condition("hot_poison", 0);
			target->apply_condition("cold_poison", 0);
			target->receive_damage("qi", 100, "����͸֧��������");
			me->add("neili", -200);
			me->receive_damage("qi", 100, "����͸֧��������");
		}
		else {
			level = me->query_skill("bahuang-gong", 1);
			duration_hot1 = target->query_condition("hot_poison");
			duration_hot2 = duration_hot1 - me->query_skill("bahuang-gong", 1) / 20;
			duration_cold1 = target->query_condition("hot_poison");
			duration_cold2 = duration_cold1 - me->query_skill("bahuang-gong", 1) / 20;

			if ( duration_hot2 < 0 ) duration_hot2 = 0;
			if ( duration_cold2 < 0 ) duration_cold2 = 0;

			target->apply_condition("hot_poison", duration_hot2);
			target->apply_condition("cold_poison", duration_cold2);
			me->add("neili", -200);
			if ( target->query_condition("hot_poison") > 0 && target->query_condition("cold_poison") > 0 ) {
				tell_object(me,"�㷢��"+target->name()+"�޷���ȫ������˻�����Ψ�Ҷ��𹦵������������÷ּ������ƣ�\n");
				if( (int)target->query_skill("bahuang-gong", 1) > 0 )
					tell_object(target,"��İ˻�����Ψ�Ҷ�����Ϊ�������޷���"+me->name()+"�������ںϣ������÷ּ������ƣ�\n");
				else tell_object(target,"���ڹ��ķ���˻�����Ψ�Ҷ��𹦴��ྶͥ���޷���"+me->name()+"�������ںϣ������÷ּ������ƣ�\n");
			}
			else tell_object(target,GRN"�㺮÷ů�����˱������ˡ�\n"NOR);
			target->receive_damage("qi", 150, "����͸֧��������");
			me->receive_damage("qi", 100, "����͸֧��������");
		}
	}

	return 1;
}
