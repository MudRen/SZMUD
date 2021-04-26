// Code of ShenZhou
// juehu.c ����צ�����֡�
// xQin 5/99
// relate file: /kungfu/condition/juehu_damage.c

#include <ansi.h>
#include <combat.h>
#include "damage_sys.h"

int perform(object me, object target)
{
	mixed foo;
	object weapon;
	string msg, unarmed, type, *limb;
	string attack_skill, dodge_skill, parry_skill;
	int ap, dp, pp, damage, tdamage, enfor, duration;
	int hand, dodge, amount;
	mapping prepare;
	mapping action = ([ "force" : 500, "damage": 1000 ]);

	if( !me->query("wudang/juehu") )
		return notify_fail("����δѧ�ᡸ��צ�����֡���\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩչ����צ�����֡���\n");		

	if( !target ) return notify_fail("��Ҫ��˭�ô˺��У�\n");

        if( !living(target) )
                return notify_fail("�����ڲ���ʹ�á���צ�����֡���\n");

	if( target->query_condition("juehu_damage") > 0 )
		return notify_fail("��λ" + RANK_D->query_respect(me) +"�ĳ�Ҳ̫���������αظϾ�ɱ����\n");
/*
	if( me->query("qi") > me->query("max_qi")/4
		&& !target->query("sell_woman/"+me->query("id")) )
		return notify_fail("��ʦ�̻壺��������������ͷ�����Ʋ������ô˺��С�\n");
*/
	if( !target->is_killing(me->query("id")) || !me->is_killing(target->query("id")) )
		return notify_fail("�㲢����"+ target->name() +"�����ಫ���ο��ô˺��У�\n");

	if( (int)me->query("neili") <= 200 )
		return notify_fail("����������̫�����޷�ʩչ����צ�����֡���\n");

	if( (int)me->query("jingli") <= 150 )
		return notify_fail("����������̫��޷�ʩչ����צ�����֡���\n");

	if( me->query_skill_mapped("force") != "taiji-shengong" 
		&& me->query_skill_mapped("force") != "wudang-jiuyang" )
		return notify_fail("�����õ��ڹ��롸��צ�����֡���·��㣣�\n");

	hand = (int)me->query_skill("hand", 1) / 2;
	dodge = (int)me->query_skill("dodge", 1) / 
		( 2 + target->query_temp("juehu_ob") );
	amount = (int)me->query_skill("force") / 3 +
		(int)me->query_skill("claw", 1) + (int)me->query_skill("finger", 1);

	// basicly wd dizi doesn't have claw and hand skill, 
	// so add this for add some temporary damage and success rate.
	me->add_temp("apply/damage", amount);
	me->add_temp("apply/attack", hand);

	// if victim is the first time meet this perform.
	// success rate will be more highher.
	me->add_temp("apply/dodge", dodge);

	msg = "\n$N���´�ת����һ����һ�����Ƶ���$n���ԡ�";
	me->add("jingli", -100);

	ap = COMBAT_D->skill_power(me, "hand", SKILL_USAGE_ATTACK);
	ap += COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( target->is_busy() ) dp /= 3;
	if( dp < 1 ) dp = 1;

	if( random(ap) < dp )
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += "\n" + SKILL_D(dodge_skill)->query_dodge_msg();
		me->start_busy(1+random(1));
	}
	else
	{
		weapon = target->query_temp("weapon");
		if( objectp(weapon) )
			switch( weapon->query("skill_type") )
			{
				case "sword" : 	msg += "����ʳ����ָһ�ţ��Ѽ�ס$W�Ľ���\n"; 
						break;
				case "hook"  :	msg += "����ʳ����ָһ�ţ��Ѽ�ס$W��\n"; 
						break;
				case "blade" : 	msg += "����̽������ץס��$W�ĵ�����\n"; 
						break;
				case "whip"  :	msg += "����̽������ץס��$W�ı��ң�\n";
						break;
				case "hammer":
				case "pike"  :
				case "staff" :
				case "club"  :
				case "stick" :	msg += "����̽������ץס��$W������ضᣡ\n"; 
						break;
				default      :	msg += "\n"; 
						break;
			}
		else msg += "\n";

		msg += HIR"����������̽����һ�С���צ�����֡����͵���ָ�ڳɻ�צ֮�Σ��⴫������ֱ��$nС����\n"NOR;
		me->add("neili", -200);

		ap = COMBAT_D->skill_power(me, "hand", SKILL_USAGE_ATTACK);
		ap += COMBAT_D->skill_power(me, "claw", SKILL_USAGE_ATTACK);
		if( ap < 1 ) ap = 1;

		pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
		if( objectp(weapon) ) pp /= 2;	// because we blocked victim's weapon,
		if( pp < 1 ) pp = 1;		// he can not use both hand to parry.

		if( random(ap + pp) < pp )
		{
			parry_skill = target->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available() ) 
				parry_skill = "parry";
			msg += SKILL_D(parry_skill)->query_parry_msg(me->query_temp("weapon"), target);
			// this is not bug :), I use me->query_temp("weapon"), because I don't 
			// want it appear weapon parry msg, we blocked victim's weapon already.
			me->start_busy(2+random(2));
		}
		else 
		{
			if( objectp(weapon) ) weapon->unequip();
			// because we blocked victim's weapon, so don't let it be a factor
			// when calculating damage.
			foo = damage_sys(me, target, "claw", me->query_temp("weapon"), action);
			if( objectp(weapon) ) weapon->wield();

			msg += (string)foo["result"];
			damage = (int)foo["damage"];

			// give victim those who doesn't have special force/dodge/parry
			// have a chance to attack back.
			if( random(target->query("combat_exp")) > me->query("combat_exp")*2/3 
				&& damage*2 > target->query("qi") )
			{

				msg += "$n�޿ɵֵ���";
				if( objectp(weapon) )
				{
					msg += "���ַ���$W��";
					weapon->unequip();
					weapon->move(environment(target));
				}
				target->reset_action();

				prepare = target->query_skill_prepare();
				if( !prepare ) prepare = ([]);

				switch( sizeof(prepare) )
				{
					case 0: attack_skill = "unarmed"; break;
					case 1: attack_skill = (keys(prepare))[0]; break;
					case 2: attack_skill = (keys(prepare))[random(2)]; break;
				}

				switch( attack_skill )
				{
					case "strike" :	msg += "������$N������";
							unarmed = "����";
							type = random(2)?"����":"����";
							break;
					case "cuff"   :	msg += "��ȭ��$N�ͻ���";
							unarmed = "ȭͷ";
							type = "����";
							break;
					case "claw"   :	msg += "��ָ��$N$l���䣬";
							unarmed = "��צ";
							type = random(2)?"����":"ץ��";
							break;
					case "finger" :	msg += "��ָ��$N$l��ȥ��";
							unarmed = "��ָ";
							type = "����";
							break;
					case "hand" :	msg += "������$N��ȥ��";
							unarmed = "����";
							type = "����";
							break;
					case "kick" :	msg += "�ɳ�һ������$N��";
							unarmed = "����";
							type = "����";
							break;
					default :	msg += "һ�ſ�ҧ��$N��$l��";
							unarmed = "����";
							type = "ҧ��";
							break;
				}
				msg += "ֻ�κ�$P����ͬ���ھ���\n";
				enfor = (int)target->query("jiali");
				target->set("jiali", (int)target->query("force")/2);

				ap = COMBAT_D->skill_power(target, attack_skill, SKILL_USAGE_ATTACK);
				pp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE);
				if( random(ap + pp) < pp )
				{
					msg += "$N���ֲ���$n"+ unarmed +"������ȴ�����˾����䡣\n";
					damage /= 2;
				}
				else
				{
					if( objectp(weapon) )
						msg = replace_string( msg, "$W", weapon->name() );
       					message_vision(msg, me, target);
					// end the msg here because $P & $p need to be exchange.

					foo = damage_sys(target, me, attack_skill,
						target->query_temp("weapon"), target->query("actions"));
					msg = (string)foo["result"];
					tdamage = (int)foo["damage"];
					if( tdamage < 0 ) tdamage = 0;

					me->receive_damage("qi", tdamage, target);
					if( random(tdamage) > (int)me->query_temp("apply/armor") )
						me->receive_wound("qi", tdamage - 
						(int)me->query_temp("apply/armor"), target);

					limb = me->query("limbs");
					msg += COMBAT_D->damage_msg(tdamage, type);
					msg = replace_string( msg, "$l", limb[random(sizeof(limb))]);
					msg = replace_string( msg, "$w", unarmed );

					message_vision(msg, target, me);
					// start a new msg here again.

					if( tdamage > 0 )
						msg = "( $N"+ COMBAT_D->status_msg((int)me->query("qi")
						*100/(int)me->query("max_qi")) + " )\n";
					else msg = "";
				}
				target->set("jiali", enfor);
			}
			if( damage < 0 ) damage = 0;

			target->receive_damage("qi", damage, me);
			if( random(damage) > (int)target->query_temp("apply/armor") )
				target->receive_wound("qi", damage - 
				(int)target->query_temp("apply/armor"), me);

			msg += COMBAT_D->damage_msg(damage, "����");

			if( damage > 0 )
			{
				msg+= "( $n"+ COMBAT_D->status_msg((int)target->query("qi")
					*100/(int)target->query("max_qi")) + " )\n";

				me->add("shen", -damage*100);
				me->add("wudang/juehu_usage", 1);

				duration = damage/10;
				target->add_temp("apply/attack", -duration);
				target->add_temp("apply/defense", -duration);
				target->set_temp("wudang/juehu_damage", 1);
				target->apply_condition("juehu_damage", duration);
				if( damage > target->query("max_qi")/3
					&& target->query("gender") == "����" )
				{
					target->set("gender", "����");
					target->set("ori_gender", "����");
					tell_object(target, HIB 
					"\n������ͻȻ�ӹ�һ˿�����Ԥ�У�����\n\n" NOR);
				}
			}
			else
			{
				msg += "$P��$p���ܳ��治��Ļ��⿪��һץ������ãȻ��֪���롣\n";
				me->start_busy(3+random(3));
			}

		}
	}
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -hand);
	me->add_temp("apply/dodge", -dodge);

	msg = replace_string( msg, "$l", "����");
	msg = replace_string( msg, "$w", "��צ��ָ");
	if( objectp(weapon) ) msg = replace_string( msg, "$W", weapon->name() );
	message_vision(msg, me, target);
	if( wizardp(me) ) tell_object(me, sprintf("damage: %d\n", damage));

	target->add_temp("juehu_ob", 1);
	me->reset_action();
	me->start_busy(1);
	return 1;
}
