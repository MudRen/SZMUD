// Code of ShenZhou
// chan.c �򹷰����������־�
// Lara 2001/11/11
// �����������ģ����㹫ʽ���������ԱȽϣ���������ʣ���߳���ʱ��
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{       
        int mywx;
        string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if( weapon->query("skill_type") != "stick" )
                return notify_fail("�������ް������ʹ�ô򹷰����������־�����\n");
        if( me->query_temp("ban",1) )
                return notify_fail("������ʹ�ð��־���\n");
        if( (int)me->query_skill("force") < 100 )
                return notify_fail("����ڹ���Ϊ�������ʹ�ò��ˡ������־���\n");        
        if( me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("�����õ��ڹ���򹷰�����·��㣣�\n");
        if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ���������\n");                
        if( (int)me->query_skill("stick") < 100 )
                return notify_fail("��Ĵ򹷰���������죬����ʹ�á������־���\n");
        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jingli", -5);
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        }
        msg = CYN "$Nʹ���򹷰����������־����ó���ɽ��Ӱ����$n��û��\n";
        me->add("neili", -50);
        me->add("jingli", -20);
        mywx = me->query_int();
        if( (mywx * (random(me->query("combat_exp")/10000) * (int)me->query_skill("stick") ) > 
        ((int)target->query_int() * ((int)target->query("combat_exp")/5000) * ((int)target->query_skill("parry")/2 + (int)target->query_skill("dodge")/2))/4) ) {
                msg += "���$p��$P���˸���æ���ң�һʱ�޷����н�����\n" NOR;
                target->start_busy( (int)me->query_skill("stick") /(20+random(10)));
        } else {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(1+random(3));
        }
        message_vision(msg, me, target);
        return 1;
}
