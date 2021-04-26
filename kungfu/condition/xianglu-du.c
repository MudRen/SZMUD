// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int neili;
//      int ml;
//      ml = me->query("max_neili")/1000;
	if( !living(me) ) {
     		message_vision(me->name() + "ʹ��غ���һ����\n", environment(me), me);
   	}
   	else {
      		tell_object(me, HIG"���˿�ͻȻһ����ľ��һ����Ϯ�������Ӳ��ɵ�һ�Σ�\n" NOR );
      		message("vision", me->name() + "������ͻȻ�������Σ��˿��з���һ������\n",environment(me), me);
   	}
   	
   	neili=me->query("neili")-100;
   	
   	if(neili<0) {
   		me->set("neili",0);
   		neili=me->query("jingli")-100;
   		if(neili<0) {
   			neili==0;
   			me->set("jingli",0);
   			me->unconcious();
   		} else me->set("jingli",neili);
   	} else me->set("neili",neili);  	
   	
   	me->receive_wound("jing", random(10),"��¶������������");
      	me->receive_wound("qi", random(10),"��¶������������");
	me->receive_damage("qi", random(10),"��¶������������");
	
      	me->apply_condition("xianglu_du", duration - random(1));
	        
   	if( duration == 1) me->delete("poisoner");

   	if( duration < 1 ) return 0;
   
   return CND_CONTINUE;
}
