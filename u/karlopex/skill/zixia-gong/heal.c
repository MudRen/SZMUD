// Code of ShenZhou
// neiheal.c
// qfy Nov 12, 1996.

#include <ansi.h>

int exert(object me, object target)
{
	int mode, duration1, level, duration2;
	
	if( !target || target == me ) return 0;
	if( target == me ) mode = 1;
	else mode = 2;

   	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("ս�����޷��˹����ˣ�\n");

   	if ( mode == 1 ) {
		if ( (int)me->query_skill("zixia-gong", 1) < 20 ) 
			return notify_fail("�����ϼ����Ϊ��������\n");

		if( (int)me->query("neili") < 50 )
			return notify_fail("�������������\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

		write( HIW "��ȫ����ɣ�������������ϼ�����ˡ�\n" NOR);
		message("vision",
			HIW + me->name() + "�������ˣ�ͻȻ����������ʢ�³���Ѫ����ɫ�������ö��ˡ�\n" NOR,
			environment(me), me);

        	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
		me->add("neili", -50);
		me->set("jiali", 0);
	}	
	else {
		if ( (int)me->query_skill("zixia-gong", 1) < 50 )
			return notify_fail("����ϼ��������̫ǳ������Ϊ���˻����Ԫ�޼������ˣ�\n");

		if( (int)me->query("max_neili") < 300 )
			return notify_fail("���������Ϊ������\n");

		if( (int)me->query("neili") < 150 )
			return notify_fail("�������������\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

		if( !living(target) )
			return notify_fail("�����ѻ��������ˣ����ܾ��Σ�\n");

		message_vision(MAG"$N����������ϼ���������İ�$n�������Ŵ�Ѩ������ؽ���������$n����....\n"
				  "���ã�$N��ͷ�ϴ����죬ͷ���������ڣ��Ե�ʮ��ƣ�롣\n"
				  "ֻ��$n�³�һ�����Ϻ����Ѫ����ɫȴ�Ե�ʮ�ֲ԰ס�\n" NOR, me, target );

		target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
		target->add("qi", 10 + (int)me->query_skill("force")/3 );
		if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

		me->add("neili", -150);
		me->set("jiali", 0);
	}

	return 1;
}
