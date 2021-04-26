// qingyan-zhang.c ����������
// snowyu 2002/3
#include <ansi.h>
inherit SKILL;

mapping *action =
({
        ([
                "action" : "$N˫�Ʊ�����£�һʽ����������������$n��$l",
                "force" : 90,
                "dodge" : 5,
                "parry" : 20,
                "damage": 10,
                "lvl" : 0,
                "skill_name" : "��������",
                "damage_type" : "����"
        ]),
        ([
                "action" : "$N����΢�࣬����һʽ���������ơ�������ˮ�����бб�ĳ�",
                "force" : 140,
                "dodge" : 10,
                "parry" : 15,
                "damage": 20,
                "lvl" : 10,
                "skill_name" : "��������",
                "damage_type" : "����"
        ]),
        ([
                "action" : "$N˫��������������$n��$l�������Ʒ�֮�£�һʽ���̺����Ρ���$n��ȥ",
                "force" : 180,
                "dodge" : 15,
                "parry" : 20,
                "damage": 30,
                "lvl" : 20,
                "skill_name" : "�̺�����",
                "damage_type" : "����"
        ]),
        ([
                "action" : "$Nһʽ���������졹����ɫһƬ�԰ף�˫�ƻó������ѩ��������$n����",
                "force" : 210,
                "dodge" : 15,
                "parry" : 25,
                "damage": 35,
                "lvl" : 30,
                "skill_name" : "��������",
                "damage_type" : "����"
        ]),
        ([
                "action" : "$N���λζ����ó�������ӰΧ����$n���ߣ������ĳ�һ��������������һʽ������������",
                "force" : 260,
                "dodge" : 15,
                "parry" : 25,
                "damage": 50,
                "lvl" : 40,
                "skill_name" : "��������",
                "damage_type" : "����"
        ]),
        ([
                "action" : "$N˫��һ����һʽ��������ɢ��������$n�Ļ����;ƴ�������һ�",
                "force" : 420,
                "dodge" : 40,
                "parry" : 30,
                "damage": 60,
                "lvl" : 50,
                "skill_name" : "������ɢ",
                "damage_type" : "����"
        ])
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yiyang-zhi" || combo=="jinyu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����������Ʊ�����֡�\n");
        if ((int)me->query_skill("kurong-changong", 1) < 20
                && (int)me->query_skill("beiming-shengong", 1) < 20)
                return notify_fail("��Ŀ���������򲻹����޷�ѧ���������ơ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷������������ơ�\n");
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
        int i, j, pm, level;
       	object target;
	string *msg;

	level   = (int) me->query_skill("qingyan-zhang",1);
	pm = me->query_temp("piaomiao");
	target = me->select_opponent();
	weapon = me->query_temp("weapon");

	msg = ({ 
		HIM"\n$N��ɫ���죬������ͻ���죬һ�п���һ�С�\n"NOR,
                HIW"\n$N������ɢ���İ���ͻȻת"NOR GRN"��"NOR HIW"�����־���Ҳת������һ�֣������ھ���������������������\n"NOR,
                HIR"\n$N��ɫ����תΪ���죬���������������ھ����������������Χ��˫���������д���������ʽҲԽ��Խ�࣡\n"NOR,
                HBWHT BLK"\nֻ��$N���ϼ���ͻȻή���������ľ�������鶯��������ͻ��Ȼ���죡\n"NOR,
	});

	if( pm > 1 && pm < 6 && !me->query_temp("piaomiao_attack")) {

		message_vision( msg[pm-2] , me, weapon);
		me->set_temp("piaomiao_attack", 1);
		for( j=0; j < pm-1; j++ )
		{
			me->add("neili", -50);
			COMBAT_D->do_attack(me, target, weapon);
		}
		me->delete_temp("piaomiao_attack", 1);
		me->add_temp("piaomiao", 1);

	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������������ơ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"qingyan-zhang/" + action;
}
