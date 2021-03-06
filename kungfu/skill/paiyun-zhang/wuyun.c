// Code Of ShenZhou
// 排云掌 - 乌云蔽日
// Keny's Skills

#include <ansi.h>  
inherit F_DBASE; 
inherit F_SSERVER;  

int perform(object me, object target)  
{ 
object weapon; 
int ap,dp, amount,damage,dam;   
string str; 
if( !target ) target = offensive_target(me); 
if( !target   
||      !target->is_character()   
||      !me->is_fighting(target) )  
return notify_fail("「乌云蔽日」只能对战斗中的对手使用。\n");  

if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
return notify_fail("「乌云蔽日」只能空手使用。\n");  

if( me->query_skill_mapped("strike") != "paiyun-zhang" )  
return notify_fail("你所用的并非排云掌，使不出「乌云蔽日」！\n"); 

if( (int)me->query_skill("paiyun-zhang",1) < 300 )  
return notify_fail("你的排云掌火候不够，无法使用「云莱仙境」！\n");

if( me->query("neili") <= 1200 )
return notify_fail("你的内力不够使用「乌云蔽日」！\n");  

if( me->query("jingli") <= 800 )  
return notify_fail("你的精力不够使用「乌云蔽日」！\n");

message_vision(YEL"$N掌使一招"+WHT"「乌云蔽日」"+NOR""+YEL"，此式普出招如奇名，天间好象铸成了一片乌云，$N以惊人速递闪至$n面前，重重的击出五六掌，使$n大吃一惊。\n"NOR,me,target);             

amount = (int)me->query_skill("strike")/4;  
if ( amount < 60 ) amount = 60; 
if ( amount > 100 ) amount = 100; 
me->add_temp("apply/damage",amount*3);     
me->add_temp("apply/attack",amount*4);    
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);    
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 

if (living(target) && !target->is_ghost() && target->query("eff_qi")>=0 && target->query("qi")>=0)      
{    
ap=me->query_skill("strike",1)+me->query_skill("paiyun-zhang")/4; 
dp=target->query_skill("parry",1); 
if ((random(ap)>dp/2)) {   
message_vision(HIW"$P冲前大叫起来，一招"+RED"「虚云劲」"+NOR"当前击去，这一掌好比千千万万的狂气一涌而上，向$n打去。\n" NOR, me, target);       
dam=me->query_skill("paiyun-zhang",1)*(random(3)+2); 
target->receive_wound("qi", dam/2);    
target->receive_damage("qi",dam);  
me->add("neili", -1200); 
me->add("jingli", -500);      
COMBAT_D->report_status(target);   
}   

else       
{    
me->add("neili", 100);  
me->add("jingli", 100);   
target->start_busy(2);   
message_vision(HIY"$p突然闪过一丝的招意，轻轻的一越，跳到了站圈外。\n" NOR,me,target);       
}   
}   
target->start_busy(random(4)+1);   
me->add("neili", -1000);    
me->add("jingli", -400);  
me->add_temp("apply/damage",-amount*3);        
me->add_temp("apply/attack",-amount*4);    
return 1;  
} 
