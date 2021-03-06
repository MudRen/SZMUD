// Code of ShenZhou
// by keny
// 昆仑掌法 120 级，玄天无极 100 级。
// 用衣袖为武器，提高招架等级。

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
int damage,skill;
        string *limb, type, result, str,msg;

        type = "内伤";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("流云水袖只能对战斗中的对手使用。\n");

        if( me->query_temp("liushui") )
                return notify_fail("你已在使用流云水袖了！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("空手才能施展流云水袖！\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang" )
                return notify_fail("你所用的并非昆仑掌，不能施展流云水袖！\n");

        if( me->query_skill_prepared("strike") != "kunlun-zhang" )
                return notify_fail("你所备的并非昆仑掌，不能施展流云水袖！\n");

        if( me->query_skill_mapped("force") != "xuantian-wuji" )
                return notify_fail("你所用的并非玄天无极功，施展不出昆仑掌！\n");

        if( me->query_skill("xuantian-wuji") < 100 )
                return notify_fail("你的玄天无极功火候未到，无法施展流云水袖！\n");

        if( me->query_skill("kunlun-zhang") < 120 )
                return notify_fail("你的昆仑掌火候未到，无法施展流云水袖！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用流云水袖！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用流云水袖！\n");     
        if( me->query("jing") <= 200 )
                return notify_fail("你的精不够使用流云水袖！\n");


message_vision(
HIY "\n$N施出昆仑掌中的绝技"+HIC"【流云水袖】"+NOR"，"+HIY"双袖如同风车狂转了一会，把内力运合在衣袖上如同精铁坚硬。\n" NOR, me);

        me->set_temp("liushui", 1);

skill =  ( me->query_skill("kunlun-zhang")+ me->query_skill("force") ) / 2;
me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage",  skill/6);
        me->add_temp("apply/dodge",  skill/2);
        me->add_temp("apply/parry",  skill/2);
        me->add_temp("apply/defense",  skill/2);
        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/attack", -skill/2);
        me->add("neili", -skill/2);
        me->add("jingli", -100);
        me->add("jing", -100);
        me->start_busy(random(2));

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/15);

        return 1;
}

private int remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/damage", -amount/3);
        me->add_temp("apply/parry", -amount);
        me->add_temp("apply/dodge", -amount);
        me->add_temp("apply/defense", -amount);
        me->delete_temp("liushui");
        message_vision(
        YEL "\n$N慢慢的吸了口气，把内力收起了！\n\n" NOR, me);

        return 0;
}
