// Code of ShenZhou
// dashou-yin ���ڴ���ӡ
// qfy, chage, paoshou Sept 26, 1996
// ryu, 11/14/96.

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ����������ӡ����˫�����࣬Ĵָ��Сָ���������΢Ц���۽�$n����ǰ��ӡ��$n��$l",
	"force" : 140,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "��������ӡ",
	"damage_type" : "����"
]),
([	"action" : "������$N��ָ���壬Ĵָ����΢�֣��ֽᡸ���ƹ���ӡ������$n��ͷ���£��Ʋ��ɵ�",
	"force" : 200,
        "dodge" : 10,
        "lvl" : 10,
        "skill_name" : "���ƹ���ӡ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��׼���ĸӡ������ָ���棬ʳָ���죬������˼״��ͻȻ�������ӡ����$n��$l",
	"force" : 250,
        "dodge" : 5,
        "lvl" : 20,
        "skill_name" : "׼���ĸӡ",
        "damage_type" : "����"
]),
([      "action" : "$N�ֽᡸ��������ӡ��������ŭ����������š���һ��ʤ���䣬������һ��һ�ã�׽��$n������·",
        "force" : 280,
        "dodge" : 5,
        "lvl" : 30,
        "skill_name" : "��������ӡ",
        "damage_type" : "����"
]),
([	"action" : "ȴ��$N˫����ȭ��ʳָǰ�죬������������һʽ��ҩʦ�����ӡ������$n��$l�ܹ�ȥ",
	"force" : 320,
        "dodge" : 0,
        "lvl" : 40,
	"damage" : 30,
        "skill_name" : "ҩʦ�����ӡ",
        "damage_type" : "����"
]),
([	"action" : "ֻ����$N���������󳪣���ɫׯ�ϵ�ʩչ�����½��ӡ����˫�ֽ��棬Ĵָ�����һ�¿�ס$n�羮��Ѩ������$n����һˤ",
	"force" : 380,
        "dodge" : 5,
        "lvl" : 50,
	"damage" : 40,
        "skill_name" : "���½��ӡ",
        "damage_type" : "����"
]),
([	"action" : "$N�渡΢Ц��˫�ֻ��գ������ഥ��һ������$n����ǰ��һʽ�����ֽ��ӡ����ס$n����������һ��",
	"force" : 420,
        "dodge" : 0,
        "lvl" : 60,
	"damage" : 45,
        "skill_name" : "���ֽ��ӡ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�������ǻ�ӡ����������������������䣬˫��һ����ס$n�첲�����˳��һ��",
        "force" : 450,
        "dodge" : 5,
        "lvl" : 70,
	"damage" : 55,
        "skill_name" : "�����ǻ�ӡ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yujiamu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ڴ���ӡ������֡�\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20
	&& (int)me->query_skill("xiaowuxiang", 1) < 20){
		return notify_fail("��������������򲻹����޷�ѧ���ڴ���ӡ��\n");
	}
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������ڴ���ӡ��\n");
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
	level   = (int) me->query_skill("dashou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������ڴ���ӡ��\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
