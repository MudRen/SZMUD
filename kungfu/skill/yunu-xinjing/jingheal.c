// jingheal.c
// by April 2001.11.01

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )	return notify_fail("战斗中运功疗精？找死吗？\n");

	if ((int)me->query_skill("yunu-xinjing", 1) < 60)
		return notify_fail("你的玉女心经修为还不够。\n");

	if ((int)me->query_skill("suxin-jue", 1) < 30)
		return notify_fail("你的素心诀还不够。\n");

	if( (int)me->query("jingli") < 200 )
		return notify_fail("你的精力不够。\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
		return notify_fail("你现在不须要疗精！\n");

	write( HIW "你潜心默化，气沉丹田，以素心诀凝神疗精……\n" NOR);
	message("vision",
		HIW + me->name() + "沉默下来潜心默化，气沉丹田，以素心诀凝神疗精……\n" NOR,
		environment(me), me);

	me->receive_curing("jing", (int)(me->query_skill("force")+me->query_skill("suxin-jue",1))/10);
	me->add("neili",-100);
	me->add("jingli",-50);
	me->set("jiali", 0);

	return 1;
}
