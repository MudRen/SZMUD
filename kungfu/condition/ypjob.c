// Code of ShenZhou
//Ryu

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("ypjob", duration - 1);
	if (duration == 1 ){
	me->add("yipin/failure", 1);
	tell_object(me, "������ʱ���ѵ���\n");
	me->apply_condition("ypjob", 0);
	return 1; 
	}
	return 1;
}
