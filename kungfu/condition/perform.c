// Code of ShenZhou
// perform.c
// update by april 2001.09.15

#include <ansi.h>
#include <login.h>

int update_condition(object me, string skill_type)
{
	if ( !me->is_fighting() )
		return 0;

	if ((int)me->query_condition("qh_poison") ){
		if( me->is_married()){
			me->apply_condition("qh_poison", (int)me->query_condition("qh_poison") +3);
			tell_object(me, HIR "����黨�������ˣ�\n" NOR );
		}
		else {
			me->apply_condition("qh_poison", (int)me->query_condition("qh_poison") +1);
			tell_object(me, HIR "����黨�������ˣ�\n" NOR );
		}
	}

	return 1;
}
