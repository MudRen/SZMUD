// san.c  ��Ůɢ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage, sp, dp, i;
	string result, str, msg;

	damage = (int)me->query_skill("bahuang-gong", 1);
	damage = damage +  (int)me->query_skill("tianyu-qijian", 1);
	damage = damage +  (int)me->query_skill("sword", 1);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����Ůɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("tianyu-qijian", 1) < 100 )
		return notify_fail("��������潣������죬����ʹ�á�\n");

        if ( me->query_skill_mapped("sword") != "tianyu-qijian")
                return notify_fail("��û�м��������潣�������ϣ�\n"); 

	if ((int)me->query_skill("xiaowu-xiang", 1)<100
		&& (int)me->query_skill("bahuang-gong", 1)<100
		&& (int)me->query_skill("beiming-shengong", 1)<100)
		return notify_fail("�����ң���ڹ���򲻹���\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	

	if( (int)me->query("neili", 1) < damage + 200 )
		return notify_fail("����������̫��������ʹ�á���Ůɢ������\n");
			
	message_vision(CYN "\n$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��\n"NOR, me,target);

	sp = me->query_skill("sword") + me->query_skill("dodge") + me->query_dex();
	dp = target->query_skill("parry") + target->query_skill("dodge") + me->query_dex();
	sp *= me->query("combat_exp")/1000;
	dp *= target->query("combat_exp")/1000;
	if( random(sp) > random(dp) ) 
	{
		target->start_busy( (int)me->query_skill("tianyu-qijian") / 30 + 1);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		me->add("neili", -damage);
		message_vision(HIR "\nֻ��$N������Ϊһ�ߣ�����$n��\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n\n" NOR, me,target);

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		message_vision("($N"+str+")\n", target);

		me->start_busy(2);
	} else 
	{
		message_vision(CYN "����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR, me,target);
		me->add("neili", -100);
		me->start_busy(4);
	}
	return 1;
}
