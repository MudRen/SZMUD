// 走火入魔	zouhuo_damage.c
// April 2001.09.23

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	else {
		tell_object(me, HIR"你已无法控制内力，五脏六腑象在被煎熬一般。\n"NOR);
		message("vision", me->name() + "脸色发青，豆大的汗珠不断从额头滚落。\n",
			environment(me), me);
	}

	me->receive_wound("qi", random(duration*3), "走火入魔死了");
	me->apply_condition("zouhuo_damage", duration - 1);
	
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
