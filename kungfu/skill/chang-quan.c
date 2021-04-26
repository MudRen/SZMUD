// Code of ShenZhou
// chang-quan.c �䵱��ȭ
// xQin 12/98

inherit SKILL;

mapping *action = ({
([	"action": "$N����һ����Ƶ������ģ�ʹ�С�����ʽ���ӻ���ȥ",
	"force" : 80,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "����ʽ",
	"damage_type": "����"
]),
([	"action": "$N��ȭһ���������ڡ�������$n��ȥ",
	"force" : 100,
	"dodge" : -5,
	"lvl" : 10,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$Nһ����֦���沽��˫ȭ���ֱޡ�����$n$l��ȥ",
	"force" : 135,
	"dodge" : -10,
	"lvl" : 20,
	"skill_name" : "�ֱ�",
	"damage_type": "����"
]),
([	"action": "$N�������ӳ���Ӧ��һ�С�һ���ޡ��ͻ�$n$l����������",
	"force" : 120,
	"dodge" : 15,
	"lvl" : 30,
	"skill_name" : "һ����",
	"damage_type": "����"
]),
([	"action": "$N����̤��һ���������ұۣ�ʹ��һ�С��������������Ʒ�����$n$l��ȥ",
	"force" : 150,
	"dodge" : 10,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$N������ǰ����������һ�С������֡���������$n��ȥ",
	"force" : 180,
	"dodge" : 30,
	"lvl" : 50,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$N˫��һ�֣�ʹ������ƽ�ġ������ӣ��������㣬������$nһȭ��ȥ",
	"force" : 250,
	"dodge" : 15,
	"lvl" : 60,
	"skill_name" : "ӡ��",
	"damage_type": "����"
]),
([	"action": "$N����һ����һ����ӡ�ơ����Ʒ��Ȼ����մ$n$l����һ���̾�������ȥ�ƻ���",
	"force" : 300,
	"dodge" : 0,
	"lvl" : 70,
	"skill_name" : "��ƽ��",
	"damage_type": "����"
]),
([	"action": "$Nͻ�����֣���$n$l��ȥ�����Ʒ������Ѹ鵽$pҸ�£�һ���������¡�����$p��ȥ",
	"force" : 333,
	"dodge" : 5,
	"lvl" : 80,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$Nʹ�С����ʽ���������ҽţ�һ��ԧ�������ȣ���������߳���ֱ��$n$l��ȥ",
	"force" : 300,
	"dodge" : 40,
	"lvl" : 90,
	"skill_name" : "���ʽ",
	"damage_type": "����"
]),
([	"action": "$Nһ�������ݲ������������棬̤��һ�����ѵ���$n�Ҽ�֮�࣬����һ�С����֡�����$p$l��ȥ",
	"force" : 350,
	"dodge" : 35,
	"lvl" : 100,
	"skill_name" : "����",
	"damage_type": "����"
]),
([	"action": "$N˫���ڻ���˳��ʹ��һ�С���������$n���������粨����ӿ����",
	"force" : 500,
	"dodge" : 20,
	"lvl" : 110,
	"skill_name" : "����",
	"damage_type": "����"
])
});

int valid_enable(string usage)
{
	return usage=="cuff" || usage=="parry";
}

int valid_combine(string combo)
{
	return combo=="mian-zhang";
}

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��ϰ�䵱��ȭ������֡�\n");

	if( !me->query_skill("taiji-gong", 1) && me->query_skill("chang-quan", 1)
		> me->query_skill("wudang-jiuyang", 1) + me->query_con() )
		return notify_fail("����䵱��������򲻹����޷�ѧϰ�䵱��ȭ��\n");

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("���������Ϊ̫�����޷���ϰ�䵱��ȭ��\n");
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
	int i, level, force;
	object target;

	i = random(sizeof(action));
	level = (int)me->query_skill("chang-quan", 1);
	force = (int)me->query_temp("hit_by");
	target = me->select_opponent();

	if( random(level) >= 180 && force )
	{
		message_vision("\n$N��$n�ľ����ټ�������������ȥ��", me, target);
		me->set_temp("hit_by", 0);
		return ([
			"action": action[i]["action"],
			"force" : action[i]["force"]+force,
			"dodge" : action[i]["dodge"],
			"damage_type": action[i]["damage_type"]
			]);
	}

	if( random(level) >= 110 && force )
	{
		message_vision("\n$N��$n�����ľ���������ȥ��", me, target);
		me->set_temp("hit_by", 0);
		return ([
			"action": action[i]["action"],
			"force" : force,
			"dodge" : action[i]["dodge"],
			"damage_type": action[i]["damage_type"]
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("�������������ϰ�䵱��ȭ��\n");

	if( (int)me->query("neili") < 20 )
		return notify_fail("�������������ϰ�䵱��ȭ��\n");

	me->receive_damage("jingli", 15, "����͸֧��������");
	me->add("neili", -5);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudang-unarmed/" + action;
}
