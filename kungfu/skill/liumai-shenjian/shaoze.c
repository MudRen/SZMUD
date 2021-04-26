// Code of ShenZhou
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_shaoze(object, object);

int perform(object me, object target)
{
        string msg;
        int skill, amount;
	object weapon;
	weapon = me->query_temp("weapon");

        skill  = (int)me->query_skill("liumai-shenjian", 1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

if( me->query_temp("weapon") )
                return notify_fail("��ֻ���ڿ���ʱʹ�������񽣣�\n");
        
if( me->query("neili") <= 500 )
                return notify_fail("�������������\n");
       
 if( me->query_skill("liumai-shenjian", 1) < 120 )
                return 
notify_fail("��������񽣻��δ�����޷�ʩչ���󽣣�\n");

        if( target->is_busy() )

                return notify_fail(target->name() + 
"Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

        msg = HIY 
"$N����Сָ�������£�ɲ�Ǽ�ֻ���������죡\n";

        me->start_busy(random(1));
        me->add("neili", -100);
        me->add("jingli", -50);

        if( random(me->query("combat_exp")) > 
random(target->query("combat_exp")) ) 
        { 
                msg +=
"$n��ʱ���а����η֮��������¼��ֹ����Ա���\n" NOR;

	me->set("krcg",3);
	me->set_temp("shaoze",1);
                remove_call_out("remove_shaoze");
                call_out("remove_shaoze", skill/10, me,target);


}
        else 
        {
                msg += "����$n��������������˿����ͣ��\n" NOR;
                me->start_busy(1 + random(2));
        }

        message_vision(msg, me, target);

        return 1;
}

void remove_shaoze(object me, object target) 
{
       
        me->delete_temp("shaoze");
	me->set("krcg",0);
        tell_object(me, target->name() + "�Ĺ�ʽ�𽥼�ǿ��������\n");
        tell_object(target, "�������ǰ�Ľ�������ɢȥ��\n");
}

