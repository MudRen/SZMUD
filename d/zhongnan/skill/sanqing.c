// Code of ShenZhou
//sanqing.c һ��������
//by sdong

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me, object target);

int perform(object me, object target)
{
	string weapon;
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("һ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("sanqing",1) )
		return notify_fail("������ʹ��һ�������壡\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("�����õĲ������칦���޷�ʩչһ�������壡\n");

	if( me->query_skill("xiantian-gong", 1) < 60 )
		return notify_fail("������칦���δ�����޷�ʩչһ�������壡\n");


	if( me->query_skill("sword") < 135 )
		return notify_fail("���ȫ�潣����Ϊ���㣬������ʹ��һ�������壡\n");

	if( me->query("neili") <= 200 )
		return notify_fail("�����������ʹ��һ�������壡\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ��һ�������壡\n");


	weapon = me->query_temp("weapon");
	target->set_temp("apply/speed", target->query_temp("apply/speed",1)-50);
	me->set_temp("apply/speed", me->query_temp("apply/speed",1)+50);
	me->set_temp("apply/attack", me->query_temp("apply/attack",1)+10);
	skill =  ( me->query_skill("quanzhen-jian")
		+ me->query_skill("force") ) / 2;

	message_vision(HIY "$N���һ��������ͻ�䣬"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â��һ����Ϊ�����������������磡\n\n" NOR, me, target);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -200);
	me->add("jingli", -100);
	me->add("jing", -100);
	me->set_temp("sanqing",1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target:),skill/5 );
	return 1;
}

int remove_effect(object me, object target)
{
	me->set_temp("apply/speed", me->query_temp("apply/speed",1)-50);
	me->set_temp("apply/attack", me->query_temp("apply/attack",1)-10);
	me->delete_temp("sanqing");
	message_vision(
	HIG "\n$N����һ�������������ջص������Ҳ�ָ�������\n\n" NOR, me);

	if( objectp(target) )
		target->set_temp("apply/speed", target->query_temp("apply/speed",1)+50);
	return 0;
}


