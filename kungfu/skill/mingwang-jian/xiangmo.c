// Code of ShenZhou
//xiangmo.c 降魔舞 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
        object weapon1;
        int    lvl1, lvl2, amount;
        
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("降魔舞只能对战斗中的对手使用。\n");

        weapon1 = me->query_temp("weapon");
        if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，不能使用降魔舞。\n");

        if( me->query_skill("lamaism",1) < 60 )
                return notify_fail("你密宗心法修为不足，不能使用降魔舞。\n");
                
        if( me->query_skill_mapped("force") != "longxiang-banruo" )
                return notify_fail("你所用的并非龙象般若功，无法施展降魔舞！\n");

        if( me->query_skill("longxiang-banruo", 1) < 60 )
                return notify_fail("你的龙象般若功火候未到，无法施展降魔舞！\n");

        if( (lvl2=me->query_skill("sword")) < 100 )
                return notify_fail("你不动明王剑法修为不足，还不会使用降魔舞！\n");

        amount = lvl2/10;


        if ( amount < 30 ) amount = 30;
        if ( amount > 80 ) amount = 80;

        if( me->query("neili") <= amount*4 )
                return notify_fail("你的内力不够使用降魔舞！\n");
        if( me->query("jingli") <= amount*2 )
                return notify_fail("你的精力不够使用降魔舞！\n");

        weapon = me->query_temp("weapon");

        me->add_temp("apply/damage", amount);
        me->add_temp("apply/attack", amount*3);
        me->add_temp("apply/dodge", amount*2);

        message_vision(HIY "\n$N突然纵身一跃如潜龙升天一般高高跳至半空，大喝一声手中剑已舞成一片光网，只见半空之中有无数点点寒星闪动织成一道密不透风的光网。\n\n" NOR, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        
        me->start_busy(1+random(3));
        me->add_temp("apply/damage", -amount);
        me->add_temp("apply/attack", -amount*3);
        me->add_temp("apply/dodge", -amount*2);
        me->add("neili", -amount*3);
        me->add("jingli", -amount*2);

        return 1;
}
