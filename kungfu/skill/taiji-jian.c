// Code of ShenZhou
// taiji-jian.c ̫����
// cleansword 2/15/96
// Marz 5/21/96
// Fang 6/30/96
// xQin 3/99
// Modified 6/00 -xQin
#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_SSERVER;

int taiji(object me, object victim, object weapon, int damage);
int raozhi(object me, object victim, object weapon, int damage);
nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p���ֽ���б����$W��������˸���Ȧ��ƽ����$P$w֮�ϣ�����������$w��ʱһ����\n",
	"$p$W�����֣�����ǰ��������ԲȦ��$P��$p�������࣬��סȫ�����ް�ֿ�϶��\n",
	"$p����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬$P��ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸���ѡ�$P�۾�һ����ֻ�û��С�\n",
	"$p��������ר־����һ��̫������ʹ��Բת���⣬�����쳣����ס�Ż���\n",
	"$p��̫�����С��������衹��ʽ�⿪��$P��$p����ʱ�������ᣬ����ڼҽ�������������$p���֣�����һ����\n"
});

string query_parry_msg(object weapon, object victim)
{
	object ob;

	if( !objectp(ob = victim->query_temp("weapon")) || ob->query("skill_type") != "sword"
	|| victim->query_skill_mapped("sword") != "taiji-jian"
	|| victim->query_skill("taiji-jian", 1) < 100 )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action = ({
([	"action": "$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��$l",
	"force" : 120,
	"dodge" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "���ѵ�ˮ",
	"damage_type": "����"
]),
([	"action": "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹ֱ��$n��$l",
	"force" : 140,
	"dodge" : 15,
	"damage": 15,
	"lvl" : 5,
	"skill_name" : "ָ����",
	"damage_type": "����"
]),
([	"action": "$N�ҽŶ�����һ�С�����ǡ���$w��ǰ��󷴴�$n��$l",
	"force" : 160,
	"dodge" : 10,
	"damage": 15,
	"lvl" : 10,
	"skill_name" : "�����",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�̽��ʽ�����ҽŶ�������ϥ����$w��ǰ����$n��$l",
	"force" : 180,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 15,
	"skill_name" : "̽��ʽ",
	"damage_type": "����"
]),
([	"action": "$Nһ�С����ӳ�ˮ����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 200,
	"dodge" : 15,
	"damage": 25,
	"lvl" : 20,
	"skill_name" : "���ӳ�ˮ",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�������β�����ҽű��鲽�����ֻ��գ�$w���½���$n��$l",
	"force" : 220,
	"dodge" : 10,
	"damage": 25,
	"lvl" : 25,
	"skill_name" : "������β",
	"damage_type": "����"
]),
([	"action": "$Nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l",
	"force" : 190,
	"dodge" : 10,
	"damage": 30,
	"lvl" : 30,
	"skill_name" : random(2)?"����ɨ":"����ɨ",
	"damage_type": random(2)?"����":"����"
]),
([	"action": "$N�ҽ���ǰһ������ϥ����һ�С�����Ͷ�֡���$w��ǰ�Ϸ�����$n��$l",
	"force" : 210,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 35,
	"skill_name" : "����Ͷ��",
	"damage_type": "����"
]),
([	"action": "$Nʹһ�С�������ˮ�����ҽ����س���$w�������Һ󳷣�ͻȻ����ǰ������$n��$l",
	"force" : 230,
	"dodge" : 5,
	"damage": 40,
 	"skill_name" : "������ˮ",
	"damage_type": "����"
]),
([	"action": "$Nʹ�����������¡���$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",
	"force" : 240,
	"dodge" : 10,
	"damage": 40,
	"lvl" : 45,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([	"action": "$Nһת��$w���б����һ�С�����Ҷ��������$n��$l",
	"force" : 260,
	"dodge" : 5,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "����Ҷ",
	"damage_type": "����"
]),
([	"action": "$N��Ŷ�������ϥ����˫��������һ�С�����ͷ������������$n��$l",
	"force" : 260,
	"dodge" : 10,
	"damage": 40,
	"lvl" : 55,
	"skill_name" : "����ͷ",
	"damage_type": "����"
]),
([	"action": "$Nһ��������ش���һ�С�ʨ��ҡͷ����Ĩ��$n��$l",
	"force" : 280,
	"dodge" : 15,
	"damage": 45,
	"lvl" : 60,
	"skill_name" : "ʨ��ҡͷ",
	"damage_type": "����"
]),
([	"action": "$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž���������$n��$l",
	"force" : 280,
	"dodge" : 10,
   	"damage": 50,
	"lvl" : 65,
	"skill_name" : "����ָ·",
	"damage_type": "����"
]),
([	"action": "$N��ǰ����������һ�С�Ұ����������$w��ǰƽ��$n��$l",
	"force" : 300,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 70,
	"skill_name" : "Ұ������",
	"damage_type": "����",
]),
([	"action": "$Nһ�С�����ʽ�������Ծ����أ�$w�س飬���ֹ���$n��$l",
	"force" : 320,
	"dodge" : 10,
	"damage": 50,
	"lvl" : 75,
	"skill_name" : "����ʽ",
	"damage_type": "����"
]),
([	"action": "$N��һ�����鲽��$w��һ����Բ��һʽ��С���ǡ�����$n��$l",
	"force" : 320,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 80,
	"skill_name" : "С����",
	"damage_type": "����",
]),
([	"action": "$N˫�Ų�������������һ�С���Գ�׹�����$w��ǰƽ��$n��$l",
	"force" : 360,
	"dodge" : 0,
	"damage": 60,
	"lvl" : 85,
	"skill_name" : "��Գ�׹�",
	"damage_type": "����"
]),
([	"action": "$N�����ǰ��һ����$w�ɺ�һ��Բ��ǰ����һ�С�ӭ�絧����������$n��$l",
	"force" : 360,
	"dodge" : 5,
	"damage": 65,
	"lvl" : 90,
	"skill_name" : "ӭ�絧��",
	"damage_type": "����"
]),
([	"action": "$N���ǰ��һ��������$wһ�С�˳ˮ���ۡ������Һ󷽴���$n��$l",
	"force" : 360,
	"dodge" : 0,
	"damage": 70,
	"lvl" : 95,
	"skill_name" : "˳ˮ����",
	"damage_type": "����"
]),
([	"action": "$Nһ����ʹһ�С����Ǹ��¡�������$n��$l",
	"force" : 380,
	"dodge" : 5,
	"damage": 75,
	"lvl" : 100,
	"skill_name" : "���Ǹ���",
	"damage_type": "����"
]),
([	"action": "$N�ҽ���ǰ�沽��һ�С��������¡������������һ���󻡣���ǰ����$n��$l",
	"force" : 380,
	"dodge" : 0,
	"damage": 80,
	"lvl" : 105,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([	"action": "$N�ҽŶ���������$w��󳷣�����ǰƽƽ����һ�С�����ʽ������$n��$l",
	"force" : 400,
	"dodge" : -5,
	"damage": 85,
	"lvl" : 110,
	"skill_name" : "����ʽ",
	"damage_type": "����"
]),
([	"action": "$N��������ת��沽���ҽŸ�����һ�С��Ʒ��붴����$w�й�ֱ��������$n��$l",
	"force" : 420,
	"dodge" : -5,
	"damage": 90,
	"lvl" : 115,
	"skill_name" : "�Ʒ��붴",
	"damage_type": "����"
]),
([	"action": "$N�ҽź�һ����һת������$w��󷴻���һ�С�����չ�᡹��Ĩ��$n��$l",
	"force" : 420,
	"dodge" : -10,
	"damage": 95,
	"lvl" : 120,
	"skill_name" : "����չ��",
	"damage_type": "����"
]),
([	"action": "$Nһ��������������һ���鲽���������ҡ����ֽ��������಻������$n��$l",
	"force" : 450,
	"dodge" : -5,
	"damage": 100,
	"lvl" : 125,
	"skill_name" : "���ֽ�",
	"damage_type": "����"
]),
([	"action": "$Nһ�С������пա�����ǰԾ�䣬����$w������ǰ���£�Ʈ�ݵص���$n��$l",
	"force" : 450,
	"dodge" : -10,
	"damage": 120,
	"lvl" : 130,
	"skill_name" : "�����п�",
	"damage_type": "����",
]),
([	"action": "$Nʹһ�С���ɨ÷���������岻ͣ����ת������$w����ת�������׵糸����$n��$lɨȥ",
	"force" : 450,
	"dodge" : -15,
	"damage": 100,
	"lvl" : 135,
	"skill_name" : "��ɨ÷��",
	"damage_type": "����"
]),
});

string *taiji_msg = ({
	"$N��������̤�ϣ��������֣�һ�С��������¡�������ʵʵ�������ֽ����У������Ϲ�â��˸�������͵ķ�����΢����",
	"$N�������¿��ϡ�������������̫���������Ҫ֮���������˳���������һ���˿������಻��",
	"$N����$w������ǰ��������һ���Ρ�$nֻ��һ��ɭɭ������ֱ�ƹ���",
	"$N������������������$w��ס������ͻȻƽ�̣����⼱��������������δ���$P��һ����������$n�����ߴ�ҪѨ",
	"$N����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬$n��ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸����",
	"$N�������õĹ�ȦԽ��Խ�࣬������ʱ��$Pȫ��������������Ȧ֮�У���Ȧһ��δ������һ��������\n$w��ʹ�ü��죬ȴ������˿����������֮�����������֮�����Ѵ�춻���",
	"$nֻ������ǧ�ٱ�$w��ס��$Nȫ��$N�������ƣ��˵��Ǿ���������\n����������������ɵı���ȴ���ƶ���ǧ�ٸ���Ȧ�����˳�һ�㣬����ӿ��",
	"$N����һ��һ�е��๥����������ʮ�н�����ɵ����ƣ�ͬʱ��Ϊ���ƣ�ʹ$n�޷�����"
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������\n");
	if( (int)me->query_skill("taiji-shengong", 1) < 20 )
		return notify_fail("���̫���񹦻��̫ǳ��\n");
	if( (int)me->query_skill("mian-zhang", 1) < 20 )
		return notify_fail("������ƻ��̫ǳ��\n");
        return 1;
}

string query_skill_name(int level)
{
	int i;
	for( i = sizeof(action)-1; i >= 0; i-- )
		if( level >= action[i]["lvl"] )
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, busy_time;
	object victim;
	string *limbs, limb, target, msg;

	level = (int)me->query_skill("taiji-jian", 1);
	busy_time = level/20;
	if( objectp(victim = me->select_opponent()) )
	{
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		target = victim->name();
	}

	if( me->query_temp("double_attack") )
	{
		return ([
		"action": "ͻȻ֮�䣬$N�������֣�����һ������$n$l��������һ�¿�������",
		"force" : 350+random(100),
		"dodge" : 20,
		"damage": 100+random(50),
		"damage_type" : "����" ]);
	}

	if( me->query_temp("chan/"+target) )
	{
		victim->start_busy(2);
		me->add("neili", -20);
		me->add_temp("chan/"+target, 1);

		if( me->query_temp("chan/"+target) >= busy_time )
			me->delete_temp("chan/"+target);
	}

	if( me->query_temp("taiji") && me->query("neili") > 100 )
	{
		me->add_temp("taiji_fight", 1);
		me->add("neili", -10);
		return ([
		"action": taiji_msg[random(sizeof(taiji_msg))],
		"force" : 420+random(120),
		"dodge" : 100+random(50),
		"damage": 120+random(80),
		"damage_type" : random(2)?"����":"����",
		"post_action" : (: taiji :) ]);
	}

	if( random(me->query_temp("wudang/raozhi")) > 50 || me->query_temp("raozhi_attack") ) 
	{
		switch( me->query_temp("raozhi_attack") )
		{
			case 1: msg = "�����һ�����죬$w����������ֱ����$p$l";
				break;
			case 2: msg = HIC"˭֪$N�$w"HIC"���������ؾ�������ɻ�������һ�䣬���糤��֮�Σ���������"NOR;
				break;
			default: msg = HIW"ͻȻ��$N$w"HIW"�ƿգ�����$n"+limb+"��������;������΢������Ȼ���˹�ȥ��б��$p$l"NOR;
				break;
		}

		me->add_temp("wudang/raozhi", -1); 
		me->add("neili", -25);

		if( wizardp(me) )
			tell_object(me, sprintf("\nap: %d", COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK)));

		return ([
			"action": msg,
			"force" : 380+random(120),
			"dodge" : 10,
			"damage": 120+random(80),
			"damage_type":"����",
			"post_action": (: raozhi :)
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("jingli") < 50 )
		return notify_fail("��ľ���������̫��������\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}

int taiji(object me, object victim, object weapon, int damage)
{
	int n = random(2);

	if( damage == RESULT_DODGE ) 
	{
		if( n == 0 && me->query_skill_mapped("cuff") == "taiji-quan"
		&& me->query_skill_prepared("cuff") == "taiji-quan" )
		{
			me->set_temp("double_attack", 1);
			weapon->unequip();
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
			weapon->wield();
		}
		else
		{
			me->set_temp("double_attack", 2);
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
			message_vision("\n$N���ǽ������֣�����ǰ��������ԲȦ��$n��$P�������࣬��סȫ�����ް�ֿ�϶��\n", me, victim);
		}
		me->delete_temp("double_attack");

		return 1;
	}
	else if( damage <= 0 )
	{
		message_vision("$p����$P�����й��ྡྷ������Լ��ֱ��������顣\n", me, victim);
		if( !victim->is_busy() )
			victim->start_busy(1+random((int)(me->query_skill("force")/150)));
		victim->add("neili", -(int)(me->query_skill("force")/10));
	}
	return 1;
}
int raozhi(object me, object victim, object weapon, int damage)
{
	int level = (int)me->query_skill("taiji-jian", 1)/2;
	string ductile = weapon->query("id");

	me->add_temp("raozhi_attack", 1);

	if( damage == RESULT_DODGE && me->query_temp("raozhi_attack") < 3 ) 
	{
		me->add_temp("apply/attack", level);

		if( me->query_temp("raozhi_attack") == 1 ||
			( (ductile == "bailong jian" || ductile == "ruanjian"
				|| ductile == "shuixin jian") && me->query("neili") > 500 ) )
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		else me->delete_temp("raozhi_attack");

		me->add_temp("apply/attack", -level);
		return 1;
	}
	else me->delete_temp("raozhi_attack");
	return 1;
}


