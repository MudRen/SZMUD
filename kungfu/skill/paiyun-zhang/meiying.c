// Code Of ShenZhou
// 排云掌  -  云中魅影
// Keny's Skills

#include <ansi.h> 
inherit F_DBASE; 
inherit F_SSERVER; 

int perform(object me, object target) 
{
int dex, skill;

if(!target) target = offensive_target(me); 
if( !target || !target->is_character() || !me->is_fighting(target) ) 
return notify_fail("「云中魅影」只能对战斗中的对手使用。\n"); 

if( me->query_temp("paiyun/meiying")) 
return notify_fail("你正在运功中!\n");   

if( (string)me->query_skill_mapped("dodge") != "paiyun-zhang" )   
return notify_fail("你没有将排云掌运在身法上，无法使出「云中魅影」。\n");  

if( objectp(me->query_temp("weapon")) ) 
return notify_fail("空手才能施展「云中魅影」\n"); 

if( me->query_skill_prepared("strike") != "paiyun-zhang" ) 
return notify_fail("你所备的并非排云掌，不能施展「云中魅影」！\n"); 

if( me->query("neili") <= 400 ) 
return notify_fail("你的内力不够使用「云中魅影」！\n"); 

if( me->query("jingli") <= 400 ) 
return notify_fail("你的精力不够使用「云中魅影」！\n");    

if( (int)me->query_skill("paiyun-zhang",1) < 150 )   
return notify_fail("你的排云掌火候不够，无法使用「云中魅影」！\n");   

message_vision(HIB"\n$N突然间脑海闪出一丝不寻常的招意"+HIM"「云中魅影」"+NOR""+HIB"起落无常，飘渺不定！！\n"NOR, me);   

me->set_temp( "paiyun/meiying", 1 );

dex = me->query_skill( "dodge" ); 
dex = dex / 2; 
me->add("neili",-500); 
me->add("jingli",-500); 
me->add_temp("apply/dodge",dex); 
skill = (me->query_skill("paiyun-zhang",1))/ 2; 
me->start_call_out( (: call_other, __FILE__, "end_perform", me, dex :),skill/8);
return 1; 
}

void end_perform( object me, int dex) 
{
me->add_temp("apply/dodge", -dex); 
me->delete_temp( "paiyun/meiying" ); 
message_vision(HIB"\n$N慢慢停了那股魅影，所有步法和动作变回原！\n"NOR, me);
}
