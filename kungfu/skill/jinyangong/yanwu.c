/*******************************************************************************************
creat by Karlopex@sz
by 21/05/2002
���㹦���� perform yanwu (ӥ������)--�����ʱ�� add def = 20+ ��
   ���������칦��Ч�ȼ�60�����㹦��Ч�ȼ�135��
   ���ƣ�����������Ч�ȼ�10-30 tick��ս��������
        ֻ����ս����ʹ�á�
        ���뱾������pfm���ʹ�á�
   ������$1��Хһ��������Ȼ�ӿ졣$1����Ӱʱ��ӥ�����ա�ʱ��Ⱥ����裬�����ۻ����ң�ɷ�Ǻÿ���
********************************************************************************************/
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
		return notify_fail("��ӥ�����衹�Ṧ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("jyg-yanwu") )
                return notify_fail("���������á�ӥ�����衹�Ṧ������\n");

        if( me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("�����õ��ڹ��롸ӥ�����衹�Ṧ����������ʽ��㣣�\n");

        if( me->query_skill_mapped("dodge") != "jinyangong")
                return notify_fail("�����õ����롸ӥ�����衹��ʽ��ͬ���޷�ʹ�ã�\n");
                
        if( me->query_skill("dodge") < 134 )
                return notify_fail("�������Ϊ���������޷�ʩչ��ӥ�����衹�Ṧ������\n");
                
        if( me->query_skill("force") < 59 )
                return notify_fail("����ڹ���Ϊ���δ�����޷�ʩչ��ӥ�����衹�Ṧ������\n");

        if( me->query("neili") < 600 )
                return notify_fail("�����������������������ʩչ��ӥ�����衹�Ṧ������\n");
        
        msg = HIC "$N��Хһ��������Ȼ�ӿ졣$N����Ӱʱ��ӥ�����ա�ʱ��Ⱥ����裬�����ۻ����ң�ɷ�Ǻÿ���\n\n" NOR;

        lvl1 = (int)me->query_skill("dodge");
        lvl2 = (int)me->query_skill("force");

        me->add_temp("apply/dodge", lvl1 / 15);
        me->add_temp("apply/speed", (lvl1 + lvl2)/30);
        me->add_temp("apply/defense", lvl1 / 20);
	
        me->add("neili", -(lvl1+lvl2) / 3);
        me->add("jingli", -(lvl1+lvl2) / 4);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl1, lvl2:), (lvl1+lvl2)/15);
        message_vision(msg, me);
	call_out("check", 1, me, target, lvl1, lvl2);
        me->set_temp("jyg-yanwu",1);
        return 1;
}

void remove_effect(object me, object target, int lvl1, int lvl2)
{
        if (!me || !me->query_temp("jyg-yanwu")) return;
	if( me->is_fighting())
		message_vision(HIY "\n$N����һ�������ջء�ӥ�����衹�Ṧ������$n��ʱ�е�ѹ�������˲��١�\n" NOR, me, target);
	else message_vision(HIY "\n$N���ν�ͣ������һ�������ջ��ˡ�ӥ�����衹�Ṧ������\n" NOR, me, target);
        me->delete_temp("jyg-yanwu",1);
        me->add_temp("apply/dodge", -lvl1 / 15);
        me->add_temp("apply/speed", -(lvl1 + lvl2)/30);
        me->add_temp("apply/defense", -lvl1 / 20);
}

void check(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	else if( !me->is_fighting()){	
		remove_effect(me, target, lvl1, lvl2);
		return;
        }else if( me->query_skill_mapped("dodge") != "jinyangong"){
		message_vision(HIY "\n$N���Ṧ�Ѿ������ǽ��㹦����ӥ�����衹�Ṧ������ʱ��ʧ��\n" NOR, me, target);    	
		remove_effect(me, target, lvl1, lvl2);
		return;
	}
	call_out("check", 1, me, target, lvl1, lvl2);
}

