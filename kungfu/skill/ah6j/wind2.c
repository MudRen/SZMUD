 //perform wind2

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me)
{
        int skill, skill1, skill2;
        object victim,weapon;

        if( !victim ) victim = offensive_target(me);

        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("���о���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

                message_vision(HIR "$N�������޼������н�ʹ�������Ⱦ���֮һ"+ HIC + "���о���" + HIR + "��\n" NOR, me, victim);
                
                message_vision(HIC "$Nһ��δ��ڶ����ֳ���, ��ʱ��$n���޹�������, ֻ��$nֻ�ز���.!\n" NOR, me, victim);
                message_vision(HIR "$N����$n�ҽ�! $N����������˹�ȥ, ��ʱ$n������΢����.\n" NOR, me, victim);

                victim->set("neili", 0);

        return 1;
}
