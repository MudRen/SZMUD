// Code of ShenZhou
// duanyun-bian.c ���Ʊ޷�
// sdong 09/98

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":               "$Nʹһ�С��ۻ𡹣�����$w�ڿ���ת��һȦ����Ȼ��׼$n���ظ�Ҫ����������",
        "dodge":                -5,
        "damage":               60,
        "force" :               160,
        "lvl" :                 0,
        "skill_name" : "�ۻ�",
        "damage_type":  "����"
]),
([      "action":               "$N������ң�һ�С���⡹������$w������⣬�͵���$n��ͷ����",
        "dodge":                -10,
        "damage":                95,
        "force" :               320,
        "lvl" :                 10,
        "skill_name" : "���",
        "damage_type":  "����"
]),
([      "action":               "$N����һת��ʹ��һʽ�����꡹������$w��������Ӱ���籩�����ɨ��$nȫ��",
        "dodge":                -15,
        "damage":               120,
        "force" :               480,
        "lvl" :                 20,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":               "$Nһ�С����ס�������$w�д�����֮������ɽ���������$nȫ��",
        "dodge":                -15,
        "damage":               110,
        "force" :               380,
        "lvl" :                 30,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":               "$N����һת��һ�С��Ƶ硹������$w�����һ�㣬��֪������Ϯ��$n",
        "dodge":                -10,
        "damage":                90,
        "force" :               300,
        "lvl" :                 40,
        "skill_name" : "�Ƶ�",
        "damage_type":  "����"
]),
([      "action":               "$Nһ����һ�С����硹������$wѸ���ޱȵ���$n��ͷ����",
        "dodge":                -10,
        "damage":                95,
        "force" :               300,
        "lvl" :                 50,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":               "$N������Σ��ҽź�Ȼ����һ�󲽣�һ�С�ֹ�硹������$w������Ϣ�ػ���$n",
        "dodge":                -10,
        "damage":                75,
        "force" :               300,
        "lvl" :                 60,
        "skill_name" : "ֹ��",
        "damage_type":  "����"
]),
([      "action":               "$N�����񹦣���������ע$w��һ�С����ơ�������$w���������֮�ƣ��͵���$nɨȥ",
        "dodge":                -10,
        "damage":                120,
        "force" :               420,
        "lvl" :                 70,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":               "$Nʹ��һ˦��ʹ��һ�С����¡����ڰ���ֻ��$w����һ˿��â���Ӳ���˼��ĽǶ���$n��������!",
        "dodge":                -10,
        "damage":                130,
        "force" :               520,
        "lvl" :                 120,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":               "$N����һԾ���ڰ����ʩչ�������ա���ɷ�Ǽ䣬���ذ��������е�$w�Ӱ������$nֱ������",
        "dodge":                -10,
        "damage":                150,
        "force" :               670,
        "lvl" :                 150,
        "skill_name" : "����",
        "damage_type":  "����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        mapping fam;
        object weapon;


        if( (int)me->query("max_neili") < 500 )
                return notify_fail("����������㣬û�а취�����Ʊ޷�������Щ���������ɡ�\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 50)
                return notify_fail("������칦���̫ǳ��\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������޷���\n");

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
        level   = (int) me->query_skill("duanyun-bian",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ������������Ʊ޷���\n");
        me->receive_damage("jingli", 10 );
        if( me->query_skill("duanyun-bian",1) > 150 ) me->receive_damage("jingli", 5 );
        if( me->query_skill("duanyun-bian",1) > 180 ) me->receive_damage("jingli", 10 );
        if( me->query_skill("duanyun-bian",1) > 200 ) me->receive_damage("jingli", 15 );

        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("duanyun-bian", 1) >= 50 )
                return __DIR__"duanyun-bian/" + action;
}
