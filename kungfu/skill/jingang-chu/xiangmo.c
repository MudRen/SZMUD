//by tracy 1/2002/
//xiangmo.c 金刚降魔 
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int lxbr,nec,damage,amount,quick,ap,dp;
string str = @TEXT
                                                |\
                .-':'"": - -   -  -   : -  \ (1\.`-.  
              .'`.  `.  :  :  :   :   : : : : : :  .';
             :-`. :   .  : :  `.  :   : :.   : :`.`.o ;
             : ;-. `-.-._.  :  :   :  ::. .' `. `., =  ;
             :-:.` .-. _-.,  :  :  : ::,.'.-' ;-. ,'''"
           .'.' ;`. .-' `-.:  :  : : :;.-'.-.'   `-'
    :.   .'.'.-' .'`-.' -._;..:---'''"~;._.-;
    :`--'.'  : :'     ;`-.;            :.`.-'`. 
     `'"`    : :      ;`.;             :=; `.-'`.
             : '.    :  ;              :-:   `._-`.
              `'"'    `. `.            `--'     `._;  
                        ''''   
TEXT;
        if (!target) target = offensive_target(me);
        if (!target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『金刚降魔』只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!wizardp(me)) return 0;
        if (!objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("你手中无杵，如何降魔？\n");
        if (me->query_skill_mapped("force") != "longxiang-banruo")
                return notify_fail("你所用的并非龙象般若功，无法施展降魔绝技！\n");
        if (me->query_skill("longxiang-banruo", 1) < 150)
                return notify_fail("你的龙象般若功火候未到，无法施展降魔绝技！\n");
        if (me->query_skill("jingang-chu", 1) < 150)
                return notify_fail("你的金刚降魔杵火候未到，无法施展降魔绝技！\n");
        if (me->query_skill("necromancy",1) < 200)
                return notify_fail("你降伏法修为不够，如何降伏他人？\n");
        if (me->query("neili") <= 1000)
                return notify_fail("你的内力不够使用『金刚降魔』！\n");
        if (me->query("jingli") <= 1000)
                return notify_fail("你的精力不够使用『金刚降魔』！\n");
        if( me->query_temp("xiangmo_busy",1) )
                return notify_fail("你想再使用降伏大法，却怎么也使不出来！\n");  
        if( target->is_busy() ) 
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n"); 
        nec = me->query_skill("necromancy",1);
        quick = (int)(me->query_skill("longxiang-banruo",1)/100);
        if (quick < 2) quick = 2;
        amount = (int)me->query_skill("staff")/4;
        if (amount < 60) amount = 60;
        if (amount > 100) amount = 100;  
        me->add_temp("apply/damage", amount);
        me->add_temp("apply/attack", amount*2);
        me->set_temp("xiangmo_busy",1);
        message_vision(HIR"\n$N大呼酣战，口念密宗不动明王真言，使出『金刚降魔』大法。\n"NOR,me,target);
        message_vision("$N一声高呼，身形陡转，犹如雪豹下山。\n",me,target);
        message_vision(HIW+str+NOR,me,target);
        ap = nec + quick*100+amount;
        dp = target->query_skill("force");
        damage = 0;
          if(random(ap)>dp/2)
          {     
                damage=me->query_skill("jingang-chu",1)*(random(4)+5);     
                if (damage<500) damage=500;
                if (weapon->query("id")=="xiangmo chu") damage*=3/2;              
                if (damage>target->query("jingli")) 
                {   
     message_vision(HIR"\n$n见此情景，已不知所措，只觉头昏眼花，完全被$N降伏。\n"NOR, me,target); 
                        target->receive_wound("qi", random(damage/2), me);                                 
                        target->receive_damage("jingli",target->query("jingli")+1,me);
                }   
                else
                {                    message_vision(HIR"\n$n见此情景，极力摆脱，结果精力大耗才跳出$N的降魔幻影。\n"NOR,me,target);                       
                        target->receive_damage("jingli", damage, me);
                        target->receive_wound("qi", random(damage/2), me);  
                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                        target->start_busy(random(4));
     message_vision(HIR"\n$N见$n漏出破绽，高举手中"+weapon->query("name")+HIR"向$n袭来。\n"NOR,me,target);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                }                         
          } 
          else 
          {
     message_vision(HIR"$n见此情景，冥思一翻，终于识破了$N的降魔幻影。\n"NOR, me, target);  
     message_vision("只见$n不退反进，身如飘风，反而向$N发起进攻,$N顿时不知所措。\n",me,target);
                        me->start_busy(2+random(2));
          }
                 me->add_temp("apply/damage", -amount);
                 me->add_temp("apply/attack", -amount*2);
                 me->add("neili", -me->query("jiali")-500);
                 me->add("jingli", -me->query("jiajin")-400);     
                 call_out("remove_effect", random(9-quick), me);
                 if (wizardp(me)) write(sprintf("quick=%d ap=%d dp=%d damage=%d\n",quick,ap,dp,damage)); 
                 return 1;
}
void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("xiangmo_busy");
        tell_object(me, HIY"\n你调息片刻，降伏大法又可收放自如了。\n"NOR); 
}
