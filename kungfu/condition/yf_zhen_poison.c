// yf_zhen_poison.c ����붾
// by April 2001.09.26

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 1;

	if( !living(me) ) {
		message("vision", me->name() + "��ͣ���ڵ���Ť����\n", environment(me), me);
	}
	else {
		tell_object(me, HIW "��Ȼһ������Ѹ�ٴӴ���Ϯ��ȫ�����е�����붾�����ˣ�\n" NOR );
		message("vision", me->name() + "��ͣ����������ץ������ĺ�ӡ��Ŀ���ġ�\n",
			environment(me), me);
	}

	damage = duration;
	damage *= damage;
	damage = random(damage);
	me->receive_wound("jing", damage/2 ,"����붾��������");
	me->receive_wound("qi",damage,"����붾��������");
	
	if (duration >= 10) me->apply_condition("yf_zhen_poison", duration - 1);

	if( duration < 1 ){
		tell_object(me, HIW "���е�����붾���ڻ����ˣ�\n" NOR );
		return 0;
	}
	
	return 1;
}
