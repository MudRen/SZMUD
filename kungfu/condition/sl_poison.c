// Code of ShenZhou
// shenlong_poison

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "�沿ͻȻ�鴤��һ�¡�\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼ�����ȫ���������еĻ������ƶ������ˣ�\n" NOR );
      message("vision", me->name() + "�Ĳ���ͻȻ���أ���·��ʼҡҡ�λ���������\n",
            environment(me), me);
   }
      me->receive_damage("qi", 25,"�������ƶ�ɢ��ȫ�������");
      me->receive_wound("jing", 15,"�������ƶ�ɢ��ȫ�������");
      me->apply_condition("sl_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


