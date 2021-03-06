// Code Of ShenZhou
// 排云掌 - 「云莱仙境」
// Keny's Skills

#include <ansi.h> 
inherit F_SSERVER; 

int perform(object me, object target) 
{ 
string msg; 
int damage; 
object weapon,ob; 
int skill, jiali, my_rate, your_rate; 

jiali=(int)me->query("jiali"); 
weapon = me->query_temp("weapon"); 

if(me->is_busy()) 
return notify_fail("你正忙着呢！\n"); 

if( !target ) target = offensive_target(me); 
if( !target 
||      !target->is_character() 
||      !me->is_fighting(target) ) 
return notify_fail("「云莱仙境」只能在战斗中使用。\n"); 

if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
return notify_fail("「云莱仙境」只能空手使用。\n"); 

if( me->query_skill_mapped("strike") != "paiyun-zhang" ) 
return notify_fail("你所用的并非排云掌，使不出「云莱仙境」！\n"); 

if( (int)me->query_skill("paiyun-zhang",1) < 200 ) 
return notify_fail("你的排云掌火候不够，无法使用「云莱仙境」！\n"); 

msg = HIG "\$N运功股动内力造成了一个股霞气丛丛的包围了$n，$n突间感到全神被硬掌击中，原来$N已使出了排云掌中的奇招"+MAG"「云莱仙境」"+NOR"\n" NOR; 
msg += RED "$N突然出现在$n的面前，暗自调运真气凝气于掌,只见$N一声清啸，双掌飞舞，掌势菲而所思。\n"NOR;  

if( random( me->query("combat_exp") ) > random( target->query("combat_exp") ) || !living(target) ) 
{ 
damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")*10) ) ; 
if(damage > 4000) damage = 5000; 
if(damage < 1000) damage = 2000; 
me->add("neili", -1000 ); 
me->add("jingli", -500); 

target->receive_damage("qi", damage,  me); 
target->receive_wound("qi", random(damage), me); 
target->start_busy(1+random(3)); 

msg += HIR"\n$N趁$n手忙脚乱之际，纵身跃至$n身前劈面击出左掌,右掌同时按向$n的小腹。\n"NOR; 

msg += NOR; 
me->start_busy(2+random(2)); 
} 

else { 
msg += HIY"\n$n突然闪过一丝的招意，轻轻的一越，跳到了站圈外。\n\n"NOR; 
me->add("neili", -jiali*2 ); 
me->add("jingli", -me->query("jiajin") ); 
me->start_busy(2 + random(2)); 
message_vision(msg+"\n", me, target); 
return 1; 
} 

message_vision(msg+"\n", me, target); 
COMBAT_D->report_status(target); 
return 1; 
} 
