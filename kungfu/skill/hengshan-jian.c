// hengshan-jian.c ��ɽ����
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N����$w�����˸���Ȧ��бб��$n$l��ȥ",
    "force" : 120,
    "dodge" : 40,
    "damage" : 30,
        "lvl" : 0,
    "damage_type" : "����",
]),
([  "action" : "$NͻȻ�佫$w�����֣����ִ̳�",
    "force" : 140,
    "dodge" : 35,
    "damage" : 35,
        "lvl" : 3,
    "damage_type" : "����",
]),
([     "action" : "$NͻȻ�䲽��ǰ��һ�С�ʮ��ɱһ�ˡ�������$w��$n��$l����",
       "force" : 120,
       "dodge" : 20,
       "damage" : 55,
        "lvl" : 5,
        "damage_type":  "����"
]),
([     "action" : "$N��������һ����ͬʱһ������$w��һ�С��ѽ�ϥǰ�᡹����$n��$l��������",
       "force" : 120,
       "dodge" : 20,
       "damage" : 55,
        "lvl" : 9,
        "damage_type":  "����"
]),
([      "action" : "$N���к��䣬����бб��ʹ��һʽ�����ɻ�������·ȫ��б�ƣ�Ʈ�����ף�ż���ּ���һ����ʽ����$n����׽��",
        "force" : 140,
        "dodge" : -10,
        "damage" : 115,
        "lvl" : 20,
        "skill_name" : "���ɻ�",
        "damage_type" : "����"
]),
([      "action" : "$N����ƽ�̶������泯���ң�һ�С���Įƽɳ����$w�Ͻ�����ãĪ�⣬�����ޱߵش���$n��$l",
        "force" : 160,
        "dodge" : -5,
        "damage" : 111,
        "lvl" : 40,
        "skill_name" : "��Įƽɳ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��$w��һʽ������ɽ١�������Ѹ�����ף�$w�����������죬������$n$l�Ѳ������",
        "force" : 220,
        "dodge" : 5,
        "damage" : 125,
        "lvl" : 60,
        "skill_name" : "����ɽ�",
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ת��ʹ��һ�С����տ��㡹�����ȳ��ȣ�ֱ��$n$l��������Ԩͣ���ţ����ƹ�׾��ʵ���̲��������",
        "force" : 280,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 80,
        "skill_name" : "���տ���",
        "damage_type" : "����"
]),
([      "action" : "$N�ὣ��������һ�С�ѩӵ���š��ƣ���Ȼ����һ����ɭɭ�Ľ��⣬��$n��������ס",
        "force" : 340,
        "dodge" : 15,
        "damage" : 135,
        "lvl" : 100,
        "skill_name" : "ѩӵ����",
        "damage_type" : "����"
]) ,
([      "action" : "$N����бָ��أ�ʹһ�С�ľҶ������������һ�������Ⱪ�������������죬ת˲��������$n�����߰˴�Ҫ��",
        "force" : 380,
        "dodge" : 20,
        "damage" : 250,
        "lvl" : 120,
        "skill_name" : "ľҶ����",
        "damage_type" : "����"
]) ,
([      "action" : "$Nб��һ����һ�С��ͱڶ��ơ������Ƴ����վ����������ԣ�$w����$n��$l�����������֮�У������������������仯",
        "force" : 450,
        "dodge" : 20,
        "damage" : 270,
        "lvl" : 100,
        "skill_name" : "�ͱڶ���",
        "damage_type" : "����"
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail(HIC"�������������\n"NOR);
    return 1;
}


int practice_skill(object me)
{
        if ((int)me->query_skill("hengshan-jian",1) < 199)
           return notify_fail("�����ֻ�ܴ��ڶ��ټ�ʱ��ѧϰ��\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("hengshan-jian",1);
	if(me->query_temp("hengshan") 
	&& random(level) > 160 ){
        me->add("neili", -20);
        return ([
        "action":HIG"$N�ζ�$w��̤���ţ���ƫ�棬������˼����������ޱȣ�����ʵ�ң��ѵ���$n$l"NOR,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 400,
        "damage_type":"����"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100 ){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N��������������б������â�Ӱ����ֱк��������$n��$lն��"NOR,
        "force" : 480,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 350,
        "damage_type":"����"]);
        }


        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
    return __DIR__"hengshan-jian/" + action;
}

