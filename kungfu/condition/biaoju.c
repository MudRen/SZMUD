// Code of ShenZhou
// /kungfu/condition/biaoju.c
// sdong, 12/12/98

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

	me->apply_condition("biaoju", duration - 1);

	if( duration < 1 )
	{
		call_out("let_know",1,me);
		return 0;
	}
	return CND_CONTINUE;
}

void let_know(object me)
{
		tell_object(me, HIR "��̧ͷ���˿���գ����������ӣ�ͻȻ����ʱ���ѵ����浹ù��\n" NOR);

		if( me->query("biao") )
		{
			 me->delete("biao");
			 me->set("biao/fail",1);
		}

		if( me->query("xbiao") )
		{
			 me->delete("xbiao");
			 me->set("xbiao/fail",1);
		}
		me->remove_all_killer();
}


