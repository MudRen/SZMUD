// Code by Scatter
// ���޵�����
// luowan.c
// V. 1.14

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
  object ob;
  string msg;
    int intBT;

    if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���޵�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//      weapon = me->query_temp("weapon");
//      weapon2 = target->query_temp("weapon");

        if( !living(target) )
                return notify_fail("������û�б�Ҫʹ�����޵����ơ�\n");

        if( me->query_temp("yield") )
                return notify_fail("�㲻���֣����ʹ�����޵����ƣ�\n");

        if (target->is_busy())
                return notify_fail("��������æ���ء�\n");


//      if( me->query_temp("luowang/"+target->name()) )
//              return notify_fail("���Ѿ������޵�����ǣ��ס"+ target->name() +"�ˣ��ŵ������ɡ�\n");

        if( (int)me->query_skill("meinu-quan", 1) < 100 )
                return notify_fail("�����Ůȭ��������죬ʹ�������޵����ơ�\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 120 )
                return notify_fail("�����Ů�ľ���Ϊ������ʹ�������޵����ơ�\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����ڵ�����������ʹ�����޵����ƣ�\n");

        if( me->query("jingli") <= 100 )
                return notify_fail("�����ڵ�����������ʹ�����޵����ƣ�\n");

        if( me->query_skill_mapped("parry") != "meinu-quan" )
                return notify_fail("����мܲ�����Ůȭ, �޷�ʹ�����޵����ơ�\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("�����õ��ڹ�����, �޷�ʹ�����޵����ƣ�\n");

        me->add("neili", -50);
        me->add("jingli", -50);

    msg = "\n"+HIW"\nֻ��$N˫�۷��裬������죬��ֻ�������ƻ�����ǧ��ǧ��������$n����ǰ��һ��һʽ��������Գɶ��䡣\n"NOR;

// Perform Check   N > 2n
        if( random(me->query("combat_exp")) > random(target->query("combat_exp")) * 2)
        {
                msg += HIC"ֻ��$NͻȻ֮�������˼�ֻ�֣�û��$n���׵�ʱ���Ѿ���$N�Ʒ���ס��ȫ���붯Ҳ�������ˣ�\n"NOR;
        intBT = (int)me->query_skill("meinu-quan",1) / 10;
                target->start_busy(intBT);
                me->add_temp("luowang/"+target->name(), 1);
//              call_out("luowang_checking", 1, me, target);
        }
// Perform Check  N > n
        else if( random(me->query("combat_exp")) * 2 > random(target->query("combat_exp")))
        {
                msg += HIC"$n��$NͻȻ������Ŀ죬���˷�����˼������һ���������Ӷ�����Ӱ��Χ�ˣ�\n"NOR;
        intBT = (int)me->query_skill("meinu-quan",1) / 25;
                target->start_busy(intBT);
                me->add_temp("luowang/"+target->name(), 1);
//              call_out("luowang_checking", 1, me, target);
        }
    else
    {
        message_vision(HIB"\n$nͻȻ����$N����ͻ�䣬�о�������ʱ��������û��������Ӱ֮�У�\n"NOR, me, target);
        intBT = random(4);
        me->start_busy(intBT);
    }
    message_vision(msg+"\n", me, target);
    return 1;
}


/*
void luowang_checking(object me, object target)
{
        object weapon = me->query_temp("weapon");

        if( !me ) return;

        if( !me->is_fighting() || !living(me) || me->is_ghost() )
        {
                me->delete_temp("chan");
                return;
        }
        else if( !objectp(weapon) || weapon->query("skill_type") != "cuff" )
        {
                me->delete_temp("chan");
                me->start_busy(1);
                message_vision(CYN "\n$N������������ȭ���ʧ��\n"NOR, me);
                return;
        }

        else if( me->query_skill_mapped("cuff") != "meinu-quan"
        || me->query_skill_mapped("parry") != "meinu-quan" )
        {
                me->delete_temp("luowang");
                me->start_busy(2);
                message_vision(CYN "WEAPON FAIL MESSAGE"NOR, me);
                return;
        }
        else if( me->query("neili") <= 100 )
        {
                me->delete_temp("luowang");
                me->start_busy(1);
                message_vision(CYN "\n$NͻȻ������ԭ�������������ˣ�\n"NOR,me);
                return;
        }           

        call_out("luowang_checking", 1, me, target);
}

*/
