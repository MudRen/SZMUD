#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      switch(random(5)){
      case 0 :
              msg = HIR"$N突然脚下一慢，全身的经脉无法运转！\n"NOR;
              me->start_busy(3);
              break;
      case 1 :
              msg = HIR"$N突然眉头一皱，好象是受了内伤！\n"NOR;
              me->receive_damage("qi", 200);
              me->receive_wound("qi", 100);
              break;
      case 2 :
              msg = HIR"$N的身子突然晃了两晃，感觉到内力外泻！\n"NOR;
              me->receive_damage("neili", 250);
              break;
      case 3 :
              msg = HIR"$N突然脚下一晃，顿时精神不振！\n"NOR;
              me->receive_damage("jing", 50);
              me->receive_wound("jing", 30);
              break;
      case 4 :
              msg = HIR"$N脚下恍惚，精神不能集中！\n"NOR;
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
