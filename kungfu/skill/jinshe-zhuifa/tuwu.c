// Code of ShenZhou
// tuwu.c ��������

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon1, weapon2;
	int tqi;

	weapon1 = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target || !target->is_character() || target->query("race") != "����" )
		return notify_fail("��Ҫ͵Ϯ˭��\n");

	if( environment(target)->query("no_fight") && !wizardp(me) )
		return notify_fail("�������㲻��ʩչ����������ʹ�ð���͵Ϯ��\n");

	if( me->query_skill("throwing") < 100 )
		return notify_fail("���ڽ���׶����Ϊ������������ʩչ����������ʹ�ð���͵Ϯ��\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("����ڹ���Ϊ���δ��������������ʩչ�������������䰵��͵Ϯ��\n");

	if( me->query("max_neili") <= 500 )
		return notify_fail("���������Ϊ���㣬����������ʩչ�������������䰵��͵Ϯ��\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������������������ʩչ�������������䰵��͵Ϯ��\n");

	message("vision", HIR "\nͻȻ��"+me->name()+"����"+target->name()+"һ����ʩչ������������"+weapon1->name()
		+"������Ϣ�ص�����"+target->name()+"��ǰ��\n\n" NOR, environment(target), ({target, me}) );
	me->add("neili", -100);

	tell_object(me, "��ʩչ����������͵Ϯ"+target->name()+"��\n");

	tqi = target->query("max_qi");

	if( random(me->query("combat_exp")) < random(target->query("combat_exp")) ) {
		tell_object(target, "��ͻȻ����"+me->name()+"����"+weapon1->name()+"����͵Ϯ��\n");
		message_vision("����$p������$P����ͼ�����˿�ȥ��\n", me, target);
		weapon1->add_amount(-1);
//		me->add("neili", -15);
		if( target->query("qi")*100 / tqi <= 80 ) target->kill_ob(me);
		else if( !target->is_fighting(me) ) target->fight_ob(me);
		return 1;
	}

	if( objectp(weapon2 = target->query_temp("weapon")) ) {
	    if (me->query_str() >= target->query_str()) {
		switch ( random(2) ) {
		   case 0:
			message_vision("$N�����"+weapon1->name()+"ײ����$n��"+weapon2->name()+"�����������ǡ�\n", me, target);
			message_vision("$N��Ȼ���û��ڴ������е�"+weapon2->name()+"���ַ��ϰ�գ�\n", target);
			weapon1->add_amount(-1);
			weapon2->move(environment(me));
			break;
		   case 1:
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			break;
		}
	    }			
	    else COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	else COMBAT_D->do_attack(me, target, me->query_temp("weapon"));		

//	me->add("neili", -15);
	
	if( target->query("qi")*100 / tqi <= 80 ) target->kill_ob(me);
        else if( !target->is_fighting(me) ) target->fight_ob(me);

	return 1;
}
