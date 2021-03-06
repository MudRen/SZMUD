// Code of ShenZhou
// zhentian 震天
// By keny 
// 昆仑拳法 160 级，玄天无极 120 级。
// 临时增加臂力，提高攻击力

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me,int amount);

int perform(object me, object target)
{
int original, skill;

if( objectp(target) && target != me) 
return notify_fail("你有能力提升别人的战斗了吗？\n");

if( !me->is_fighting() ) 
return notify_fail("你必须在战斗中才能使用震天拳劲！\n");

if( me->query_temp("weapon") )
return notify_fail("你只能在空手时使用震天拳劲！\n");

if( (string)me->query_skill_mapped("force") != "xuantian-wuji" ) 
return notify_fail("你都没有用人家的心法，怎么施以绝技呀。\n"); 

if( me->query_skill("xuantian-wuji", 1) < 120 )
return notify_fail("你的玄天无极火候未到，无法施展震天拳劲！\n");

if( me->query_skill("zhentian-quan", 1) < 160 )
return notify_fail("你的震天拳火候未到，无法施展震天拳劲！\n");

if( me->query("max_neili") <= 500 )
return notify_fail("你的内力修为不足，劲力不能运发，无法施展震天拳劲！\n");

if( (int)me->query("neili") < 500  )
return notify_fail("你的内力不够。\n");

if( (int)me->query_temp("quanjing") )
return notify_fail("你已经运行了震天拳劲！\n");

skill = me->query_skill("zhentian-quan", 1);
original = me->query_str();
me->add("neili", -skill*2);
me->receive_damage("jingli", skill);

message_vision(
HIR "\n $N运起【震天拳劲】的秘诀，双手拳臂青根涌现在臂上，如同融已震天之力在拳臂上。\n" NOR, me);

me->add_temp("apply/strength", original*2);
me->set_temp("quanjing", 1);
me->start_call_out( (: call_other, __FILE__, "remove_effect", me, original :), skill/6);
me->start_busy(1);
return 1;
}

void remove_effect(object me, int amount)
{
me->add_temp("apply/strength", - 2*amount);
me->delete_temp("quanjing");
tell_object(me, YEL"你缓缓吸了一口气，把身体慢慢的放松，收回震天拳劲。\n"NOR);
}
