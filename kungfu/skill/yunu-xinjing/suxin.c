// Code of ShenZhou
// suxin.c
// slow 31/5/02

#include <ansi.h>

int exert(object me, object target)
{
        int level = me->query_skill("yunu-xinjing", 1);

        if (level < 120) return notify_fail("你的内功修为还不够。\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("你的内力还不够强。\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("你的真气不够。\n");
	
        if ( me->query_temp("ngsuxin") )
                return notify_fail("你此时正在按玉女心经的心法行功。\n");

        me->set_temp("ngsuxin", 1);
write( HIW "你暗运玉女素心心法，把多年修炼的“十二少、十二多”的正反要诀发挥到极致。\n" NOR);
	message("vision",
             HIW + "只见" + me->name() + "微闭双眼，无喜无乐，无思无虑,把多年修炼的“十二少、十二多”的正反要诀发挥到极致。\n" NOR,
		environment(me), me);

	me->add("neili", -level);
        me->add_temp("apply/armor",  level);
        me->add_temp("apply/defense",  level);

	me->start_call_out( (: call_other, __FILE__, "recover", me, level :), 500);

	return 1;
}

void recover(object me, int level)
{
        me->delete_temp("ngsuxin");
        me->add_temp("apply/armor",  -level);
        me->add_temp("apply/defense",  -level);

        tell_object(me, HIG"你行功已久，慢慢收回玉女素心的心法。\n"NOR);
}
