/***********************************************************************************
creat by Karlopex@sz
by 21/05/2002
��ɽ��perform yanhui ���໲������
 ��������ɽ����Ч�ȼ�120����ϼ����Ч�ȼ�120����
 ���ܣ������ʱjifa dodge 5%��
       ��Чʱ�䣺5-10 tick��
 ���ƣ���������¾Ž�ͬʹ��
       ������yun zixiaͬʹ��

  ��������ȱ
************************************************************************************/
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_effect(object me, object target, int lvl1, int lvl2);
void check(object me, object target, int lvl1, int lvl2);
int perform(object me, object target)
{
        string msg;
	int lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���໲�������Ṧ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("zixia/lvl"))
                return notify_fail("���Ѿ�ʩչ������ϼ�񹦡����޷���ʹ�á��໲��������\n");
                
        if( me->query_skill_mapped("sword") == "dugu-jiujian" )
                return notify_fail("�����¾Ž�������ʽ���أ���������ͨ�书��\n");

        if( me->query_skill_mapped("parry") == "dugu-jiujian" )
                return notify_fail("�����¾Ž�������ʽ���أ���������ͨ�书��\n");

        if( me->query_temp("hssf-yanhui") )
                return notify_fail("���������á��໲�������Ṧ������\n");

        if( me->query_skill_mapped("force") != "zixia-gong")
                return notify_fail("�����õ��ڹ��롸�໲�������Ṧ����������ʽ��㣣�\n");

        if( me->query_skill_mapped("dodge") != "huashan-shenfa")
                return notify_fail("�����õ����롸�໲��������ʽ��ͬ���޷�ʹ�ã�\n");
                
        if( me->query_skill("dodge") < 119 )
                return notify_fail("�������Ϊ���������޷�ʩչ���໲�������Ṧ������\n");
                
        if( me->query_skill("force") < 119 )
                return notify_fail("����ڹ���Ϊ���δ�����޷�ʩչ���໲�������Ṧ������\n");

        if( me->query("neili") < 600 )
                return notify_fail("�����������������������ʩչ���໲�������Ṧ������\n");
        
        msg = MAG "$N������ϼ���������鲼��Χ��$N����Ӱ��������һ����$n�����Դ���\n\n" NOR;

        lvl1 = (int)me->query_skill("dodge");
        lvl2 = (int)me->query_skill("force");

        me->add_temp("apply/dodge", lvl1 / 12);
        me->add_temp("apply/speed", (lvl1 + lvl2)/24);
        me->add_temp("apply/defense", lvl1 / 16);
	
        me->add("neili", -(lvl1+lvl2) / 3);
        me->add("jingli", -(lvl1+lvl2) / 4);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl1, lvl2:), (lvl1+lvl2)/20);
        message_vision(msg, me, target);
	call_out("check", 1, me, target, lvl1, lvl2);
        me->set_temp("hssf-yanhui",1);
        return 1;
}

void remove_effect(object me, object target, int lvl1, int lvl2)
{
        if (!me || !me->query_temp("hssf-yanhui")) return;
        if( me->is_fighting() && objectp(target))
		message_vision(HIY "\n$N����һ�������ջء��໲�������Ṧ������$n��ʱ�е�ѹ�������˲��١�\n" NOR, me, target);
        else if( me->is_fighting() && !objectp(target))
                message_vision(HIY "\n$N����һ�������ջء��໲�������Ṧ������\n" NOR, me); 
        else message_vision(HIY "\n$Nͣס���Σ�������һ�������ջ��ˡ��໲�������Ṧ������\n" NOR, me, target);
        me->delete_temp("hssf-yanhui",1);
        me->add_temp("apply/dodge", -lvl1 / 12);
        me->add_temp("apply/speed", -(lvl1 + lvl2)/24);
        me->add_temp("apply/defense", -lvl1 / 16);
}

void check(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	else if( !me->is_fighting()){	
		remove_effect(me, target, lvl1, lvl2);
		return;
        }else if( me->query_skill_mapped("dodge") != "huashan-shenfa"){
		message_vision(HIY "\n$N���Ṧ�Ѿ������ǻ�ɽ�������໲�������Ṧ������ʱ��ʧ��\n" NOR, me, target);    	
		remove_effect(me, target, lvl1, lvl2);
		return;
	}
	call_out("check", 1, me, target, lvl1, lvl2);
}

