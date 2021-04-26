// Code of ShenZhou
// mo-bang.c  ħ��
// by ALN 2 / 98

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N��ʽ�쳣��׾������$wֱָ$n����ͷ",
        "force" : 150,
        "dodge" : 30,
        "damage": 80,
        "lvl"   : 30,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type" : "����"
]),

([      "action": "$N���绬��������$w������ס$n���̸���",
        "force" : 200,
        "dodge":  30,
        "damage": 60,
        "lvl"   : 60,
        "post_action": (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :), 
        "damage_type" : "����"
]),

([      "action": "$Nһ�С���׾���ɡ���ȫ����Ȼ����һ�ţ����ֹ���ָ��$n����ҪѨ",
        "force" : 300,
        "dodge":  50,
        "damage": 80,
        "lvl"   : 90,
        "post_action": (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :), 
        "damage_type" : "����"
]),

([      "action": "$N����$w����ֱ�㣬��$n����������һ��ֱ��",
        "force" : 400,
        "dodge":  40,
        "damage": 60,
        "lvl"   : 120,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "stick" || usage == "parry"; }

int valid_learn(object me)
{
        return notify_fail("�ⲻ������ѧ����ѧ�ġ�\n");
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("mo-bang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        return notify_fail("�ⲻ���������������ġ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"mo-bang/" + action;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object v_weapon, my_weapon;
        int ap, dp;

        if( !objectp(v_weapon = victim->query_temp("weapon")) ) return;
        if( !objectp(my_weapon = me->query_temp("weapon")) ) return;
        if( my_weapon->query("skill_type") != "stick" ) return;

        ap = (int)me->query_skill("stick");
        ap += (int)me->query_temp("apply/attack");
        ap = ap * ap * ap;

        dp = (int)victim->query("combat_exp");

        if( random(ap + dp) > dp ) {
                message_vision(HIR"\n$Nһ���м��޷��İ�����̬��Ȼ��������" + my_weapon->name() + "������λʵ������˼���������\n"NOR, me);
                message_vision(HIR"$N�������������ò���������" + v_weapon->name() + "��������ϥ������$n��ǰ��\n\n"NOR, victim, me);
                v_weapon->unequip();
                v_weapon->move(environment(victim));
                victim->start_busy(1 + random(2));
        }
}
*/     
