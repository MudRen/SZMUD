// Code of ShenZhou

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{	
   int cost, gene;

   if (!me->is_fighting()) {
	tell_object(me, GRN "�㽫���л㼯�������ջص��\n" NOR );
	me->apply_condition("neili_save", 0);
	return 0;
   }
   if( !living(me) ) {
      message(HIR"vision", me->name() + "������Ѫ���硣\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIG "��е��������������л㼯��\n" NOR );
      message_vision(HIG"$N������âԽ��Խʢ����Ե���һƬ����ͬ����һ�㣡\n"NOR,me);
   }
   
   cost = (int)me->query_condition("neili_save");
   if ( me->query("neili") > 0 && me->query("qi") > cost*3/2 ) {
	gene = (int)me->query("th_jianyi");
	me->apply_condition("neili_save", cost+100*gene);
	me->add("neili", -100*gene);
   } else {
      	message(HIR"vision", me->name() + "������Ѫ���硣\n"NOR,environment(me), me);	
	me->receive_damage("qi", cost/2,"����ʧ�أ��߻���ħ����");
   }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
