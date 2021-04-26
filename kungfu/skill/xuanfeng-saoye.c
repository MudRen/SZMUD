// Code of ShenZhou

//xuanfengsaoye-tui.c
//kane 14/10/97  

inherit SKILL;


mapping *action = ({
([      "action" :"$N���ַ�����˫�㲻�����ˣ�ʹ��һ�С�������ӿ������ź���߳�������$n���ţ���ϥײ��$n����",
        "force" : 120,
	"parry" : -5,
        "lvl" : 0,
        "skill_name" : "������ӿ",
        "damage_type" : "����"
]),
([      "action" :"$N���������ˣ���Ȼһ�С��չ����������ؽڹ���֮����һŤ���ҽ�Ю�ž��磬������Ϣ������$n��$l",
        "force" : 150,
	"dodge" : 10,
	"parry" : -10,
        "lvl" : 8,
        "skill_name" : "�չ�����",
        "damage_type" : "����"
]),
([      "action" :"$Nʹ��С�����֣���ס$n�������ڼ��ᣬ���һ�С���Ԩ���ԡ�����Ӱ���ٵس�$nǰ���ߵ�",
        "force" : 200,
	"dodge" : 5,
	"parry" : -5,
        "lvl" : 15,
        "skill_name" : "��Ԩ����",
        "damage_type" : "����"
]),
([      "action" :"$N���һ����ǧ��׹���������ס���Σ�ʹ��һʽ�������Ҷ��������֧�أ�������������˲Ϣ���ɨ��Ȧ���Ƶ�$n��������",
        "force" : 250,
	"dodge" : 5,
	"parry" : -10,
        "lvl" : 20,
        "skill_name" : "�����Ҷ",
        "damage_type" : "����"
]),
([      "action" :"$N����۽�$n��ȥ���������ײ��$nС����$n�����ֵ���$N�������٣�һ�С���ɨ���ơ���������ϥ��˫��ԧ����������$n��$l",
        "force" : 300,
        "dodge" : 15,
        "parry" : -10,
        "lvl" : 30,
        "skill_name" : "��ɨ����",
        "damage_type" : "����"
]),
([      "action" :"$N����һ�ݣ�Ծ�ڰ�գ�һʽ������׹�ء����ҽ���ײ��$n���飬��ź�ɨ$nǰ�أ���غ�˫�����$n���ף�һ����ʽ��Ѹ���ޱ�",
        "force" : 350,
        "dodge" : 20,
	"parry" : -15, 
        "lvl" : 40,
        "skill_name" : "����׹��",
        "damage_type" : "����"
]),
([      "action" :"$N���η���ײ��$n��ʹ��һ�С�˷�紵ѩ����$N���������棬�ȷ���ã�������ɨֱ�ߣ��������ŷ��ߣ�����������ʮ���ֽ�һ�㣬$n��ʱ��Ŵ���",
	"force" : 400,
	"dodge" : 20,
	"parry" : -5,
	"lvl" : 50,
	"skill_name" : "˷�紵ѩ",
	"damage_type" : "����"
]),
([      "action" :"$N����̤�����а��Է�λ�����һ����ȣ�һʽ���׶����졹��ɲ�Ǽ���$n����������ʮ���ȣ���Ӱ��ɽ��$nȫ��Ҫ����һ���⣬�Ƶ��Ͷ�֮��",
	"force" : 450,
	"dodge" : 15,
	"parry" : -5,
	"lvl" : 60,
	"skill_name" : "�׶�����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="kick" || usage=="parry"; }

int valid_combine(string combo) { return combo=="luoying-shenjian"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ɨҶ�ȱ�����֡�\n");
	if ((int)me->query_skill("bitao-xuangong", 1) < 20)
	   return notify_fail("��ı���������򲻹����޷�ѧ����ɨҶ�ȡ�\n");
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
	level   = (int) me->query_skill("xuanfeng-saoye",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˡ�\n");
        me->receive_damage("jingli", 25);
	me->add("neili", -5);
       
       return 1;
}

string perform_action_file(string action)
{
       return __DIR__"luoying-shenjian/" + action;
}
