// Code of ShenZhou
// mo.c ħ���ġ�ħ���־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon, t_weapon;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ħ���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if( weapon->query("skill_type") != "stick" )
                return notify_fail("�������ް������ʹ��ħ���ġ�ħ���־�����\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ���������\n");

        if( (int)me->query_skill("stick") < 200 )
                return notify_fail("���ħ��������죬����ʹ�á�ħ���־���\n");

        if( !objectp(t_weapon = target->query_temp("weapon")) )
                return notify_fail("ħ���ġ�ħ���־�����û���������Ķ�����Ч��\n");

        message_vision(HIR"\n$Nһ���м��޷��İ�����̬��Ȼ��������" + weapon->name() + "������λʵ������˼���������\n"NOR, me);

        me->add("neili", -80);
        me->add("jingli", -20);

        ap = (int)me->query_skill("stick");
        ap += (int)me->query_temp("apply/attack");
        ap = ap * ap * ap / 3 + (int)me->query("combat_exp");

        dp = (int)target->query("combat_exp");

        if( random(ap + dp) > dp ) {
                message_vision(HIR"$N�������������ò���������" + t_weapon->name() + "��������ϥ������$n��ǰ��\n\n"NOR, target, me);
                if( base_name(target) == "/kungfu/skill/yanxing-dao/copy/user" )
                        destruct(t_weapon);
                else {
                        t_weapon->unequip();
                        t_weapon->move(environment(target));
                }
                target->start_busy(1 + random(2));
        } else {
                message_vision(HIG"$N������$n����ͼ����û���ϵ���\n\n"NOR, target, me);
                me->start_busy(1);
        }

        return 1;
}

