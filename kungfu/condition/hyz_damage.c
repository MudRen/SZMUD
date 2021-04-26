// Code of ShenZhou
// hyz_damage.c ��Ԫ�޼�����
// qfy Nov 11, 96.

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int amt1, amt2;

   amt1 = me->query("huashan/enemy");
   amt2 = amt1/2;
        
   if( !living(me) ) {
      message("vision", me->name() + "���Ϻ���㣬��ɫ�԰׵ú��ˡ�\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "��Ȼ��һ��ͷ��Ŀѣ�������еĻ�Ԫ�޼������˷����ˣ�\n" NOR );
      message("vision", me->name() + "����ɫͻȻ��Ϊ�԰ף�ҡҡ��׹���ƺ������˷����ˣ�\n",
            environment(me), me);
   }

   me->receive_damage("qi", amt1, "���˷�������");
   me->receive_wound("qi", amt2, "���˷�������");       
   me->apply_condition("hyz_damage", duration - 1);

   if ( !me->query_temp("huashan/hyz_damage") ) {
	me->add_temp("apply/attack", -amt1*2/3);
	me->add_temp("apply/dodge", -amt1*2/3);
	me->set_temp("huashan/hyz_damage", 1);
   }

   if( duration < 1 ) {
	me->delete("huashan/enemy");

	if ( me->query_temp("huashan/hyz_damage") ) {
		me->add_temp("apply/attack", amt1*2/3);
		me->add_temp("apply/dodge", amt1*2/3);
		me->delete_temp("huashan/hyz_damage");
	}

	return 0;
   }

   return CND_CONTINUE;
}