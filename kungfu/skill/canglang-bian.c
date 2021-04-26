// Code of ShenZhou
// canglang.c
//chaos 22/3/97
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N�����������Ӷ�$w��ʹ��һ�С��󺣳�ɳ��������$w������$n��$l��ȥ��ȥ���䲻�����������Ƴ��ͣ���ͬѹ�˼�ǧ����ɳһ��",
	"force" : 200,
	"dodge" : 0,
	"parry" : 5,
	"damage": 40,
	"lvl" : 0,
	"skill_name" : "�󺣳�ɳ",
	"damage_type" : "����"
]),
([      "action" : "$N�ֳ�$w���룬һ�С�����һ�ߡ���$wһ�˶�Ȼһ��������$nǰ�أ�������������$n��·��ס����һ�������߳��������پ���$n����",
	"force" : 220,
	"dodge" : 0,
	"parry" : 10,
	"damage": 50,
	"lvl" : 12,
	"skill_name" : "����һ��",
	"damage_type" : "����"
]),
([      "action" : "$N���һ��������������ʹ��һ�С������ſա������Ƽӿ죬ֻ��ʮ���ر�Ӱ�羪�Ϻ��˰���$n��$l�������",
	"force" : 250,
	"dodge" : 0,
	"parry" : 5,
	"damage": 60,
	"lvl" : 24,
	"skill_name" : "�����ſ�",
	"damage_type" : "����"
]),
([      "action" : "$N����ת������$w��һʽ�������޲���������$wȥ������������˿���ƿ�֮����������֮���������$w�����������ѹε�����������",
	"force" : 280,
	"dodge" : 5,
	"parry" : 10,
	"damage": 70,
	"lvl" : 36,
	"skill_name" : "�����޲�",
	"damage_type" : "����"
]),
([      "action" : "$N�������߲���������ʹ��һ�С��׺�һ�ڡ���$w�Ϸ���������ɲ�Ǽ���ʮ����Ӱ������˷���$n����Ҫ������",
	"force" : 320,
	"dodge" : 10,
	"parry" : 5,
	"damage": 80,
	"lvl" : 48,
	"skill_name" : "�׺�һ��",
	"damage_type" : "����"
]),
([      "action" : "$N��Хһ����˫Ŀ�����ʢ��һ�С�ŭ�����Ρ�������չ�������ɨֱ����������������̼��ѽ�$nȫ���ס",
	"force" : 380,
	"dodge" : 15,
	"parry" : 15,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "ŭ������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("bitao-xuangong", 1) < 30)
	{
		return notify_fail("��ı����������̫ǳ��\n");
	}
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])

	return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("canglang-bian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon, where;
	
	where = environment(me);
	
	if (!where->query("guanchao")) 
		return notify_fail("����ϰ��һ������˱޷���������ôҲ���������˶��ֵľ��⡣\n");
	      
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ������������˱޷���\n");
	message_vision(HIC"$N��Ժ���������ӱޣ�ʹ�����뺣��ͬ���������о���������Ҳ�纣������һ�������޾���\n"NOR, me);
	me->add("neili", random(3));
	me->add("jingli", -30);
	return 1;
}

string perform_action_file(string action)
{
return __DIR__"canglang-bian/" + action;
}
