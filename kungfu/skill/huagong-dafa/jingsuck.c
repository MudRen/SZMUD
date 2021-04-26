// Code of ShenZhou
// jingsuck.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp, jing, jing1, eff_jing;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || target == me 
        || target->query("id") == "mu ren" 
        || target->query("id") == "shangshan" 
        || target->query("id") == "mengzhu" 
        || target->query("id") == "fae" )
                return notify_fail("��Ҫ��ȡ˭�ľ���\n");

        if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ������\n");

        if( objectp(me->query_temp("weapon")) && me->query_skill("huagong-dafa",1) < 60)
                return notify_fail("��Ļ����󷨹���������������ֲ���ʩ�û��������˾�����\n");

        if( !me->is_fighting() || !target->is_fighting() || !living(target) )
                return notify_fail("�������ս���в�����ȡ�Է��ľ���\n");

        if( (int)me->query_skill("huagong-dafa",1) < 45 )
                return notify_fail("��Ļ����󷨹���������������ȡ�Է��ľ���\n");

        if( (int)me->query("neili",1) < 10 )
                return notify_fail("�����������������ʹ�û����󷨡�\n");

        if( (int)target->query("jing") < (int)target->query("max_jing") / 5 
         || (int)target->query("jingli") < (int)target->query("max_jingli") / 10 )
                return notify_fail( target->name() +
                        "�Ѿ������ɢ�����Ѿ��޷�����������ȡ�����ˣ�\n");

        message_vision(
                HIR "$NͻȻ���ص�һЦ��˫��һǰһ���׼$n��̫��Ѩ���˹�����\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
        sp *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;

        me->set_temp("sucked", 1);              

        if( random(sp+dp) > dp )
        {
                tell_object(target, HIR "���;������������̰��ʹ����־������ͷ����һƬ�հף�\n" NOR);
                tell_object(me, HIG "�����" + target->name() + "�ľ���������ԴԴ���������˽�����\n" NOR);

                target->receive_damage("jing", (int)me->query_skill("huagong-dafa", 1)/10 );

		if( (int)me->query("eff_jing") < (int)me->query("max_jing") )
	                me->receive_curing("jing", (int)me->query_skill("huagong-dafa", 1)/10);
		else me->add("jing",(int)me->query_skill("huagong-dafa", 1)/10);

                if( target->query("combat_exp") >= me->query("combat_exp")/2 ) {
                                me->add("potential", 1);
                if (me->query("potential") > me->query("max_potential"))
                me->set("potential", me->query("max_potential"));
                }

                me->start_busy(random(3));
                target->start_busy(random(3));
                me->add("neili", -(int)me->query_skill("huagong-dafa", 1)/6);
                me->add("jingli", -5);

                call_out("del_sucked", 2, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(3);
                call_out("del_sucked", 4, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}
