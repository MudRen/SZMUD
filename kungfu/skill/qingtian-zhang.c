// Code of ShenZhou
// qingtian-zhang.c, ������
// snowbird, July 99
// 1.1.1.1

inherit SKILL;

mapping *action = ({
([      "action": "$Nһ��һ������һʽ����������������β���غ�������ɨ��$n��$l",
        "force" : 150,
        "dodge":  -5,
        "damage": 20,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 0,
        "skill_name" : "��������",
]),
([      "action": "$N���һ��������$w����һƬ���⣬һ�С�ҹս�˷�������$n��$l��ɨ��ȥ",
        "force" : 200,
        "dodge": -5,
        "damage": 30,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 10,
        "skill_name" : "ҹս�˷�",
]),
([      "action": "$N��Ȼһ����Х��һ�С����Ǹ��¡��� ����$w�ó������׹⣬��Ϯ$n�ظ�ҪѨ",
        "force" : 260,
        "dodge": -10,
        "damage": 40,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 20,
        "skill_name" : "���Ǹ���",
]),
([      "action": "$N���ζ�Ȼ�������ɶ࣬һʽ��ǧ��ѹ����������$w���ź�Х�ƿ����������",
        "force" : 320,
        "dodge": -10,
        "damage": 40,
        "damage_type": "����",
        "lvl" : 30,
        "skill_name" : "ǧ��ѹ��",
]),
([      "action": "$N����$n�Ų�δ�ȣ�������ǰ���У���Ȼһָ����β�𴦣�������ѰѨ����ֱȡ��$n�����¡�Ѫ��Ѩ��",
        "force" : 380,
        "dodge": -10,
        "damage": 40,
        "damage_type": "����",
        "lvl" : 40,
        "skill_name" : "����ѰѨ",
]),
([      "action": "$N��ͷһת��Ѹ��һ�С���ɨǧ����������Ѹ�ݣ�������������$n����·��ɨ��ȥ",
        "force" : 410,
        "dodge": -10,
        "damage": 45,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 50,
        "skill_name" : "��ɨǧ��",
]),
([      "action": "��Ȼ�䣬$N�����ȹ⻪��ʢ��$w���ơ���������������ʱ��$nȦ�ڵ���",
        "force" : 440,
        "dodge": -10,
        "damage": 70,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 60,
        "skill_name" : "��������",
]),
([      "action": "$N����$w���������ҷ������������뺣��ʮ��ʮ����һʽ�����ƶϷ塹��$n��$l��ɨ��ȥ",
        "force" : 470,
        "dodge": -10,
        "damage": 75,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 70,
        "skill_name" : "���ƶϷ�",
])
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("force") < 30){
                return notify_fail("����ڹ���Ϊ���̫ǳ��\n");
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
        level   = (int) me->query_skill("qingtian-zhang",1);
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

        if (me->query_str() < 20)
                return notify_fail("��ı��������������ȡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ��������������ȡ�\n");
        me->receive_damage("jingli", 20);
        if(me->query_skill("qingtian-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("qingtian-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
        return 1;
}
