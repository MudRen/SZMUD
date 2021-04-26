// Code of ShenZhou
// killer.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "大理官府不再通缉你了！\n");
                if (me->query("dali/trust") < -100) me->add("dali/trust",100);
		return 0;
	}
	me->apply_condition("dlkiller", duration - 1);
	return 1;
}
