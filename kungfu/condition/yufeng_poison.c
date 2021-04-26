// yufeng_poison.c ��䶾
// by April 01.08.31

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 1;

	if( !living(me) ) {
		message("vision", me->name() + "�ı���üë�·�š��һ���ȥ�ˡ�\n", environment(me), me);
	}
	else {
		tell_object(me, HIW "��Ȼһ�������Ӵ��ں�Ϯ�������е���䶾�����ˣ�\n" NOR );
		message("vision", me->name() + "�����Ӳ�ͣ�ز���������˫�ֲ�ס���Ĵ���ץ��\n",
			environment(me), me);
	}

	damage = duration/3;
	damage *= damage;
	damage = random(damage);
	me->receive_wound("jing", damage ,"��䶾��������");
	
	if (duration == 10) 
		tell_object(me, HIW "��Ȼһ���������Ķ�ȥ��������䶾̫��Ѿ���������Ȼ�����ˣ�\n" NOR );
	else me->apply_condition("yufeng_poison", duration - 1);

	if( duration < 1 ){
		tell_object(me, HIW "������䶾������Ȼ�����ˣ�\n" NOR );
		return 0;
	}
	
	return 1;
}
