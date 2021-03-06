// Code of ShenZhou
//sanqing.c 「一剑化三清」
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
		return notify_fail("「一剑化三清」只能对战斗中的对手使用。\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得「一剑化三清」？\n");
                
	if( me->query_temp("sanqing",1) )
		return notify_fail("你已在使用「一剑化三清」！\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("你所用的并非先天功，无法施展「一剑化三清」！\n");

	if( me->query_skill("xiantian-gong", 1) < 60 )
		return notify_fail("你的先天功火候未到，无法施展「一剑化三清」！\n");


	if( me->query_skill("sword") < 135 )
		return notify_fail("你的全真剑法修为不足，还不会使用「一剑化三清」！\n");

	skill =  ( me->query_skill("sword")
		+ me->query_skill("force") ) / 5;

	if ( skill < 50 ) time = 50;
	if ( skill > 100 ) time = 100;
	else time = skill;

	if( me->query("neili") <= skill*3 )
		return notify_fail("你的内力不够使用「一剑化三清」！\n");
	if( me->query("jingli") <= skill )
		return notify_fail("你的精力不够使用「一剑化三清」！\n");
	if( me->query("jing") <= skill )
		return notify_fail("你的精不够使用「一剑化三清」！\n");

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
		message_vision(HIY "$N大喝一声，剑招突变，"+(me->query_temp("weapon"))->query("name")+HIY"逼出雪亮光芒，一剑化为二剑，剑剑快似闪电！\n\n" NOR, me, target);
	else if( me->query_skill("sword") < 300 )
		message_vision(HIY "$N大喝一声，剑招突变，"+(me->query_temp("weapon"))->query("name")+HIY"逼出雪亮光芒，一剑化为三剑，剑剑快似闪电！\n\n" NOR, me, target);
	else if( me->query_skill("sword") < 400 )
		message_vision(HIY "$N大喝一声，剑招突变，"+(me->query_temp("weapon"))->query("name")+HIY"逼出雪亮光芒，一剑化为四、五剑，剑剑快似闪电！\n\n" NOR, me, target);
	else if( me->query_skill("sword") < 500 )
	{
		message_vision(HIY "$N大喝一声，剑招突变，"+(me->query_temp("weapon"))->query("name")+HIY"逼出雪亮光芒，一剑化为七、八剑，剑剑快似闪电！\n\n" NOR, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	else
	{
		message_vision(HIY "$N大喝一声，剑招突变，"+(me->query_temp("weapon"))->query("name")+HIY"逼出雪亮光芒，一剑化为无数剑，霎那间漫天电闪雷鸣！\n\n" NOR, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


	if ( random(sp) > random(st) && random(dp) > random(dt) ){
		message_vision(HIY "$n见$N的剑招突变，一剑快似一剑，"+(me->query_temp("weapon"))->query("name")+HIY"逼出雪亮光芒，剑剑朝向自己攻来，一进不知如何是好！\n\n" NOR, me, target);
		target->start_busy( 1+random(2));
	}
	me->add("neili", -att*2 );
	me->add("jingli", -att );
	me->add("jing", -att );
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
		message_vision(HIG "\n$N手中无剑，「一剑化三清」的威力瞬时间消失。\n\n" NOR, me);
	else{
		if( me->is_fighting() )
			message_vision(HIG "\n$N吸了一口气，将内力收回丹田，剑招也恢复正常！\n\n" NOR, me);
		else message_vision(HIG "\n$N吸了一口气，将内力收回丹田。\n\n" NOR, me);
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

