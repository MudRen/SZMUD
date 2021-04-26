// Code of ShenZhou
//Jay 10/7/96
// modified by sdong to add some damage 10/25/98
// modified by maco again 2/9/2000

#include "ansi.h"
inherit SKILL;

mapping *action = ({
([	"action": "$Nʹ��һ�С����߳�����������$wٿ��ٿ����ֱȡ$n��$l",
        "force" : 100,
        "dodge" : 10,
        "damage" : 15,
        "lvl" : 0,
	"damage_type": "����"
]),
([	"action": "$N����$w���һζ���һ�С�ҡͷ��β����$n��$l��ȥ",
	"force" : 120,
	"dodge":  0,
	"damage": 30,
	"lvl" : 0,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ�С������½�������$n��$l",
        "force" : 160,
	"dodge":  10,
	"damage": 40,
	"lvl" : 10,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����"
]),
([	"action": "$Nʩ��������ͦ����$w��β�ڵ�������һ�ǣ�����������$n��ȥ",
        "force" : 240,
	"dodge":  20,
	"damage": 60,
        "lvl" : 20,
	"damage_type": "����"
]),
([      "action": "$NͻȻͦ���£�����$wһ�С��������ߡ������ŵ�Ƥ����$n��$l",
        "force" : 300,
        "dodge":  20,
        "damage": 70,
	"lvl" : 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����"
]),
([      "action": "$N��Ȼ����鶯��һ�С��߲����ҡ����ȷ��ķ�������ס$n������$w����$n�������Ѩ",
	"force" : 350,
	"dodge":  5,
	"damage": 80,
	"lvl" : 40,
	"damage_type": "����"
]),
([      "action": "$N������ͻȻ��ǰ�˵���ʹ����������ɽ��������$w��ͷ����$n����ͷδ����һ�ɾ����ѽ�$n�Ƶ����Դ���",
	"force" : 400,
	"dodge":  0,
	"damage": 100,
	"lvl" : 50,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����"
]),
([      "action": "$N�͵ذ�$w������棬$w�ӵ��·�������$n������֮�⣬����һ�С������׵硹",
	"force" : 440,
	"dodge":  10,
	"damage": 120,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"lvl" : 60,
	"damage_type": "����"
]),

});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦�����̫ǳ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("staff")) > 60
	&& me->query_skill("force") > 90
	&& me->query("neili") > 120 && random(2) == 0) {
		return ([
		"action": HIB"$NͻȻ˫�ֳŵأ�˫���ס$w"+HIB"������һ���������$n"NOR,
		"force" : 500,
		"damage": 150,
		"damage_type": "����"]);
	}

	return action[random(sizeof(action))];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if (random(me->query_skill("lingshe-zhang",1))>30
		  && (me->query_temp("weapon"))->query("name")=="����") {
		victim->apply_condition("snake_poison",
					 random(me->query_skill("lingshe-zhang", 1)/2) +
		victim->query_condition("snake_poison"));
	if (victim->query("poisoner") != me)
		victim->set("poisoner", me);
        }
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ��������������ȷ���\n");
	me->receive_damage("jingli", 40);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lingshe-zhang/" + action;
}

