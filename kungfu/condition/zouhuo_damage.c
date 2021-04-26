// �߻���ħ	zouhuo_damage.c
// April 2001.09.23

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
	else {
		tell_object(me, HIR"�����޷����������������������ڱ��尾һ�㡣\n"NOR);
		message("vision", me->name() + "��ɫ���࣬����ĺ��鲻�ϴӶ�ͷ���䡣\n",
			environment(me), me);
	}

	me->receive_wound("qi", random(duration*3), "�߻���ħ����");
	me->apply_condition("zouhuo_damage", duration - 1);
	
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
