// Code of ShenZhou
// panlong-zhang.c �����ȷ�
// by Long
// ������ˮ $N������ǰһ�ˣ�$wͻȻ�����¼���������������ϻ���$n��$1
// ������β $N�Ӷ����е�$w��$nӭ�����£�$n��Ҫ������$NͻȻ˫��һ����$wβ��$n��$1��ȥ��
// �����ֺ�
// ������ͷ
// ˫��Ϸ��	$Nһ�����е�$w�� $w����������Ӱ��$n��$1���˹�ȥ
// Ⱥ������

inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
	"force" : 180,
	"dodge":  -5,
	"damage": 30,
	"damage_type": "����",
	"lvl" : 0,
	"skill_name" : "���ӿ���",
]),
([      "action": "$N����$w���裬һ�С�ɽ��ӿ䣡��Ʋ��ɵ��ع���$n��$l",
        "force" : 200,
        "dodge": -5,
        "damage": 40,
        "damage_type": "����",
        "lvl" : 10,
        "skill_name" : "ɽ��ӿ�",
]),
([	"action": "$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
	"force" : 250,
	"dodge": -5,
	"damage": 45,
	"damage_type": "����",
	"lvl" : 20,
	"skill_name" : "ɽ������",
]),
([      "action": "$N����$wб�ڣ�����һ����Բ����һʽ������ѩ�ء���$n����Ӱ������ס",
        "force" : 300,
        "dodge": -5,
        "damage": 55,
        "damage_type": "����",
        "lvl" : 30,
        "skill_name" : "����ѩ��",
]),
([	"action": "$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
	"force" : 350,
	"dodge": -10,
	"damage": 60,
	"damage_type": "����",
	"lvl" : 40,
	"skill_name" : "���·ת",
]),
([      "action": "$N����$w����һ����һʽ��ӥ��Ⱥ�ء���$w��β��ס$n��·��һ��$w������$n������",
        "force" : 400,
        "dodge": -5,
        "damage": 70,
        "damage_type": "����",
        "lvl" : 50,
        "skill_name" : "ӥ��Ⱥ·",
]),
([	"action": "$N����һ�ݣ�Ծ�ڰ�գ�$w�߾ٹ��������һ����ʹһ�С���ɽѩ����������$w�ó���ʮ����Ӱ����$n����Ҫ��������ס",
	"force" : 450,
	"dodge": -15,
	"damage": 80,
	"damage_type": "����",
	"lvl" : 60,
	"skill_name" : "��ɽѩ��",
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("�������������\n");
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
	level   = (int) me->query_skill("tianshan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������ɽ�ȷ���\n");
	me->receive_damage("jingli", 25);
	return 1;
}

