// Code of ShenZhou
// shenlong-goufa.c ��������
// ywz 06/20/1997

inherit SKILL;

mapping *action = ({
([      "action" : "ֻ��$N˫��һ��һ�£�һ�С����츲�ء�ͬʱ����$n��ͷ�����Ȳ���",
	"force" : 120,
	"dodge" : 20,
	"damage" : 5,
	"lvl" : 0,
//	"damage_type" : "����"
]),
([      "action" : "ֻ��$Nǰ���鹥$n��������ȴ��Ѹ�ײ����ڶ�֮����$n��������ȥ����һ�С��������ϡ���",
	"force" : 140,
	"dodge" : 15,
	"damage" : 10,
	"lvl" : 0,
	"damage_type" : "����"
]),
([      "action" : "ֻ��$Nһ�С�ѩ����������˫�������ͬѩ���׷ɣ���$n��ȫ��£����$N˫��֮�¡�",
	"force" : 160,
	"dodge" : 10,
	"damage" : 15,
	"lvl" : 0,
	"damage_type" : "����"
]),
([      "action" : "ֻ��$Nʹ����������������һ������һ����һ������һ����һ���ǳɣ�ֱ��$n�������Ѩ��",
	"force" : 180,
	"dodge" : 5,
	"damage" : 20,
	"lvl" : 9,
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С������пա���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 200,
	"dodge" : 15,
	"damage" : 20,
	"lvl" : 9,
//	"damage_type" : "����"
]),
([      "action" : "$Nһ�С�������β�����ҽ����ϣ����ֻ��գ�$w���½���$n��$l",
	"force" : 220,
	"dodge" : 10,
	"damage" : 25,
	"lvl" : 9,
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С����Ķ��ǡ���˫��һ��һ�ң�һ���ǳɺ�ɨ$n��$l",
	"force" : 190,
	"dodge" : 10,
	"damage" : 25,
	"lvl" : 19,
	"damage_type" : "����"
]),
([      "action" : "$N�ҽ���ǰһ������ϥ����һ�С�������������$w��ǰ�Ϸ�����$n��$l",
	"force" : 210,
	"dodge" : 15,
	"damage" : 35,
	"lvl" : 19,
	"damage_type" : "����"
]),
([      "action" : "$Nʹһ�С�������թ�����ҽ����س���$w�������Һ󳷣�ͻȻ����ǰ������$n��$l",
	"force" : 230,
	"dodge" : 5,
	"damage" : 20,
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������ص�����$w��������Բ�������಻�ϻ���$n��$l",
	"force" : 240,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 29,
//	"damage_type" : "����"
]),
([      "action" : "$Nһת��˫�����б����һ�С��ɺ�λ���������$n��$l",
	"force" : 260,
	"dodge" : 5,
	"damage" : 45,
	"lvl" : 29,
	"damage_type" : "����"
]),
([      "action" : "$N˫���չ���΢һ��ͷ��һ�С�����˼������˫��ͻȻ���Ժ���$n��ȥ",
	"force" : 260,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 29,
	"damage_type" : "����"
]),
([      "action" : "$NͻȻ���������ҹ��ϣ�һ�С�����ҳ�����Ĩ��$n��$l",
	"force" : 280,
	"dodge" : 15,
	"damage" : 45,
	"lvl" : 39,
//	"damage_type" : "����"
]),
([      "action" : "$NͻȻ���ҹ��������ϣ�һ�С��Ҷ��󳤡���Ĩ��$n��$l",
	"force" : 280,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 39,
//	"damage_type" : "����"
]),
([      "action" : "$N˫�ֹ�ͷ���ڣ�һ�С����ܹ��ݡ�����ת���壬˫������$n",
	"force" : 300,
	"dodge" : 5,
	"damage" : 55,
	"lvl" : 39,
	"damage_type" : "����",
]),
([      "action" : "$Nһ�С���ţ���١���˫���໥��ײ���������$nһ��֮��ͻȻ����$n��$l",
	"force" : 320,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 49,
//	"damage_type" : "����"
]),
([      "action" : "$Nһ�С�һ�����á���˫��һ��һ�̻���$n",
	"force" : 320,
	"dodge" : 5,
	"damage" : 55,
	"lvl" : 49,
	"damage_type" : "����",
]),
([      "action" : "$N˫�Ų�������������һ�С���Ҷ���ҡ���˫����ǰƽ��$n�ĵ���",
	"force" : 360,
	"dodge" : 0,
	"damage" : 55,
	"lvl" : 49,
	"damage_type" : "����"
]),
([      "action" : "$N�����ǰ��һ����˫����������·�����ֱ����$n��������",
	"force" : 360,
	"dodge" : 5,
	"damage" : 55,
	"lvl" : 59,
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С�Ⱥħ���衹��˫���趯��סȫ����$nײȥ",
	"force" : 360,
	"dodge" : 0,
	"damage" : 65,
	"lvl" : 59,
//	"damage_type" : "����"
]),
([      "action" : "$Nһ����ʹһ�С��������ơ���˫������һ�е�����$n��$l",
	"force" : 380,
	"dodge" : 5,
	"damage" : 70,
	"lvl" : 69,
	"damage_type" : "����"
]),
([      "action" : "$N�ҽ���ǰ�沽��һ�С����Ǹ��¡�����ͻȻ��$n���˹�ȥ",
	"force" : 380,
	"dodge" : 0,
	"damage" : 75,
	"lvl" : 79,
	"damage_type" : "����"
]),
([      "action" : "$N����$w��󳷣�����ǰƽƽ����һ�С�����������$n��$l",
	"force" : 400,
	"dodge" : -5,
	"damage" : 80,
	"lvl" : 79,
	"damage_type" : "����"
]),
([  "action" : "$Nһ�С���·ͬ�项��˫���й�ֱ����һ��һ�´���$n��$l",
	"force" : 420,
	"dodge" : -5,
	"damage" : 85,
	"lvl" : 89,
	"damage_type" : "����"
]),
([      "action" : "$N������������һ�С����ͬ�١���ͷ�½��ϣ�˫����$n��ͷ����ȥ",
	"force" : 420,
	"dodge" : -10,
	"damage" : 85,
	"lvl" : 89,
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("��Ķ����󷨻��̫ǳ��\n");
	if ((int)me->query_skill("hook", 1) < 20)
		return notify_fail("��Ĺ���������������ʵ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level  = (int) me->query_skill("ruyi-gou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hook")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ�������������������\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ruyi-gou/" + action;
}

mapping *query_skilldbase() {return action;}
