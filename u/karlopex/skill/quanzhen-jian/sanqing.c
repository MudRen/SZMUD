// Code of ShenZhou
//sanqing.c һ��������
//by sdong, 06/98
// modified by sdong, 12/24/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
	string weapon;
	int skill, att;

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

	skill =  ( me->query_skill("quanzhen-jian")
		+ me->query_skill("force") ) / 5;

	if( me->query("neili") <= skill*3 )
		return notify_fail("�����������ʹ��һ�������壡\n");
	if( me->query("jingli") <= skill )
		return notify_fail("��ľ�������ʹ��һ�������壡\n");
	if( me->query("jing") <= skill )
		return notify_fail("��ľ�����ʹ��һ�������壡\n");

	weapon = me->query_temp("weapon");

	me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill*2);

	att = skill;
	if ( att < 45) att = 45;
	if (att >200 ) att = 200;

        me->set_temp("apply/attack", me->query_temp("apply/attack",1)+att*2);

	me->set_temp("apply/dodge", skill*3/2);
	me->set_temp("apply/parry", skill*3/2);

	if( me->query_skill("sword") < 200 )
		message_vision(HIY "$N���һ��������ͻ�䣬"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â��һ����Ϊ�����������������磡\n\n" NOR, me, target);
	else if( me->query_skill("sword") < 300 )
		message_vision(HIY "$N���һ��������ͻ�䣬"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â��һ����Ϊ�����������������磡\n\n" NOR, me, target);
	else if( me->query_skill("sword") < 400 )
		message_vision(HIY "$N���һ��������ͻ�䣬"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â��һ����Ϊ�ġ��彣�������������磡\n\n" NOR, me, target);
	else if( me->query_skill("sword") < 500 )
	{
		message_vision(HIY "$N���һ��������ͻ�䣬"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â��һ����Ϊ�ߡ��˽��������������磡\n\n" NOR, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	else
	{
		message_vision(HIY "$N���һ��������ͻ�䣬"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â��һ����Ϊ�����������Ǽ��������������\n\n" NOR, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -skill*3 );
	me->add("jingli", -skill );
	me->add("jing", -skill );
	me->set_temp("sanqing",1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :),50 );
	return 1;
}

int remove_effect(object me)
{
	me->set_temp("apply/speed", 0);
	me->set_temp("apply/attack", 0);
	me->set_temp("apply/dodge", 0);
	me->set_temp("apply/parry", 0);
	me->delete_temp("sanqing");

	if( me->is_fighting() )
		message_vision(HIG "\n$N����һ�������������ջص������Ҳ�ָ�������\n\n" NOR, me);

	return 0;
}


