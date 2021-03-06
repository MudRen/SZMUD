// Code of Shenzhou
// creat by Karlopex@sz
/*************************************************************************************
perform wuji （「纯阳无极」）--中高手在出神通之前一个重要进攻性pfm，快速攻击一招，威力巨大，但所费内力同样巨大。
条件：纯阳拳等级200，先天功等级200。（注：不是有效等级）
功能：增加20% attack
限制：只可与pfm sanhua 或者 perform yanwu之一组合使用。
      威力巨大，busy时间稍长 20 tick +或至战斗结束。
      所费内力与威力成正比。威力越大，内力需求越多。skill*2
描述：$1运起先天功之纯阳内劲，太阳穴高高鼓起，面如金箔，所发拳招竟带出嗤嗤声响，从不可思议方位向$1击来一招。
***************************************************************************************/               
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string weapon;
	int max_times, st_lvl;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「纯阳无极」只能对战斗中的对手使用。\n");


	if( objectp(me->query_temp("weapon")) )
		return notify_fail("「纯阳无极」需空手才能施展！\n");

	if( me->query_skill_mapped("cuff") != "chunyang-quan" )
		return notify_fail("你所用的并非纯阳拳，不能施展「纯阳无极」！\n");

	if( me->query_temp("cyq-wuji",1) )
		return notify_fail("你已在使用「纯阳无极」，你的功夫不足以再摧动「纯阳无极」！\n");
		
	if( me->query_skill_prepared("cuff") != "chunyang-quan" )
		return notify_fail("你所备的并非纯阳拳，不能施展「纯阳无极」！\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("你所用的并非玄门先天功，施展不出「纯阳无极」！\n");

	if( me->query_skill("xiantian-gong",1) < 199 )
		return notify_fail("你的玄门先天功火候未到，无法施展「纯阳无极」！\n");

	if( me->query_skill("chunyang-quan", 1) < 199 )
		return notify_fail("「纯阳无极」需要精湛的纯阳拳方能有效施展！\n");

	if( me->query("neili") <= 200 )
		return notify_fail("你的内力不够使用「纯阳无极」！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用「纯阳无极」！\n");

	skill = me->query_skill("force")/2 + me->query_skill("cuff") / 2;
	st_lvl = me->query("shentong");
	if (st_lvl > 60) st_lvl -= 60;
	else st_lvl = 0;
	max_times = skill / 100 + st_lvl / 2;
	if (max_times > 10) max_times = 10;
	if( skill > 1000 ) skill = 1000;
	me->set_temp("cyq-wuji/old_attack",me->query_temp("apply/attack"));
	me->set_temp("cyq-wuji/old_damage",me->query_temp("apply/damage"));
	me->set_temp("cyq-wuji/old_speed",me->query_temp("apply/speed"));
	message_vision(HIR "\n\n$N运起先天功之纯阳内劲，太阳穴高高鼓起，面如金箔，所发拳招竟带出嗤嗤声响。\n\n"NOR, me, target);
	me->add_temp("apply/attack" , skill / 10);
	me->add_temp("apply/damage" , skill / 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->set_temp("cyq-wuji/max_times",max_times);
	me->set_temp("perform/chunyangwuji", 1);	
	tell_object(me,HIG"可以用"+chinese_number(max_times)+"招「纯阳无极」。\n"NOR);
	return 1;
}
