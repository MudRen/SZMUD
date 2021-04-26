// Code of ShenZhou
//qinnashou.c  ������
// arthurgu 1999/10

#include <ansi.h>
inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

string* buwei = ({
        "�����ⲿ",
        "����",
        "���ֹؽ�",
        "����",
        "�粿�ؽ�",
        "����ҪѨ",
        "ϥ�ؽ�",
        "����"
});

mapping *action = ({
([      "action" : "$Nʩ�����þ�����һ����ץ��$n��" + buwei[random(8)] + "",
        "force" : 400,
        "parry" : 5,
        "damage": 80,
        "lvl" : 10,
        "damage_type" : "����"
]),

});

int valid_enable(string usage) { return  usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������ֱ�����֡�\n");
        if ((int)me->query_skill("force", 1) < 20 || me->query("max_neili") < 50)
           return notify_fail("����ڹ���򲻹����޷�ѧ�����֡�\n");
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
        object victim;
        string bw;
        
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level   = (int) me->query_skill("qinnashou",1);
        
        bw = buwei[random(sizeof(buwei))];
        if ((int) me->query_skill("douzhuan-xingyi",1) > random(50) && level > random(240) && me->query("neili") > 300
        && me->query("combat_exp") > random(victim->query("combat_exp")*2) && random(2)==0) {
                me->add("neili", -50);
                message_vision(HIC"$N�����ü���Ȼ��ץס��$n��"+bw+"!\n"NOR,me,victim);
                message_vision(GRN"$N�˱ܲ�������$n����ס"+bw+",�ж�����ٻ�������\n"NOR,victim,me);
                victim->start_busy(1 + random(level/50));
        }

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
        me->receive_damage("jingli", 15);
        me->add("neili", -5);
       
       return 1;
}

