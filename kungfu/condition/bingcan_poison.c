// Code of ShenZhou
//rama@sz modified from xx_poison
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
//      int ml;
//      ml = me->query("max_neili")/1000;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然一阵刺骨的奇寒袭来，你中的冰蚕剧毒发作了！\n" NOR );
      message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
            environment(me), me);
   }
   if(me->query("poisoner")){
      me->receive_damage("qi",random(duration)/2+10,me->query("poisoner"));
      me->receive_wound("jing",random(duration)/2+10,me->query("poisoner"));
      me->receive_wound("jing",random(duration)/2+10,me->query("poisoner"));
        }
        else{
      me->receive_damage("qi", random(duration)/2+10, "冰蚕剧毒攻心死了");
      me->receive_wound("jing", random(duration)/2+10,"冰蚕剧毒攻心死了");
        }
//   if(!userp(me)) me->receive_curing("jing", 12);

      me->apply_condition("bingcan_poison", duration - 1);
//    me->apply_condition("xx_poison", duration - 1); 
        
   if( duration == 1) me->delete("poisoner");

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

