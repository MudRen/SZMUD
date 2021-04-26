// Code of ShenZhou

inherit SKILL;

mapping *action = ({
([      "action" : "$N����̽��������Ծ�𣬽���������ɣ��������ӣ�һ�С����б��¡�����һȭ��һȭ������$n��ȥ",
        "force" : 200,
        "dodge" : 10,
        "lvl" : 0,
        "skill_name" : "���б���",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�㣬�����Ƽ����ң�һ�С��ò��绢����ٿ������Ծ�����ڿ���Ťת���ӣ���ŷɳ�������$n��$l",
        "force" : 250,
        "dodge" : 20,
        "lvl" : 12,
        "skill_name" : "�ò��绢",
        "damage_type" : "����"
]),
([      "action" : "$N˫�������ҹ�����������һ�ƣ�һʽ����ѥת���������ֺ�ɨһȭ",
        "force" : 320,
        "dodge" : 5,
        "lvl" : 24,
        "skill_name" : "��ѥת��",
        "damage_type" : "����"
]),
([	"action" : "$N�����ᶶ��������ת��һʽ�����ɵ�ɽ������������ͻȻ��������$n��$l��ȥ",
	"force" : 400,
        "dodge" : 5,
	"lvl" : 36,
	"skill_name" : "���ɵ�ɽ",
	"weapon" : "����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	return notify_fail("���޷�������ȭ��\n");
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
	level   = (int) me->query_skill("yanqing-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	return notify_fail("�㲻��������ȭ��\n");
}

