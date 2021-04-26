// Code of ShenZhou
// neiheal.c
// qfy Nov 12, 1996.

#include <ansi.h>

int exert(object me, object target)
{
	int mode, duration1, level, duration2;

	if( target == me ) mode = 1;
	else mode = 2;

   	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("ս�����޷��˹����ˣ�\n");

   	if ( mode == 1 ) {
		if ( !(int)me->query_condition("hyz_damage") > 0 )
			return notify_fail("�㲢δ�ܻ�Ԫ�޼������ˣ�\n");

		if ( (int)me->query_skill("zixia-gong", 1) < 80 ) 
			return notify_fail("����ϼ��������̫ǳ�����ܻ����Ԫ�޼������ˣ�\n");

		if( (int)me->query("neili") < 150 )
			return notify_fail("�������������\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

		message_vision(MAG"$N��ϥ�����˶���ϼ����ֻ��ͷ���������ڣ����³�һ���Ϻ����Ѫ����ɫ�Ե�ʮ�ֲ԰ס�\n"NOR, me);
        	me->apply_condition("hyz_damage", 0);
        	me->add("neili", -100);
		me->receive_damage("qi", 100, "����͸֧��������");
	}	
	else {
		if ( !(int)target->query_condition("hyz_damage") > 0 )
			return notify_fail("���˲�δ�ܻ�Ԫ�޼������ˣ�\n");

		if ( (int)me->query_skill("zixia-gong", 1) < 100 )
			return notify_fail("����ϼ��������̫ǳ������Ϊ���˻����Ԫ�޼������ˣ�\n");

		if( (int)me->query("max_neili") < 600 )
			return notify_fail("���������Ϊ������\n");

		if( (int)me->query("neili") < 250 )
			return notify_fail("�������������\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

		if( !living(target) )
			return notify_fail("�����ѻ��������ˣ����ܾ��Σ�\n");

		message_vision(MAG"$N����������ϼ���������İ�$n�������Ŵ�Ѩ������ؽ���������$n����....\n"
				  "���ã�$N��ͷ�ϴ����죬ͷ���������ڣ��Ե�ʮ��ƣ�롣\n"
				  "ֻ��$n�³�һ�����Ϻ����Ѫ����ɫȴ�Ե�ʮ�ֲ԰ס�\n" NOR, me, target );

		tell_object(target,GRN"��е�һ������һ�����������������������ߣ�������\n"
				      "�ڻ���������ˣ����ʱ��ʱ���ĸо���\n"NOR);

		if( (int)target->query_skill("zixia-gong", 1) > 20 ) {
			tell_object(target,GRN"���Ԫ�޼������˱������ˡ�\n"NOR);
			target->apply_condition("hyz_damage", 0);
			target->receive_damage("qi", 100, "����͸֧��������");
			me->add("neili", -200);
			me->receive_damage("qi", 100, "����͸֧��������");
		}
		else {
			level = me->query_skill("zixia-gong", 1);
			duration1 = target->query_condition("hyz_damage");
			duration2 = duration1 - me->query_skill("zixia-gong", 1) / 20;

			if ( duration2 < 0 ) duration2 = 0;

			target->apply_condition("hyz_damage", duration2);
			me->add("neili", -200);
			if ( target->query_condition("hyz_damage") > 0 ) {
				tell_object(me,"�㷢��"+target->name()+"�޷���ȫ��������ϼ���������������÷ּ������ƣ�\n");
				if( (int)target->query_skill("zixia-gong", 1) > 0 )
					tell_object(target,"�����ϼ����Ϊ�������޷���"+me->name()+"�������ںϣ������÷ּ������ƣ�\n");
				else tell_object(target,"���ڹ��ķ�����ϼ�����ྶͥ���޷���"+me->name()+"�������ںϣ������÷ּ������ƣ�\n");
			}
			else tell_object(target,GRN"���Ԫ�޼������˱������ˡ�\n"NOR);
			target->receive_damage("qi", 150, "����͸֧��������");
			me->receive_damage("qi", 100, "����͸֧��������");
		}
	}

	return 1;
}
