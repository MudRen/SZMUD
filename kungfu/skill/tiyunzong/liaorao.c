/***********************************************************************************
creat by Karlopex@sz
by 21/05/2002
�����ݣ�perform liaorao ���������ƣ�
                  ������������150����̫����150����
                  ���ܣ�����jifa dodge 15%��
                        ��Чʱ�䣺5-10 tick��
                  ��������ȱ

************************************************************************************/
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_effect(object me, object target, int lvl1, int lvl2);
void chkpfm(object me, object target, int lvl1, int lvl2);
int perform(object me, object target)
{
        string msg;
	int lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���������ơ��Ṧ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("tyz-liaorao") )
                return notify_fail("���������á��������ơ��Ṧ������\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("�����õ��ڹ��롸�������ơ��Ṧ����������ʽ��㣣�\n");

        if( me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("�����õ����롸�������ơ���ʽ��ͬ���޷�ʹ�ã�\n");
                
        if( me->query_skill("dodge") < 149 )
                return notify_fail("�������Ϊ���������޷�ʩչ���������ơ��Ṧ������\n");
                
        if( me->query_skill("force") < 149 )
                return notify_fail("����ڹ���Ϊ���δ�����޷�ʩչ���������ơ��Ṧ������\n");

        if( me->query("neili") < 600 )
                return notify_fail("�����������������������ʩչ���������ơ��Ṧ������\n");
        
        msg = MAG "$N����̫���񹦣�$N����Ӱ��������һ�㣬��$N������Ʈ��������\n\n" NOR;

        lvl1 = (int)me->query_skill("dodge");
        lvl2 = (int)me->query_skill("force");

        me->add_temp("apply/dodge", lvl1 / 10);
        me->add_temp("apply/speed", (lvl1 + lvl2)/25);
        me->add_temp("apply/defense", lvl1 / 15);
	
        me->add("neili", -(lvl1+lvl2) / 3);
        me->add("jingli", -(lvl1+lvl2) / 4);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl1, lvl2:), (lvl1+lvl2)/30);
        message_vision(msg, me);
        me->set_temp("hssf-yanhui",1);
        return 1;
}

void remove_effect(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	if( me->is_fighting())
		message_vision(HIY "\n$N����һ�������ջء��������ơ��Ṧ������$n��ʱ�е�ѹ�������˲��١�\n" NOR, me, target);
	else message_vision(HIY "\n$N��ʤ���ѷ֣����ջ��ˡ��������ơ��Ṧ������\n" NOR, me, target);
        me->delete_temp("hssf-yanhui",1);
        me->add_temp("apply/dodge", -lvl1 / 10);
        me->add_temp("apply/speed", -(lvl1 + lvl2)/25);
        me->add_temp("apply/defense", -lvl1 / 15);
}

void check(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	else if( !me->is_fighting()){	
		remove_effect(me, target, lvl1, lvl2);
		return;
        }else if( me->query_skill_mapped("dodge") != "tiyunzong"){
		message_vision(HIY "\n$N���Ṧ�Ѿ��������䵱�������ݣ����������ơ��Ṧ������ʱ��ʧ��\n" NOR, me, target);    	
		remove_effect(me, target, lvl1, lvl2);
		return;
	}
	call_out("check", 1, me, target, lvl1, lvl2);
}

