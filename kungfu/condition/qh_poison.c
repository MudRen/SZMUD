//�黨��qh_poison
//�ڱ�Black/2001/8
// update by April 2001.09.15

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
//	int ml;
	
//	ml = me->query("max_neili")/1000;

	if( !living(me) ) message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
	else {
		tell_object(me, HIR"��żȻ������ǰ������ʱ�⣬ͻȻ���黨�̵ĵط�һ���ʹ��\n"NOR);
		message("vision", me->name() + "����¶��ʹ�����飬�����������Ĳ���������\n",
			environment(me), me);
	}

/*
	if(me->query("poisoner")){
		me->receive_damage("qi", 25, me->query("poisoner"));
		me->receive_wound("jing", 15, me->query("poisoner"));
	}
    else{
		me->receive_damage("qi", 25, "�黨����������");
		me->receive_wound("jing", 15, "�黨����������");
	}
*/
	if (!me->is_married()){
//		me->apply_condition("qh_poison", duration - 1);
		me->receive_damage("qi", duration, "�黨����������");
		me->receive_wound("jing", duration*2, "�黨����������");
	}
	else {
		me->receive_damage("qi", duration*3, "�黨����������");
		me->receive_wound("jing", duration*5, "�黨����������");
	}
	
	if(!userp(me)) me->receive_curing("jing", 12);

//  me->apply_condition("qh_poison", duration - 1);
//	if( duration == 1) me->delete("poisoner");

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
