// Code of ShenZhou
// killer.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
                tell_object(me, "���������־�ֹͣ�˶����׷ɱ��\n");
		return 0;
	}
        me->apply_condition("bjkiller", duration - 1);
	return 1;
}
