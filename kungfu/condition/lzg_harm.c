#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      switch(random(5)){
      case 0 :
              msg = HIR"$NͻȻ����һ����ȫ��ľ����޷���ת��\n"NOR;
              me->start_busy(3);
              break;
      case 1 :
              msg = HIR"$NͻȻüͷһ�壬�������������ˣ�\n"NOR;
              me->receive_damage("qi", 200);
              me->receive_wound("qi", 100);
              break;
      case 2 :
              msg = HIR"$N������ͻȻ�������Σ��о���������к��\n"NOR;
              me->receive_damage("neili", 250);
              break;
      case 3 :
              msg = HIR"$NͻȻ����һ�Σ���ʱ������\n"NOR;
              me->receive_damage("jing", 50);
              me->receive_wound("jing", 30);
              break;
      case 4 :
              msg = HIR"$N���»�㱣������ܼ��У�\n"NOR;
              me->receive_damage("jingli", 150);
              break;
      }
      message_vision(msg, me);
      me->apply_condition("lzg_harm", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
        return "hurt";
}
