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
                return notify_fail("风中劲草只能对战斗中的对手使用。\n");

                message_vision(HIR "$N将内力巨集于腿中将使出风神腿绝招之一"+ HIC + "风中劲草" + HIR + "！\n" NOR, me, victim);
                
                message_vision(HIC "$N一招未完第二招又出来, 顿时间$n毫无攻击能力, 只见$n只守不功.!\n" NOR, me, victim);
                message_vision(HIR "$N踢中$n右脚! $N又向左肩踢了过去, 此时$n已受轻微内伤.\n" NOR, me, victim);

                victim->set("neili", 0);

        return 1;
}
