// Code of ShenZhou
// huaying.c 分身化影
// by Felix 5/2002

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int tddg);

int exert(object me, object target)
{
	int ddg, tddg, time;

	if( me->query("family/family_name") != "少林派")
		return notify_fail("你不是少林弟子如何能施展分身化影？\n");

	if( me->query_skill("shaolin-shenfa", 1) < 100)
		return notify_fail("你的少林身法火候未到，无法施展分身化影！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 100)
		return notify_fail("你的混元一气修为还不够，无法施展分身化影！\n");

	if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
		return notify_fail("你所用的并非混元一气功，无法施展分身化影！\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("你已经发动了金刚伏魔神通，不能同时施展分身化影！\n");

	if( (int)me->query_temp("huaying") )
		return notify_fail("你已经在施展分身化影！\n");

	time = me->query_skill("shaolin-shenfa", 1)/30;
	if ( time < 3) time = 3;
	if ( time > 10) time = 10;
	
	ddg = me->query_skill("dodge");

	tddg = me->set_temp("apply/dodge", ddg*11/10);

	me->add("neili", -50);

	message_vision(YEL
	"\n$N深吸一口气，运步如飞激得脚下尘土飞扬，渐渐已舞成一团灰影，令人眼花撩乱。\n"NOR, me);

	me->set_temp("huaying", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :),time );

	return 1;
}

void remove_effect(object me, int tddg)
{
	me->set_temp("apply/dodge", tddg*10/11);

	me->delete_temp("huaying");

	message_vision(YEL
		"\n只见灰影渐渐散去，$N站定恢复了身形。\n"NOR, me);
}