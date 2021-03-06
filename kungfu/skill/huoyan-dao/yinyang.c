// Code of ShenZhou
// yinyang.c 阴阳劲
// code by slow

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage, jiali, jiajin, ap, dp, pp,dmg,lvl;
        int     value,level;
        string  msg,msg2,str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("你不是空手。\n");

        if( (lvl=(int)me->query_skill("huoyan-dao", 1)) < 120 )
                return notify_fail("你的火焰刀修为不够。\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
        && me->query_skill_mapped("force") != "longxiang-banruo")
                return notify_fail("你所用内功不对！\n");
              if (me->query("family/family_name") != "雪山派")
          return notify_fail("这是雪山派的独门绝学。\n");

        if( me->query("neili") <= lvl*2 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 150 )
                return notify_fail("你的精力不够！\n");


        
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");

        if ( !me->query("xueshan/yinyang") )
        me->set("xueshan/yinyang",1);
        
        value = me->query("xueshan/yinyang");
        level = value / 100 + 1;

        if (level > 9)
        level = 9;
        
       msg = HIY"$N运起火焰刀第"HIG+chinese_number(level)+"重阴阳劲"+HIY",双掌如抱圆球，内力运出，$n感到有两股至寒至热的内劲\n从不同方向袭来。\n"NOR;
        message_vision(msg, me, target);


        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);   

        ap = (ap+random(ap*2))/2.5;

        if( ap > dp ) {
                damage = 500 + level*(jiali + jiajin/2 + 1000) + lvl * 4;
                dmg = damage;
                damage = (damage + random(damage * 2)) / 2;
                if (damage > dmg )  damage = dmg + random(damage/20);
                
                if (wizardp(me)) printf("damage = %d\n",damage);
                if ((int)damage/target->query("eff_qi")*100>=100) {
                        message_vision(HIR "只见$N的双掌结实的印在$n的胸口,$n口喷鲜血，心脉已被$N震断。\n\n" NOR, me,target);
                        if (target)
                        target->die();
                        return 1;
                }
                
                if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
                        message_vision(HIR "$n直觉心口一震，鲜血已从口中溢出。\n\n" NOR, me,target);
               
                if ((int)damage/target->query("eff_qi")*100<50)
                        message_vision(HIR "$n眼见不妙，运气内功抵御，直觉的两股内劲涌向胸口，不由气血翻腾。\n\n" NOR, me,target);
                
                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", damage/2+random(damage/2), me);
                target->start_busy(1+random(2));   
                
                str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
                message_vision("($N"+str+")\n", target);
                                                                                     // target busy time > own busy time
                me->start_busy(3+random(2));
                if(jiali > me->query("neili"))
                jiali = me->query("neili");
                if(jiajin > me->query("jingli"))
                jiajin = me->query("jingli")-1;
            
                me->add("neili", -jiali-lvl);                                                               // cost neili 140
                me->add("jingli", -jiajin-lvl/2); 
                
                if (target->query("combat_exp") > me->query("combat_exp") && random(level*level*4) == 0 
       && me->query("xueshan/yinyang") < 900 && lvl*5 >(level*60 + 40)) 
                {
                me->set("xueshan/yinyang",value + 1);  
                tell_object(me,HIC"你反复使用阴阳劲，对阴阳二种内力的控制，似乎有了更深的了解。\n"NOR);
                }
         
        }
        else
        {
                message_vision(HIW "$n看破了$N企图，哈哈大笑，随手化解。\n" NOR, me, target);
                me->start_busy(3+random(3));
        
                
        }
      


        return 1;
}
