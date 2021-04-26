// dian.c �������� ��Ѩ
// modified by xuanyuan 29/07/2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	object ob;		
        int ap, dp, pp;
	string result, str, msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ѩֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("��ʹ�õ��������ԡ�\n");

//	if (!objectp(obj=present("jinling suo", me)))
//		return notify_fail("������û�н�����������ʹ�õ�Ѩ����\n");

	if( (int)me->query_skill("yinsuo-jinling", 1) < 120 )
		return notify_fail("����������岻�����죬��������Ѩ\n");

	if( (int)me->query_skill("tianluo-diwang",1)<120)
		return notify_fail("������޵����ƻ���㣬�ַ����������\n");

	if( (int)me->query_skill("yunu-xinjing",1)< 135)
		return notify_fail("����ڹ���Ϊ̫������޷����Ѩ��\n");
	
	if( (int)me->query("max_neili")<1200)
		return notify_fail("�������������ʩչ��Ѩ����.\n");
			
	if ( (int)me->query("neili") < 1000 )
		return notify_fail("�������������Ѩ��\n");

	msg = HIY "\n$N���Ͻ���ɳ���ʹ������������ϳ˵�Ѩ����ֱȡ$n�Ĵ�׵Ѩ��\n\n"NOR;

	ob = target->query_temp("weapon");
        ap = COMBAT_D->skill_power(me,"whip", SKILL_USAGE_ATTACK)*3;
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        ap = (ap+random(ap*2))/4;

        if( ap > dp )
	{
		me->start_busy(2);
		if (! objectp(ob))
		{
			int damage = 0;

			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += HIR "$n�������˼����ϳ���������û�ܶ����"
						"$N�Ľ���������$n��̴��Ѩ�ϣ�$nֻ����һ��"
						"�������Ե�����ϣ���������˵���������ܡ�\n";
					damage = 3;
					break;
				case 1:
					msg += HIR "$n����Ʈ�������鶯֮����������Ҫ�Ȳʣ�"
              					"�����ۡ���һ��������ܸ$n��ɫɷ�ף�ҡҡ��׹��\n";
					damage = 5;
					break;
				}
			} else
			if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch(random(2))
				{
				case 0:
					msg += HIR "$n���һ�����Գ�������ǿ�����ֳ��У���࣡�"
						"��һ�����죬�����ཻ��$n����΢�Σ������ֽ��\n";
					damage = 3;
					break;
				case 1:
					msg += HIR "$nһ����Х��˫�ֻû���������Ӱ����ס��ǰ��"
						"ֻ�����͡���һ������Ӱ������$n�Ѿ������ɫ�Ұס�\n";
					damage = 4;
					break;
				}
			} else
			{
				switch(random(2))
				{
				case 0:
					msg += HIR "$n�������У���Ȼ��֪��ܣ����͡���һ����$N"
						"�Ľ���������$n��׵Ѩ�ϣ�$nȫ������,�����ڵء�\n";
//					target->unconcious();
					damage = 5;
					break;
				case 1:
					msg += HIR "$nһת��Ѿ�����˾�ʮ���ֻ���İ취��"
						"��δ���ü�ʩչ��ֻ�����͡���һ�����ѱ�$N���д�׵Ѩ��ȫ�����������ڵء�\n";
//					target->unconcious();
					damage = 5;
					break;
				}
			}
			if (damage > 0)
				target->receive_damage("qi", target->query("max_qi") * damage / 15);
				me->add("neili", - (500 + damage*40) );
				me->start_busy(2 + random(3));
				message_vision(msg + NOR, me, target);
				str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
				message_vision("\n($N"+str+")\n", target);
			return 1;
		}
		if (ob->query("item_make"))
		{
			msg += HIR "$næ��" + ob->query("name") + "�мܣ�ֻ���û��ھ������ұ����������\n" NOR;
		} else
		{
			msg += HIW "$n��æ�мܣ�ֻ������ž����һ����$n���е�" + ob->name()+ HIW"�������ɣ�\n";
			ob->move(environment(target));       
		}
		target->start_busy(2);
		me->add("neili", - 200 );
	} else
	{
		int busy = 0;
		if (target->query_skill("dodge") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += "$nһ����Ц�������仯�˼����������˶�Ŀ��һʱ��$N�޷�������\n";
				busy = 2;
				break;
			case 1:
				msg += "$nͻȻ���Ʈȥ���������磬��$N���еĺ�̱仯�޴�ʩչ��\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += "$n��ɫ���أ��ӿ��ܣ����ɶ��ɣ���$N�޴����֣�ֻ���ջؽ��塣\n";
				busy = 3;
				break;
			case 1:
				msg += "$n������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�\n";
				busy = 1;
				break;
			}
		} else
		{
			switch (random(3))
			{
			case 0:
				msg += "$n��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
				busy = 2;
				break;
			case 1:
				msg += "$n������������ȥ�鶯���$Nһ�������ƶٻ���\n";
				busy = 2;
				break;
			case 2:
				msg += "$n��ס����������ע" + ob->query("name")
					 + "��������ס��$N�Ľ�����\n";
				busy = 2;
				break;
			}
		}
		target->start_busy(busy);
		me->start_busy( 2 + random(3) );
	}
	message_vision(msg + NOR, me, target);
	me->add("neili", - 500 );
	me->start_busy( 2 + random(3) );
	return 1;
}
