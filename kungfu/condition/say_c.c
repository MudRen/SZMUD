// Code of ShenZhou

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
                me->delete_temp("say_msg_cnt", 1);
		tell_object(me, HIC "�㲻Ҫ˵̫��ķϻ���˵һ����͹��ˡ�\n" NOR);
		return 0;
	}
	me->apply_condition("say_c", duration - 1);
	return 1;
}