// Code Of ShenZhou 
// by keny 
// perform tianjing （石破天惊） 
//  条件：震天拳法200级，玄天无极200级。 
// 描述：$1双眼圆睁怒喝一声，犹如平地暴雷般震得人心胆俱裂。 
// $1携暴喝之威，带重重拳影以昆仑雪崩、石破天惊之势砸了下来，惊得$2如木人般定在当场，不知如何招架。 
// 描述 by lnere 
 
#include <ansi.h>  
#include <combat.h>  
inherit F_SSERVER;  

int perform(object me, object target)  
{  
int skill;
string msg;

if( !target ) target = offensive_target(me);  
if( !target || !target->is_character() || !me->is_fighting(target) )  
return notify_fail("「石破天惊」只能对战斗中的对手使用。\n");  

if( objectp(me->query_temp("weapon")) )  
return notify_fail("你必须空手才能使用「石破天惊」！\n");                 

if( me->query_temp("quanjing")) 
return notify_fail("你真气凝聚在体内未散，不能同时运再真气施展「石破天惊」！\n"); 

if( me->query_temp("liushui")) 
return notify_fail("你真气凝聚在体内未散，不能同时运再真气施展「石破天惊」！\n"); 

if( me->query_temp("tianjing")) 
return notify_fail("你正在施展「石破天惊」！\n");


if( (int)me->query_skill("zhentian-quan", 1) < 200 )  
return notify_fail("你的「震天拳」火侯不够!\n");  

if( (int)me->query_skill("xuantian-wuji", 1) < 200 )  
return notify_fail("你的「玄天无极」火侯不够!\n");

if( (int)me->query("neili", 1) < 1000 )  
return notify_fail("你现在内力太弱，不能使用「石破天惊」!\n");  

if( (int)me->query("jingli", 1) < 500 )  
return notify_fail("你现在精力太弱，不能使用「石破天惊」!\n"); 

message_vision(RED"\n$N双眼圆睁怒喝一声，犹如平地暴雷般震得人心胆俱裂。\n" NOR, me);  
message_vision(HIR"\n$N携暴喝之威，带重重拳影以昆仑雪崩、石破天惊之势砸了下来，惊得$n如木人般定在当场，不知如何招架。\n" NOR, me); 

me->set_temp("tianjing", 1); 

skill =  ( me->query_skill("zhentian-quan") 
+ me->query_skill("cuff") ) / 2; 

me->add_temp("apply/attack", skill/3); 
me->add_temp("apply/damage",  skill/6); 
me->add_temp("apply/dodge",  skill/2);
me->add_temp("apply/speed", 100); 

COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

me->add("neili", -1000); 
me->add("jingli", -500);  
me->start_busy(random(2)); 

me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/5); 
return 1; 
} 

private int remove_effect(object me, int amount) 
{ 
me->add_temp("apply/attack", -amount); 
me->add_temp("apply/damage", -amount/3); 
me->add_temp("apply/dodge", -amount); 
me->add_temp("apply/speed", -100);

me->delete_temp("tianjing"); 
message_vision( HIY "\n$N吸了一口气，将内力收回丹田！\n\n" NOR, me); 

return 0; 
} 
