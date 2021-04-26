// Code of ShenZhou
// /kungfu/condition/b_ciwan.c
// wzfeng 2000 10

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

        if(!me) return 1;
	me->apply_condition("b_ciwan", duration - 1);
	printf("����ʱ�仹��		%d\n",duration);
	if( duration < 2 )
	{
		call_out("let_know",1,me);
		return 0;
	}
	return CND_CONTINUE;
}

void let_know(object me)
{
	int amount;
	if ( !me ) return;
	amount = me->query_temp( "ciwan_power" );

        me->add_temp("apply/parry", amount);
	    me->delete_temp("pixie/ciwan");
		me->delete_temp("pixie_times/ciwan");
		me->delete_temp("cannot_perform");
		me->delete_temp("cannot_perform_msg");
		me->delete_temp("ciwan_power");
        
		 if(me->is_fighting() )
			{
			me->start_busy(1 + random(1));
			message_vision(HIG"$N�忪����Ѩ����˫���ж��𽥻ָ�������\n"NOR,me  );
			}
		 else
			 message_vision(HIG"$N���ڳ忪����Ѩ����\n"NOR,me  );
}

