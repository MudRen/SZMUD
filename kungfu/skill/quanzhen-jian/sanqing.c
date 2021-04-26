// Code of ShenZhou
//sanqing.c ��һ�������塹
//by sdong, 06/98
// modified by sdong, 12/24/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_effect(object me, object weapon, int skill);
void check(object me, object weapon, int skill);

int perform(object me, object target)
{
	string weapon;
	int skill, att, time, sp, dp, st, dt;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��һ�������塹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽������ʹ�á�һ�������塹��\n");
                
	if( me->query_temp("sanqing",1) )
		return notify_fail("������ʹ�á�һ�������塹��\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("�����õĲ������칦���޷�ʩչ��һ�������塹��\n");

	if( me->query_skill("xiantian-gong", 1) < 60 )
		return notify_fail("������칦���δ�����޷�ʩչ��һ�������塹��\n");


	if( me->query_skill("sword") < 135 )
		return notify_fail("���ȫ�潣����Ϊ���㣬������ʹ�á�һ�������塹��\n");

	skill =  ( me->query_skill("sword")
		+ me->query_skill("force") ) / 5;

	if ( skill < 50 ) time = 50;
	if ( skill > 100 ) time = 100;
	else time = skill;

	if( me->query("neili") <= skill*3 )
		return notify_fail("�����������ʹ�á�һ�������塹��\n");
	if( me->query("jingli") <= skill )
		return notify_fail("��ľ�������ʹ�á�һ�������塹��\n");
	if( me->query("jing") <= skill )
		return notify_fail("��ľ�����ʹ�á�һ�������塹��\n");

	sp = me->query_temp("apply/speed");
	dp = me->query_temp("apply/dodge"); 
	st = target->query_temp("apply/speed");
	dt = target->query_temp("apply/dodge"); 
	me->add_temp("apply/speed", skill * 5 / 3);

	att = skill;
	if ( att < 50) att = 50;
	if (att > 250 ) att = 250;

        me->add_temp("apply/attack", att * 7 / 3);

	me->add_temp("apply/dodge", skill * 5 / 3);
	me->add_temp("apply/parry", skill * 5 / 3);

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


	if ( random(sp) > random(st) && random(dp) > random(dt) ){
		message_vision(HIY "$n��$N�Ľ���ͻ�䣬һ������һ����"+(me->query_temp("weapon"))->query("name")+HIY"�Ƴ�ѩ����â�����������Լ�������һ����֪����Ǻã�\n\n" NOR, me, target);
		target->start_busy( 1+random(2));
	}
	me->add("neili", -skill*3 );
	me->add("jingli", -skill );
	me->add("jing", -skill );
	me->set_temp("sanqing",1);
	me->set_temp("sanqing_weapon",weapon);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, weapon, skill :),time );
	call_out("check", 1, me, weapon, skill);
	return 1;
}

void remove_effect(object me, object weapon, int skill)
{
	int att = skill;
	if(!me || !me->query_temp("sanqing",1)) return;
	if ( att < 50) att = 50;
	if (att > 250 ) att = 250;
	if ( (!weapon || weapon != me->query_temp("weapon")) && me->query_temp("delete_sanqing"))
		message_vision(HIG "\n$N�����޽�����һ�������塹������˲ʱ����ʧ��\n\n" NOR, me);
	else{
		if( me->is_fighting() )
			message_vision(HIG "\n$N����һ�������������ջص������Ҳ�ָ�������\n\n" NOR, me);
		else message_vision(HIG "\n$N����һ�������������ջص��\n\n" NOR, me);
	}
 	me->add_temp("apply/speed", -skill * 5 / 3);
	me->add_temp("apply/attack", -att * 7 / 3);
	me->add_temp("apply/dodge", -skill * 5 / 3);
	me->add_temp("apply/parry", -skill * 5 / 3);
	me->delete_temp("sanqing");
	me->delete_temp("delete_sanqing");
	me->delete_temp("sanqing_weapon");
	if (wizardp(me)) tell_object(me,HIG"delete sanqing ok!\n"NOR);
}
void check(object me, object weapon, int skill)
{
	if(!me) return;
	if( !objectp(weapon) || me->query_temp("sanqing_weapon") != me->query_temp("weapon") )
	{
		me->set_temp("delete_sanqing",1);
		remove_effect(me, weapon, skill);
		return;
	}
	call_out("check", 1, me, weapon, skill);
}

