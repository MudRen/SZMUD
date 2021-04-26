// Code of ShenZhou
//xiangmo.c ��ħ�� 

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
                return notify_fail("��ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon1 = me->query_temp("weapon");
        if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("�������޽�������ʹ�ý�ħ�衣\n");

        if( me->query_skill("lamaism",1) < 60 )
                return notify_fail("�������ķ���Ϊ���㣬����ʹ�ý�ħ�衣\n");
                
        if( me->query_skill_mapped("force") != "longxiang-banruo" )
                return notify_fail("�����õĲ���������������޷�ʩչ��ħ�裡\n");

        if( me->query_skill("longxiang-banruo", 1) < 60 )
                return notify_fail("���������������δ�����޷�ʩչ��ħ�裡\n");

        if( (lvl2=me->query_skill("sword")) < 100 )
                return notify_fail("�㲻������������Ϊ���㣬������ʹ�ý�ħ�裡\n");

        amount = lvl2/10;


        if ( amount < 30 ) amount = 30;
        if ( amount > 80 ) amount = 80;

        if( me->query("neili") <= amount*4 )
                return notify_fail("�����������ʹ�ý�ħ�裡\n");
        if( me->query("jingli") <= amount*2 )
                return notify_fail("��ľ�������ʹ�ý�ħ�裡\n");

        weapon = me->query_temp("weapon");

        me->add_temp("apply/damage", amount);
        me->add_temp("apply/attack", amount*3);
        me->add_temp("apply/dodge", amount*2);

        message_vision(HIY "\n$NͻȻ����һԾ��Ǳ������һ��߸�������գ����һ�����н������һƬ������ֻ�����֮����������㺮������֯��һ���ܲ�͸��Ĺ�����\n\n" NOR, me, target);

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
