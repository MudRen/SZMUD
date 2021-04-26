// Code of ShenZhou
// yujia-muquan ������ĸȭ
// qfy, chage, paoshou Sept 26, 1996
// Ryu, 11/14/96.

inherit SKILL;

mapping *action = ({
([      "action" : "$N��ȭ���ඥ�������ֱ��$n�����������",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "�ඥ",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ְڡ���ࡹʽ����ȭ���������������Ϸ�������Ծ����б��ȣ�һȭ����$n��$l",
	"force" : 170,
        "dodge" : 5,
	"lvl" : 8,
	"skill_name" : "���",
	"damage_type" : "����"
]),
([	"action" : "$N�������ü�����������ڣ���ȭ������ȭ��������ž����ػ���$n$l",
	"force" : 200,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 16,
	"skill_name" : "�ü",
        "damage_type" : "����"
]),
([      "action" : "$N�������䣬һʽ����������ȭ���գ�����$n��$l",
        "force" : 240,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 24,
        "skill_name" : "���",
        "damage_type" : "����"
]),
([	"action" : "$N�������š�ʽ���ͷ��ڵأ���Ȼ��������˫��˫���������$n������ȭ����",
	"force" : 280,
        "dodge" : 15,
	"damage": 10,
	"lvl" : 32,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$N���΢̧���������������ȭ�繳������$n��$l",
        "force" : 320,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$N��̤���в���ʹ��һ�С����ġ����Ƶ�$n��࣬˫ȭ�ſ�������$n��$l",
        "force" : 320,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 48,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N˫ȭ�������΢Ц�к�����������$n���ɼ��Ȼ���ϣ�һ�С���ʤ��˫ȭ����$n����",
	"force" : 360,
        "dodge" : 5,
	"damage": 20,
	"lvl" : 56,
	"skill_name" : "��ʤ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="dashou-yin"; } 

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ��������֡�\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 10
	&& (int)me->query_skill("xiaowuxiang", 1) < 10){
		return notify_fail("����ڹ���Ϊ��򲻹����޷�ѧ������ĸȭ����\n");
	}
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���������ĸȭ����\n");
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
	level   = (int) me->query_skill("yujiamu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������������ĸȭ����\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yujia-muquan/" + action;
}
