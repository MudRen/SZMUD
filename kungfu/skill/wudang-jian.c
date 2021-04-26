// Code of ShenZhou
// wudang-jian.c �䵱����
// xQin 12/98

#include <ansi.h>
#include <combat.h>

inherit SKILL;

int raozhi(object me, object victim, object weapon, int damage);
nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p�Ѵ����·磬��һ��$W�Խ��Ż��ص������쳣��\n",
	"$p�������飬��$P��ָ��$N��æ����ܿ���\n",
	"$p΢һ����һ��$W����˷�����������ס�ˣ�ʹ$P��Ҳ����������\n",
	"$p���漱ת����ס��·������һ���������ܿ���\n",
	"$p�������ˣ����빬̤��Ǭλ���߿�����̤��λ����ȥ$P�������ơ�\n",
	"$p�����Ƴ��ͣ�����Ӳ�ܣ�����һ����$W�����ƶϷ塹бɨ$P��\n",
	"$p$W������׹�ء�ֱ�����µ��ܡ�\n",
	"$p�Ҽ��������ʺ羭�졹��$W���á�\n",
	"$p�����˱ܣ��ؽ�б�ã�һ�С�б��һĨ��������$P��ָ��\n",
	"$p�������ܣ�ֻ��һ����������ָ����$P�ؿڴ�ȥ��$N��æ�����ù���\n",
});

string query_parry_msg(object weapon, object victim)
{
	object ob;

	if( !objectp(ob = victim->query_temp("weapon"))
	|| ob->query("skill_type") != "sword" || victim->query_skill("wudang-jian", 1) < 100 )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action = ({
([      "action": "$N����Ѹ�ݣ�$w���ƺ����롹�����˸�Ȧ�ӣ�һ��������ȥ��$w��Ӱ���Σ�ֱ��$n$l",
        "force" : 100,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "�ƺ�����",
        "damage_type": "����"
]),
([      "action": "$N���½������֣�һ·���ֽ���$n��ȥ��$w���׺���ա���$l��ȥ����������",
        "force" : 120,
        "dodge" : -10,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "�׺����",
        "damage_type": "����"
]),
([      "action": "$N������էչ����ͦ������$n$l��һ��$wʩչ���������������˿��������ˮ����������",
        "force" : 140,
        "dodge" : 10,
        "damage": 25,
        "lvl" : 20,
        "skill_name" : "����էչ",
        "damage_type": "����"
]),
([      "action": "$NͻȻԾ�𣬻��־���һ������������������һ���ֿ���׼�����������������Ѽ�$n$l",
        "force" : 170,
        "dodge" : 5,
        "damage": 35,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$N��������$n���ף�$w���������ơ���$w�����𴦣�������һ���ƿ�֮������$n��������",
        "force" : 190,
        "dodge" : -10,
        "damage": 40,
        "lvl" : 40,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "ٿ��$Nһ�С��������ӡ���$wһ���������漴ǧͷ�������ҵ��������������Ϸ���һ��",
        "force" : 210,
        "dodge" : 20,
        "damage": 45,
        "lvl" : 50,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$N��$nˢˢ�����������컨�꡹����Ȧ�ӣ�$w���֣����಻�ϣ����ǽ�����������������֮��",
        "force" : 230,
        "dodge" : 0,
        "damage": 55,
        "lvl" : 60,
        "skill_name" : "���컨��",
        "damage_type": "����"
]),
([      "action": "$N$w���ͷ����һ�������չ�᡹��$wһȦ������$P�������飬������磬���¿���֮�ʣ���Ʈ�ݣ�������",
        "force" : 250,
        "dodge" : 10,
        "damage": 45,
        "lvl" : 70,
        "skill_name" : "���չ��",
        "damage_type": "����"
]),
([      "action": "��������һ����һ��$w��$N����������������$n�����۵糸������$p$l��ȴ��һ�С����Ӻ�ա�",
        "force" : 280,
        "dodge" : 0,
        "damage": 50,
        "lvl" : 80,
        "skill_name" : "���Ӻ��",
        "damage_type": "����"
]),
([      "action": "Ǻ��һ��������������$w�ݳ���$NĿ�ӽ��⣬�������ͣ����ذα�������׹�⣬����һ�С��������ڡ�����ʽ",
        "force" : 300,
        "dodge" : -5,
        "damage": 50,
        "lvl" : 90,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$N����$w��������˸��$wԽʹԽ�죬ͻȻ��ת�������һ�����ȣ�ˢ��һ��������$n$l����һ�С�˳ˮ���ۡ��������䵱�����ľ���",
        "force" : 320,
        "dodge" : 0,
        "damage": 55,
        "lvl" : 100,
        "skill_name" : "˳ˮ����",
        "damage_type": "����"
]),
([      "action": "$Nһ����Х��$w�ݳ���ָ��$n��һ�С��ֻ����ҡ��������������죬�����������϶��µ��������£�������Ѱ��",
        "force" : 350,
        "dodge" : 0,
        "damage": 65,
        "lvl" : 110,
        "skill_name" : "�ֻ�����",
        "damage_type": "����"
]),
([      "action": "$N$wһ��ʹһ�С����񳯻ˡ������������Ҳ�����ʱ����绯Ϊ��ʮ�����⣬��ס$n���̣���һ����Ȼ�����������Ǳ������Ľ���",
        "force" : 380,
        "dodge" : 10,
        "damage": 75,
        "lvl" : 120,
        "skill_name" : "���񳯻�",
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query_skill("sword", 1) < 30 )
		return notify_fail("��Խ�������ʶ��������\n");

	if( (int)me->query_skill("wudang-jiuyang", 1) < 50 )
		return notify_fail("����䵱���������̫ǳ��\n");
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
	int i, level;
	object victim;
	string *limbs, limb, msg;

	level = (int)me->query_skill("wudang-jian", 1);
	if( objectp(victim = me->select_opponent()) )
	{
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
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
			"force" : 350+random(100),
			"dodge" : 10,
			"damage": 100+random(50),
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
	object weapon = me->query_temp("weapon");

	if( !objectp(weapon) || (string)weapon->query("skill_type") != "sword" )
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("jingli") < 50 )
		return notify_fail("�������������ϰ�䵱������\n");

	me->receive_damage("jingli", 30, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudang-jian/" + action;
}

int raozhi(object me, object victim, object weapon, int damage)
{
	int level = (int)me->query_skill("wudang-jian", 1)/2;
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

/*
$P���ƽ������಻�ϣ�һ�мȳ����ڶ���˳�Ƹ��ž���������˿���ϣ��������ࡣ
*/
/*
˭֪����춽����������ؾ�������ɻ�������һ�䣬���糤��֮�Σ���
�����롣Ѱ������ֻ�����һ�����������������ˮ��ˮ�Ľ�������������
�����������ۣ��ܹ���ȫȻ�벻����һ������˴̵���Σ����ֵĵ���Ťͷ
һ�࣬��ˮ����һ��������бб����һ������Ѫֱ�����졣
copyright by ����ɽɽׯ�� http://members.xoom.com/seisuke/
*/
