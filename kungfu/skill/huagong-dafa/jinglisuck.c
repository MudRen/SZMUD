// Code of ShenZhou
// jinglisuck.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp, jl;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || target == me 
        || target->query("id") == "mu ren" 
        || target->query("id") == "shangshan" 
        || target->query("id") == "mengzhu" 
        || target->query("id") == "fae" )
                return notify_fail("��Ҫ��ȡ˭�ľ�����\n");

        if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ��������\n");

        if( objectp(me->query_temp("weapon")) && me->query_skill("huagong-dafa",1) < 90)
                return notify_fail("��Ļ����󷨹���������������ֲ���ʩ�û��������˾�����\n");

        if( !me->is_fighting() || !target->is_fighting() || !living(target) )
                return notify_fail("�������ս���в�����ȡ�Է��ľ�����\n");

        if( (int)me->query_skill("huagong-dafa",1) < 75 )
                return notify_fail("��Ļ����󷨹���������������ȡ�Է���������\n");

        if( (int)me->query("neili") < 20 )
                return notify_fail("�����������������ʹ�û����󷨡�\n");

        if( (int)me->query("jingli") >= (int)me->query("max_jingli") * 5/2 )
                return notify_fail("����ȡ�ľ�������ȫ���޷�����ȡ������\n");

	/*
        if( (int)target->query("max_jingli") <= 0 )
                return notify_fail( target->name() +
                        "û���κξ�����\n");

        if( (int)target->query("jingli") < (int)target->query("max_jingli") / 10 )
                return notify_fail( target->name() + "�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κξ����ˣ�\n");

	*/
	
        message_vision(HIR "$N��$n΢΢һЦ��ͻȻ���Ʊ�צ������$n������\n\n" NOR, me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
        sp *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;

        me->set_temp("sucked", 1);              

        if( random(sp+dp) > dp )
        {
                tell_object(target, HIR "�����ڻ���Ѩ��" + me->name() + "ͻȻ��ס���������ã�ֻ���������ˮ���Ի���Ѩ���ڶ�����\n" NOR);
                tell_object(me, HIG "�����" + target->name() + "�ľ���������ԴԴ���������˽�����\n" NOR);

		jl = (1+random(3)) * (int)me->query_skill("huagong-dafa", 1);
		if ((int)target->query("jingli") > jl)
		{		
	                target->add("jingli", -1 * jl );
	                me->add("jingli", (1+random(3))*((int)me->query_skill("huagong-dafa", 1)));
		}else{
	                me->add("jingli", (1+random(2))*((int)me->query_skill("huagong-dafa", 1)) * 2 / 3);
	                target->add("jingli", -1 * jl );
	                }
                if( target->query("combat_exp") >= me->query("combat_exp")/2 ) {
                        me->add("potential", 1);
                        me->add("combat_exp", 1);
                        if (me->query("potential") > me->query("max_potential"))
                        me->set("potential", me->query("max_potential"));
                }

                me->start_busy(1+random(3));
                target->start_busy(1+random(3));
                me->add("neili", -(int)me->query_skill("huagong-dafa", 1)/6);
                me->add("jingli", -5);

                call_out("del_sucked", 2, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ��û��$P��ס����\n" NOR, me, target);
                me->add("jingli", -5);
                me->start_busy(2+random(2));
                call_out("del_sucked", 5, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}

