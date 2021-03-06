// Code Of ShenZhou
// 两仪剑 无声无色(Perform wushengse)
// by keny, earl

#include <ansi.h>
inherit F_SSERVER;

void remove_temp(object me)
{
if (me->query_temp("pfm_wushengse"))
me->delete_temp("pfm_wushengse");
}

int perform(object me, object target)
{
object weapon; 
int amount,damage; 

if (me->query_temp("pfm_wushengse"))
{
return notify_fail("你的敌人已明了到你有此拙了，等他掉淡了才出击吧！ \n");
}

if ( !target ) target = offensive_target(me);

if( !target || !target->is_character()) 
return notify_fail("你想对谁人施出此技？\n");

if( environment(target)->query("no_fight")) 
return notify_fail("小心打破东西了。\n"); 

if(target->query_temp("surrender/ownder")!=0) 
return notify_fail("你现在不能在他身上施出此技!"); 

if( me->query_skill("sword") < 150 )
return notify_fail("你的两仪剑法不够，无法令悟此技精髓。\n"); 

if( me->query_skill("force") < 200 ) 
return notify_fail("内功比外功还要重要吧？我看你还是在内功上花点时间吧。\n"); 

if (me->query("neili") < 600) 
return notify_fail("你的内力不够，无法施技。\n"); 

amount = (int)me->query_skill("sword")/4;
if ( amount < 60 ) amount = 60; 
if ( amount > 100 ) amount = 100;
me->add_temp("apply/damage",amount*2);
me->add_temp("apply/attack",amount*3); 

if(target->query("combat_exp") < me->query("combat_exp")) 
{
message_vision(HIG"\n$N紧握著"+(me->query_temp("weapon"))->query("name")+HIG"，突然使出昆仑派剑学中的绝招"+HIC"“无声无色”，"+HIG"同时疾向$n背后刺去。\n" NOR, me, target); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
}

else {
message_vision(HIY"\n$n见此招凶猛，高高翻身退到一丈外，躲过了此技。\n"NOR,me,target);
}

me->set_temp("pfm_wushengse", 1); 
call_out("remove_temp", 5, me); 
target->kill_ob(me); 
me->add("neili", -400); 
me->add("jingli", -400); 
me->add_temp("apply/damage",-amount*2); 
me->add_temp("apply/attack",-amount*3);
return 1;
}
