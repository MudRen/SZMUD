
// �غ�ָ��
// suhan-zhi.c
// V. 1.2

/*
[70] about �غ�ָ                             ���ڰ���(chchong)(Fri Aug 31)
----------------------------------------------------------------------
�ֻ����ң����ߵ��У�ľ���乭���༧��ʫ��;�϶���ҩ���������䣬�����ٳأ����ҹ����
$N������Σ���$nһ��֮�ʣ�������϶���룬һ�С����ߵ��С���$n����ġ�����Ѩ����ȥ��
$Nһ�С��ֻ����ҡ����ֿ������磬ٿ�Ĵ�����ָ������$n����ǰ��Ѩ��
$N����һת��һ���絽$n���һʽ��ľ���乭��������ʳָ������ָ��$n�ı���
$N����̤��һ���������������ʳָЮ��������������$n����ʽ����̹��������һʽ���༧��ʫ����
$NͻȻ�������һʽ�����ҹ���������������Ľ���׹������һָ����$n��
$N��Ȼ��ͷ��һʽ���϶���ҩ�������������$n��ȥ����ָȴ������$n�������ȥ��
$N������ָ����һ������Ȧ�ӣ�һ�С������ٳء�����ʱ����$n�ۻ����ң���֪���롣
$N����һԾ������$n������ϥһ��������ʳָ����һʽ���������䡹������$n�ĺ��ԡ�
*/

inherit SKILL;

mapping *action = ({
([      "action" : "$N������Σ���$nһ��֮�ʣ�������϶���룬һ�С����ߵ��С�����$n����ġ�����Ѩ����ȥ",
        "force" : 60,
        "dodge" : -5,
        "lvl" : 0,
        "skill_name" : "���ߵ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ֻ����ҡ����ֿ������磬ٿ�Ĵ�����ָ������$n����ǰ��Ѩ",
        "force" : 70,
        "dodge" : -5,
        "lvl" : 0,
        "skill_name" : "�ֻ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һת��һ���絽$n���һʽ��ľ���乭��������ʳָ������ָ��$n�ı���",
        "force" : 90,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "ľ���乭",
        "damage_type" : "����"
]),
([      "action" : "$N����̤��һ���������������ʳָЮ��������������$n����ʽ����̹��������һʽ���༧��ʫ��",
        "force" : 120,
        "dodge" : 5,
        "damage": 10,
        "lvl" : 9,
        "skill_name" : "�༧��ʫ",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�������һʽ�����ҹ���������������Ľ���׹������һָ����$n",
        "force" : 160,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 18,
        "skill_name" : "���ҹ��",
        "damage_type" : "����"
]),
([      "action" : "$N��Ȼһ��ͷ��һ�С��϶���ҩ�������������$n���ϴ�ȥ������ȴ������$n�������ȥ",
        "force" : 210,
        "dodge" : 20,
        "damage": 15,
        "lvl" : 27,
        "skill_name" : "�϶���ҩ",
        "damage_type" : "����"
]),
([      "action" : "$N������ָ����һ������Ȧ�ӣ�һ�С������ٳء�����ʱ����$n�ۻ����ң���֪����",
        "force" : 270,
        "dodge" : 25,
        "damage": 20,
        "lvl" : 36,
        "skill_name" : "�����ٳ�",
        "damage_type" : "����"
]),
([      "action" : "$N����һԾ������$n������ϥһ��������ʳָ����һʽ���������䡹������$n�ĺ���",
        "force" : 510,
        "dodge" : 50,
        "damage": 10,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="meinu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�غ�ָ��������֡�\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("�����Ů�ľ���򲻹����޷�ѧ�غ�ָ����\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����غ�ָ����\n");
    if (me->query("gender") != "Ů��")
        return notify_fail("�غ�ָ��ֻ��Ů���Ӳſ���ѧ��\n");
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
        level   = (int) me->query_skill("suhan-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������غ�ָ����\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 20 )
                return notify_fail("�����Ů�ľ���Ϊ��������\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("suhan-zhi", 1) >= 30 )
                return __DIR__"suhan-zhi/" + action;
}