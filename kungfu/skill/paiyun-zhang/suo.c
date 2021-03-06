// Code Of ShenZhou
// 排云掌 - 从云心锁
// Keny's Skills

#include <ansi.h> 
inherit F_SSERVER;

int perform(object me, object target) 
{        
int mywx; 
string msg; 
object weapon; 
if( !target ) target = offensive_target(me); 
if( !target 
||      !target->is_character() 
||      !me->is_fighting(target) ) 
return notify_fail("「从云心锁」只能对战斗中的对手使用。\n"); 

if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))  
return notify_fail("「从云心锁」只能空手使用。\n"); 

if( me->query_skill_mapped("strike") != "paiyun-zhang" )  
return notify_fail("你所用的并非排云掌，使不出「从云心锁」！\n");  

if( me->query("neili") <= 200 )  
return notify_fail("你的内力不够使用「从云心锁」！\n");  

if( me->query("jingli") <= 100 )  
return notify_fail("你的精力不够使用「从云心锁」！\n");     

if( (int)me->query_skill("paiyun-zhang",1) < 70 )  
return notify_fail("你的排云掌火候不够，无法使用「从云心锁」！\n");  

if( target->is_busy() ) { 
me->add("neili", 10); 
me->add("jingli", 5); 
return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n"); 
} 

msg = HIC"$N一式"+NOR""+CYN"「从云心锁」"+NOR"，"+HIC"旋力发于双掌，力道横行已将$n的攻击化为零，讯间再连起了四、五掌击于$n！\n"; 
me->add("neili", -50); 
me->add("jingli", -20); 
mywx = me->query_int(); 
if( random( me->query("combat_exp") ) > random( target->query("combat_exp") ) || !living(target) ) 
{
msg += HIY"结果$p被$P缠了个手忙脚乱，一时无法还招进攻！\n" NOR; 
target->start_busy(12); 
} else { 
msg += HIY"$p双手一移，轻轻的避过了$P的进攻。\n" NOR; 
me->start_busy(1+random(3)); 
} 
message_vision(msg, me, target); 
return 1; 
} 
