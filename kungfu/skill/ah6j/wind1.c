 //perform wind1

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me)
{
        int skill, skill1, skill2;
        object victim,weapon;

        if( !victim ) victim = offensive_target(me);

        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("����׽Ӱֻ�ܶ�ս���еĶ���ʹ�á�\n");

                message_vision(HIW "$N����$n�������Ҵ�һ��:" + HIC + "����׽Ӱ" + HIW + "����ʱ�佫$n�񵾲�һ�����˳�ȥ��\n" NOR, me, victim);

        return 1;
}
