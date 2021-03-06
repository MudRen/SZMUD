// Code of ShenZhou
///kungfu/skill/duanyun-bian/riyue.c 日月无光
// sdong 09/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int str, dex, skill,power;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("日月无光只能对战斗中的对手使用。\n");


	if( me->query_skill_mapped("force") != "xiantian-gong" )
					 return notify_fail("你所用的并非玄门先天功，施展不出日月无光！\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("你的玄门先天功火候未到，无法施展日月无光！\n");

	if( me->query_skill("whip") < 135 )
		return notify_fail("日月无光需要精湛的断云鞭法方能有效施展！\n");

	// for a 800K player, frce/2 = 150, shen/3K = 300, power = 300
	// for players > 1.2M, power will hit max
	str = me->query_str();
	power = random( me->query("shen") / 3000 ) + me->query("force")/2;
	if(power<150)power=150;
	if(power>480)power=480;

	if( me->query("neili") <= 200+power*2 )
		return notify_fail("你的内力不够使用日月无光！\n");
	if( me->query("jingli") <= power )
		return notify_fail("你的精力不够使用日月无光！\n");


	message_vision(HIW "$N运足内力，猛地一扬"NOR+"$n"+HIW"卷起无边风云遮月掩日，一股"NOR+HIM"罡风"NOR+HIW"随著漫天鞭影扑天盖地的向敌人袭来。\n\n" NOR, me, me->query_temp("weapon"));

	me->add_temp("apply/attack",power/2);
	me->add_temp("apply/damage",power/5);
	target->add_temp("apply/armor",-power/2);
	target->add_temp("apply/dodge",-power);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add_temp("apply/attack",-power/2);
	me->add_temp("apply/damage",-power/5);
	target->add_temp("apply/armor",power/2);
	target->add_temp("apply/dodge",power);

	// modification by chu:
	// The cost was 100 and 50 each, which is too low.  Right now people use
	// riyue to kill opp, perform one after continuously.  
	// now the cost will be around 900 neili 400 jingli, which means high
	// hands can only perform 3, 4 times in a fight
	me->add("neili", -power*2);
	me->add("jingli", -power/2);
	me->start_busy( 1+random(2));
	return 1;
}


