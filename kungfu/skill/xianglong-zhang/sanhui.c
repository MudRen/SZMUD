// Code of ShenZhou
// sanhui ���������ڡ�
// Lara 2001/11/11
/*
����������������ʹϧ�����Ƿ�ŭ������������������һ�������ֺ���һ�ƣ���
�򶡴����ȥ�����ǽ���ʮ���Ƶ�һ�С������лڡ���������֮ʱ���붡�������
����ʮ�����ɣ���˵���㵽����������֮�ʣ���������Ѳ����߰��ɡ�

������������֮�У�����������ǿ��Ҳ����һ�ƿɻ�����������ġ����������š�
���Ƿ壬��Ľ�ݡ��Ĵ������������ް��С��֮�ģ�Ȼ������ʮ�����֮����ƣ�
���ϲ�������������Լ��������ⲻ������һ�Ƽȳ������������������������⣬
����һ�С������лڡ���������ǰ�ƣ�˫����������һ����ɽ������ѹ��������

����ֻһ˲֮�䣬����������Ϣ���ͣ��Է���������ŭ����ӿ���Ʋ��ɵ���˫��
��һ�����εĸ�ǽ�����Լ���ǰ���塣����֮�£����ﻹ����ԣ��˼�Բߣ���֪
���ǵ��Ƴ�ӭ���Ʊر۶����ۣ�˵����ȫ���Ǿ��飬��æ�н��������ϼ��ף�˫
������������Բ��ס��ǰ��ͬʱ���������Ʈ����ˡ�

���������������һ�С������лڡ���ǰ������δ�������������ֵ��������ﲻ��
����ֱ����棬����бб�ӳ���Ҳ����������ƫ��һ���������ұ����飬������Ϣ
��ʱ���ǣ����������ݳ�����֮�⣬Ψ�ֵ�������׷�������Ƶ��أ�������������
�����ϡ���������Գ�ۣ����Ӱ���и��µİ��Ͻ�ס�����ֽ⿪������Ѩ����
*/

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        string weapon;

        if( !target ) target = offensive_target(me);
/*
        if( !wizardp(me) )
                return notify_fail("�㲻�����壬����ʹ�á��������ڡ���\n");
*/
        if( me->query_temp("sanhui_busy") )
                return notify_fail("��΢һ�˾���ֻ��������Ϣ���ǣ��������ƣ�\n");

        if( me->query_temp("xianglong",1) )
                return notify_fail("������ʹ���ڹ����޷����á��������ڡ���\n");

        if( !target || !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("���������ڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���������ڡ�ֻ�ܿ������á�\n");

        if( me->query_temp("yield") )
                return notify_fail("�㲻���ƣ����ʹ�����������ڡ���\n");

        if( me->query_str() < 50 )
                return notify_fail("�������������ʩչ���������ڡ���\n");

        if( me->query_con() < 50 )
                return notify_fail("������ʲ�����ʩչ���������ڡ���\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õ��ڹ��롸�������ڡ���·��㣣�\n");

        if( me->query_skill("huntian-qigong", 1) < 280 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ���������ڡ���\n");

        if( me->query_skill("xianglong-zhang", 1) < 300 )
                return notify_fail("�㽵��ʮ���Ʋ�����죬�޷�ʩչ���������ڡ���\n");

        if( (int)me->query("max_neili", 1) < 5000 )
                return notify_fail("���������Ϊ����������ʩչ���������ڡ���\n");

        if( me->query("neili") < 1000 )
                return notify_fail("�����ڵ�����̫��������ʹ�á��������ڡ���\n");

        if( (int)me->query("jingli", 1) < 500 )
                return notify_fail("�����ڵľ����������޷�ʹ�á��������ڡ�\n");

        message_vision( HIR"\n$N����һ�������첽���磬����Ҫ�������ˣ�\n"NOR, me);

        me->add("neili", -100);
        me->add("jingli", -100);
        me->set_temp("sanhui", 1);

        call_out("sanhui", 1, me, target);
        return 1;

}

int sanhui(object me, object target)
{
        int enfor, skill, amount, lvl;
	if (me->query_skill("strike") < 450 )
		lvl = ( me->query_skill("strike") - 300 ) / 10;

        if ( !living(me) || me->is_ghost() || environment(me) != environment(target) )
        {
                remove_effect(me);
                return;
        }
        else if ( !living(target) || !me->is_fighting(target) )
        {
                message_vision(CYN"\n$N�����ջ����ƣ���������ǰ���˸�ԲȦ��\n"NOR,me);
                remove_effect(me);
                return;
        }
        else if ( (int)me->query("neili", 1) < 500 )
        {
                tell_object(me, HIR"���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n"NOR);     
                remove_effect(me);
                return;
        }
        else
        {
                skill = me->query_skill("force");
                enfor = me->query("jiali");

                // this one count how many strike u hit.
                me->set_temp("sanhui_busy", (int)me->query_temp("sanhui"));

                /*
                 * if 1 strike missed, do attack again. at most can have 3 strike.
                 * the enfor of each strike will add by, but the apply/attack will reduce.
                 */

                switch ( me->query_temp("sanhui") )
                {
                        case 1:         // the first strike is same to leiting's,
                                        // but this will only add on apply/attack.
                                amount = skill/2;
                                me->set("jiali", (int)(enfor+enfor/3));
                                break;
                        case 2:
                                amount = skill/3;
                                me->set("jiali", (int)(enfor+enfor/2));
                                break;
                        case 3:
				amount = skill/3;
                                me->set("jiali", enfor*2);
                                break;
                }

		amount = amount* 5/4;
		if ( amount > 250 ) amount = 250;
                me->add_temp("apply/attack", amount * lvl * 15 /100 );
                me->add_temp("apply/damage", amount * lvl * 15 /100 );
                me->add_temp("apply/strike", amount/3);

                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));

                me->add_temp("apply/attack", -amount * lvl * 15 /100 );
                me->add_temp("apply/damage", -amount * lvl * 15 /100 );
                me->add_temp("apply/strike", -amount/3);
                me->set("jiali", enfor);

                /*
                 * PS: in xianglong-zhang.c mixed hit_ob,
                 * if hit target, will delete_temp("sanhui"),
                 * so start remove_effect.
                 */

                if ( !me->query_temp("sanhui") || me->query_temp("sanhui") == 3 )
                        remove_effect(me);
                else
                {
                        me->add_temp("sanhui", 1);
                        sanhui(me, target);
                }
        }

        return 1;
}

void remove_effect(object me)
{
        int sanhui_busy = me->query_temp("sanhui_busy");

        // if 300 htqg and 300 force, enable force will 450.
        int amount = (int)(me->query_skill("force") - 450) / 2;
        if ( amount < 10 ) amount = 10;
        if ( amount > 20 ) amount = 20;

        if ( sanhui_busy == 3 )
                message_vision(RED"\n$N���ƻ�����������������ò�ת��Ϊ�أ����µ�Ϣ��\n"NOR,me);

        // if 3 hit all missed, delete sanhui temp here.
        if ( me->query_temp("sanhui") )
                me->delete_temp("sanhui");

        // more hits, cost more neili, min 100, max 300.
        me->add("neili", -100 * sanhui_busy);

        // more hits, longer busy time, longer to receive heal.
        if ( sanhui_busy > 2 ) sanhui_busy = 2;
        me->start_busy(sanhui_busy + random(1));
        call_out("receive_heal", (int)amount * sanhui_busy / 3, me);
}

void receive_heal(object me)
{
        if ( !me ) return;

        me->delete_temp("sanhui_busy");
        tell_object(me, MAG"\n�㾭��һ���˹���Ϣ����ȥ����������ס��һ��������\n"NOR); 
}
