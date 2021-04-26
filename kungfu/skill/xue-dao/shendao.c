// Code of ShenZhou
// juezhao.c ��Ѫ�� 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill1, skill2, enfor, amount, shen1, shen2, nei_loss, qi_loss,lv1,lv2;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if( weapon->query("skill_type") != "blade" )
                return notify_fail("�������޵������ʹ�ü�Ѫ�񵶣�\n");

	if( me->query_str() < 25 )
		return notify_fail("��ı���������ʹ��Ѫ�����У�\n");

	if( me->query_skill("longxiang-banruo", 1) < 80
	&& me->query_skill("xiaowuxiang", 1) < 80)
		return notify_fail("���������������δ�����޷�ʩչ��Ѫ�񵶣�\n");

	if( me->query_skill_mapped("force") != "longxiang-banruo"
	&& me->query_skill_mapped("force") != "xiaowuxiang")
                return notify_fail("�����õ��ڹ����Ѫ�񵶵���·��㣣�\n");

	if( me->query_skill("xue-dao", 1) < 120 )
		return notify_fail("���Ѫ�����δ��������ʹ���У�\n");

	if( me->query("neili") <= 800 )
		return notify_fail("�����������ʹ�ü�Ѫ�񵶣�\n");

	message_vision(HIR "$NͻȻ��ת��������Լ���ͷ�Ϳ�һ��������һ�������У�������Ѫ������Ѫ��ĵ���ȴ�ַ·𻯳�һƬѪ��������ס$n����Ӱ��\n\n" NOR, me, target);

   // take into account both attacker and victem's shen
	lv1=me->query("PKS")/10;
	lv2=me->query("MKS")/500;
	shen1 = 0 - me->query("shen");
	shen2 = me->query("shen");
	skill1 = me->query_skill("force");
	skill2 = me->query_skill("blade");
	enfor = me->query("jiali");
	amount = 80 + (skill1+skill2)/30 +lv1+lv2+((shen1/1500)+random(shen2/2000))/10;
   // higher the power, higher cost 
    // adjust for the new combatd limit of 400
	if (amount > 400)
		amount = 400;
	nei_loss = 0 - amount - 200;
	qi_loss = 0 - amount/20 - 20;

	me->add_temp("apply/attack", amount);
	me->add_temp("apply/damage", amount);
	me->add_temp("apply/dodge",  amount);
	me->set("jiali", 50+enfor);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->start_busy(1+random(2));
	me->add("neili", nei_loss);
	me->add("jingli", -50);
	me->add("eff_qi", qi_loss);
	me->set("jiali", enfor);
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/dodge", -amount);

	return 1;
}

