// Code of ShenZhou
// killer.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "���Ĺٸ�����ͨ�����ˣ�\n");
		return 0;
	}
	me->apply_condition("xakiller", duration - 1);
	return 1;
}
