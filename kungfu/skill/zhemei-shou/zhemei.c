// duo.c ������÷

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      string msg;
      object weapon, weapon2;
      int skill;
	int exp1,exp2,comb1,comb2;
	int skill1,skill2,neili1,neili2,str1,str2;

      me->clean_up_enemy();
      target = me->select_opponent();

      skill = me->query_skill("zhemei-shou",1);

      if( !(me->is_fighting() ))
              return notify_fail("������÷ֻ�ܶ�ս���еĶ���ʹ�á�\n");

      if (objectp(weapon2 = me->query_temp("weapon")))
              return notify_fail("�������֡�\n");

      if (!objectp(weapon = target->query_temp("weapon")))
         return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

      if( skill < 100)
              return notify_fail("�����ɽ��÷�ֵȼ�����, ����ʹ�ÿ�����÷��\n");

	if ((int)me->query_skill("xiaowuxiang", 1)<100
		&& (int)me->query_skill("bahuang-gong", 1)<100
		&& (int)me->query_skill("beiming-shengong", 1)<100)
		return notify_fail("�����ң���ڹ���򲻹���\n");

	if ( me->query_skill_mapped("force") != "xiaowuxiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷�ʹ�ÿ�����÷��\n");

	message_vision(CYN"\n$N�����Ϣ����һ�ƣ�������·ͻȻ����Ϊצ��ץ��$n���е�"+weapon->query("name")+CYN"��\n\n"NOR,me,target);

	exp1 = me->query("combat_exp");
	exp2 = target->query("combat_exp");
	skill1 = me->query_skill("zhemei-shou");
	skill2 = target->query_skill("parry");
	neili1 = me->query("neili");
	neili2 = target->query("neili");
	str1 = me->query_str();
	str2 = target->query_str();

	if (exp1 < exp2/3)
	{
		message_vision("˭֪$n����������������һ�����е�ס��$N�Ĺ��ơ�\n",me,target);
		me->start_busy(1+random(3));
		me->add("neili",-50);
		COMBAT_D->do_attack(target,me,me->query_temp("weapon"));
		return 1;
	}

	if (exp1 > random(exp2))
	{
	message_vision(HIR"$nһ����������"+weapon->query("name")+HIR"�ѱ�$N����ץ����\n\n"NOR,me,target);
		comb1 = str1*neili1*skill1;
		comb2 = str2*neili2*skill2;
	
		if (comb1 > comb2 * 3/5 )
		{
			
	message_vision(HIW"$nֻ��һ�ɾ�����"+weapon->query("name")+HIW"���˹���������һ�飬����"+weapon->query("name")+HIW"���ֶ�����\n"NOR,me,target);
			weapon->move(me);
			me->add("neili",-50);
			return 1;
		}
	message_vision(HIW"$N��ת��ץ���һ������������������"+weapon->query("name")+HIW"�������˾��ضᣡ\n\n"NOR,me,target);
	message_vision(HIG"$Nֻ��$n���е�"+weapon->query("name")+HIG"��ͬ��������һ�㣬ֻ�÷��֣�Ʈ���˿���\n"NOR,me,target);
			me->start_busy(1+random(2));
			me->add("neili",-150);
			return 1;

	}
	message_vision("����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�Ʈ��㿪$N�Ĺ�����\n",me,target);
	me->add("neili",-50);
	me->start_busy(1+random(2));
	return 1;
}