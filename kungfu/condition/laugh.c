// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int neili, poison;

	if( !living(me) ) {
     		message_vision(HIY"$N����һ�������˯���з���������Ц����\n", environment(me), me);
   	}
   	else {
   		     		
  		message_vision(HIY"$NͻȻ������Ĵ�Ц����������ȴ¶��ʹ�����ɫ��\n",environment(me), me);	                    		   	
   	        
   	}
   	   	
   	me->start_busy(3);
   	
   	me->apply_condition("laugh", duration - random(5));
	
	
	if (me->query("combat_exp")>100000)
		me->add("jing", -25);		

   	if( duration < 1 ) {
   		message_vision(HIG"$N�����������������ڵĺ����Ѿ���Ȼ�޴档"NOR,me);	
   		return 0;
   	}
   	
   return CND_CONTINUE;
}
