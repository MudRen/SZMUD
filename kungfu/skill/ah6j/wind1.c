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
                return notify_fail("补风捉影只能对战斗中的对手使用。\n");

                message_vision(HIW "$N发现$n攻势猛烈大喊一声:" + HIC + "捕风捉影" + HIW + "，顿时间将$n像稻草一样飞了出去！\n" NOR, me, victim);

        return 1;
}
