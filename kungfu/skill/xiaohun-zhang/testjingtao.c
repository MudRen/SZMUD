       // Code by Slow
     
#include <ansi.h>
      inherit F_DBASE; 
      inherit F_SSERVER; 
       
      int perform(object me, object target) 
      { 
              object weapon; 
              int myexp, targexp, damage, skill, merand, targrand, targneili,time,i; 
              string str,*limb,type; 
              mapping myfam; 
              int tmp_jiali,dmg;
         int num;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「怒海惊涛」只能对战斗中的对手使用。\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "古墓派") )
                  return notify_fail("只有古墓弟子才能用「怒海惊涛」。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("空手才能施展「怒海惊涛」！\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" )
                return notify_fail("你所用的并非玉女心经，使不出「怒海惊涛」！\n");

        if( (int)me->query_skill("yunu-xinjing",1) < 120 )
                return notify_fail("你内功修为太差，不能运用「怒海惊涛」！\n");

        if( me->query_skill("xiaohun-zhang",1) < 120 )
                return notify_fail("你黯然销魂掌修为太差，不能运用「怒海惊涛」！\n");
         if ( !living(target))    
              return notify_fail("现在不没必要用「怒海惊涛」把！\n");  
          if (me->query_temp("jingtao_time"))
                return notify_fail("「怒海惊涛」消耗内力巨大，不能频繁使用！\n");
         if (!me->query("canjingtao"))
           return notify_fail("你现在还没学会！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用「怒海惊涛」！\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("你的精力不够使用「怒海惊涛」！\n");     
      if( me->query("jing") <= 200 )
               return notify_fail("你的精不够使用「怒海惊涛」！\n");
          if( me->query_skill_prepared("cuff") == "meinu-quan" ) {
          me->set_temp("restore", 1);
          me->prepare_skill("cuff");
          }
message_vision(HIR"\n$N的掌风隐隐带着潮涌之声，掌风鼓荡，竟似有狂潮涌来，这正是神雕大侠当年在大海中练出的绝技。 \n"NOR,me,target);
message_vision(HIG"\n$N见$n和身扑上，当即退步避开，跟着“魂不守舍”、“倒行逆施”、“若有所失”，连出三招。\n"NOR,me,target);
message_vision(HIG"跟着是一招“行尸走肉”，踢出一脚。\n"NOR,me,target);
        skill=me->query_skill("xiaohun-zhang",1);
         num=(int)(skill/5);
             tmp_jiali=me->query("jiali");
        me->set("jiali",0);
        me->add_temp("apply/strength",num);
        me->add_temp("apply/damage",(num*3+40));
        me->add_temp("apply/attack",num);
        me->set_temp("perform/jingtao",1);
        me->set_temp("jingtao_time",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           me->add_temp("perform/jingtao",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           me->add_temp("perform/jingtao",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("perform/jingtao",1);
        me->add_temp("apply/strength",-num);
        me->add_temp("apply/attack",-num);
        me->add_temp("apply/damage",-(3*num+40));
          me->delete_temp("perform/jingtao");
        if (random(me->query("combat_exp")*2)>target->query("combat_exp"))
//        && skill>200 && random(2)=0)
          {
            message_vision(HIB"$N这一脚发出时恍恍惚惚，隐隐约约，若有若无，$n那里避得过了？砰的一响，正中胸口。\n"NOR,me,target);
            message_vision(HIB"$n大叫一声，一口鲜血喷出!\n"NOR,me,target);
              dmg = me->query_skill("force")+me->query_skill("strike")+me->query("jiajin");
              dmg = dmg + random(dmg*2);   
              target->receive_damage("qi", dmg,  me);
              target->receive_wound("qi", random(dmg), me);
          COMBAT_D->report_status(target); 
          }
          else {
            message_vision(HIB"$n见此招飘忽不定，暗道:“厉害！“，急退数丈避开。\n"NOR,me,target);
           me->start_busy(1+random(2));
            }
        me->add("neili", -350);
        me->add("jingli", -150);
         me->set("jiali",tmp_jiali);
        

        if( me->query_temp("restore") ) me->prepare_skill("cuff", "meinu-quan");
                        
           call_out("remove_effect",5,me);

        return 1;
}        
void  remove_effect(object me)
{
       me->delete_temp("jingtao_time");
}
