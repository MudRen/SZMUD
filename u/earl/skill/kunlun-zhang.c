// kunlun-zhang.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$N�Ʒ缤����˫�ƴ��䣬���������޷���һ�С������ɽ��������$n��$l",
        "force" : 200,
                  "dodge" : -5,
                  "parry" : 5,
        "lvl" : 0,
        "skill_name" : "�����ɽ",
        "damage_type" : "����"
]),
([      "action" : "$N˫������һ�С������Ƶ�����һ�ƻ���$n���ţ���һ��ȴ����$nС��",
        "force" : 230,
                  "dodge" : 5,
                  "parry" : 10,
        "lvl" : 20,
        "skill_name" : "�����Ƶ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ������Ī�⣬һ�С���粻������ǰ�����ң�˲Ϣ֮����$n����������һʮ����",
        "force" : 300,
                "dodge" : 15,
                  "parry" : 20,
        "lvl" : 38,
        "skill_name" : "��粻��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ����Х������һ�ƣ�һ�С�ɽ��·ת��������ת׾��ȴ��ȥ����죬��$n��$l�ͻ���ȥ��",
        "force" : 280,
                  "dodge" : 20,
                  "parry" : 25,
        "lvl" : 55,
        "skill_name" : "ɽ��·ת",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƽ����������ޣ�һ�С������޷졹������$n��$l",
        "force" : 350,
                  "dodge" : 25,
                  "parry" : 25,
        "lvl" : 72,
        "skill_name" : "�����޷�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ɽ�Ϻӡ�������һȭ���������ƽ���������ȭ��һ����˫������������$n��$l",
       "force" : 400,
                  "dodge" : 25,
                  "parry" : 30,
        "lvl" : 87,
        "skill_name" : "��ɽ�Ϻ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫���뻮������˫�����ƣ�һ�С������ء���һ����ɽ������������ֱ��$n����",
        "force" : 450,
                  "dodge" : 30,
                  "parry" : 35,
        "lvl" : 101,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�������ת��һ�С���ɽѩƮ������Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 520,
                  "dodge" : 45,
                  "parry" : 40,
        "lvl" : 120,
        "skill_name" : "��ɽѩƮ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="zhentian-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("xuantian-wuji", 1) < 20)
                return notify_fail("��������޼�����򲻹����޷��������ơ�\n");
        if ((int)me->query("max_neili") < 200)
                return notify_fail("���������Ϊ�������޷��������ơ�\n");
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
        level   = (int) me->query_skill("kunlun-zhang",1);
        
          for(i = sizeof(action); i > 0; i--)
                                 if(level > action[i-1]["lvl"]) 
return action[NewRandom(i, 1, level/5)];
                              
}

int practice_skill(object me)
{

        if ((int)me->query("jingli") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("������������������ơ�\n");
        me->add("jingli", -25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kunlun-zhang/" + action;
}
