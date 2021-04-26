// Code of ShenZhou
// yingzhua-qinna.c -ӥצ������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nٿ������һ������ۺ�ӣ�һת��˫��ʮָ��������ӥצ���Ͳ�$n��$l",
        "force" : 120,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 0,
        "damage_type" : "ץ��"
]),
([      "action" : "$N���������ĵ�������֮�������糱������һ����ͷ����һ����ͷ�����಻������˫������$nײ����ȥ",
        "force" : 160,
        "dodge" : 10,
        "parry" : 10,
        "damage": 5,
        "lvl" : 15,
        "damage_type" : "����"
]),
([      "action" : "$N�������ͣ�����һ�ƣ�����һȭ�����治���·�����ȴ�Ǵ������ޣ�������׾��ʵ������ѧ�еļ��߾���",
        "force" : 230,
        "dodge" : 0,
        "parry" : 0,
        "damage": 20,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N���ִ󿪴��أ��ߵ�ȫ�Ǹ���·�ӣ���Ȼ���һ����˫ȭ�����׿�ɽ������ɽ��������$n�ػ�",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 15,
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N����ת����˫�ƴ�ÿ켫���Ʒ����������Զ�����ɣ���$n������������",
        "force" : 340,
        "dodge" : 10,
        "parry" : 0,
        "damage": 15,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N����������һ���Ƴ�$n������������ǰ���������ˣ�ÿ̤��һ�����ŵױ���һ����ӡ��ͷ�ϰ�����������ʵ�ѷ��ӵ��˼���",
        "force" : 400,
        "dodge" : 0,
        "parry" : 0,
        "damage": 0,
        "lvl" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N�������ݣ�˫Ŀ������������������������һ����ȣ�����ɽ�鱮���ۻ�������������$n��ѹ��ȥ",
        "force" : 450,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "lvl" : 90,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ӥצ�����ֱ�����֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷���ӥצ�����֡�\n");
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
        level   = (int) me->query_skill("yingzhua-qinna",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�������������ӥצ�����֡�\n");
                
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

