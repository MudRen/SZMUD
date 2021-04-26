// Code of ShenZhou
// /kungfu/condition/biao.c
// sdong, 12/12/98

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

	me->apply_condition("wuguan_job", duration - 1);

	if( duration < 1 )
	{
		call_out("let_know",1,me);
		return 0;
	}
	return CND_CONTINUE;
}

void let_know(object me)
{
		string job_stat = me->query_temp("wuguan_job");

		if ( sizeof(job_stat) < 5 ) {
		tell_object(me, HIG "�������룬��û��ʲô�ط�û��ȥ��\n" NOR);
		}else{
		tell_object(me, HIG "����Ի�ȥ�����ˣ�\n" NOR);
		}
}                                                           