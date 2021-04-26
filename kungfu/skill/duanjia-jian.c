// Code of ShenZhou
// Duanjia-jian �μҽ�
// Original, unknown; modified, by Acep

inherit SKILL;

mapping *action = ({
([      "action" :
"$N����һת��һʽ���ƺ����롹����$wƽָ�����������ڶ���һ���ǳɺ�ɨ$n��$l",
        "force" : 125,
        "dodge" : 5,
	"parry" : 15,
        "damage": 5,
        "lvl"   : 0,
        "skill_name" : "�ƺ�����",
        "damage_type" : "����"

]),
([      "action" :
"$N����һ�࣬����ǰ̤��ʹ��һʽ������ֱ�¡�����$w����$n��$l",
        "force" : 150,
        "dodge" : 0,
		"parry" : 15,
        "damage": 10,
        "lvl"   : 10,
        "skill_name" : "����ֱ��",
        "damage_type" : "����"

]),
([      "action" :
"$N��$wһ�ᣬһʽ��ѩӿ���ء���˫����������������������$n����һն",
        "force" : 180,
        "dodge" : 5,
		"parry" : 15,
        "damage": 20,
        "lvl"   : 20,

        "skill_name" : "ѩӿ����",
        "damage_type" : "����"

]),
([      "action" :
"��������һ�����죬$N����Ծ���ڰ�գ�һʽ����ɽ��ˮ����$w�������$n",
        "force" : 230,
        "dodge" : 25,
		"parry" : 5,
        "damage": 30,
        "lvl"   : 30,
        "skill_name" : "��ɽ��ˮ",
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type" : "����"

]),
([      "action" :
"$N����һЦ��һʽ���̼���������������$w�������һ����ת����$n��$l��ȥ",
        "force" : 250,
        "dodge" : 15,
		"parry" : 15,
        "damage": 40,
        "lvl"   : 40,
        "skill_name" : "�̼�����",
        "damage_type" : "����"
]),
([      "action" :
"$Nʹ��һʽ�����ͻ�𡹣�������Ȼһ��������$w�����Ƴ�,������$n����֮����ʮ���ٶȴ���$n��$l",
        "force" : 280,
        "dodge" : 5,
		"parry" : 0,
        "damage": 50,
        "lvl"   : 50,
        "skill_name" : "���ͻ��",
        "damage_type" : "����"
]),
([      "action" : 
"$Nͦ����ۣ������������������$w��ӣ�����$n��$l�����Ƕμҽ��������ơ������Ͻ�",
        "force" : 300,
        "dodge" : 10,
		"parry" : 0,
        "damage": 60,
        "lvl"   : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "�����Ͻ�",
        "damage_type" : "����"
]),
([      "action" :  
"$N����һԾ��һʽ�������ա����ڰ����ת������һ�ӣ�$w��ɶ�����ֱ��$n��$l",
        "force" : 320,
        "dodge" : 25,
		"parry" : 10,
        "damage": 65,
        "lvl"   : 70,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" :
"$N��Ȼ����һ��������$wէȻһ�֣�һʽ������滨�������쾢����ˮ��й�ذ����$n",
        "force" : 350,
        "dodge" : 5,
		"parry" : 30,
        "damage": 75,
        "lvl"   : 80,
		"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "����滨",
        "damage_type" : "����"
]),
([      "action" :   
"$Nȫ������������$w�������ߣ�һʽ����¹��ԭ����Ѹ�ײ����ڶ�֮�Ʊ���$n��$l",
        "force" : 380,
        "dodge" : 5,
		"parry" : 25,
        "damage": 85,
        "lvl"   : 90,
		"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "��¹��ԭ",
        "damage_type" : "����"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == 
"parry") || (usage == "staff"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20
		&& (int)me->query_skill("beiming-shengong", 1) < 20)
		return notify_fail("��Ŀ����������̫ǳ��\n");
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
	level=(int) me->query_skill("duanjia-jian",1);
    for(i=sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" 
		&& (string)weapon->query("skill_type") != "staff")
		return 
		notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ������㡣\n");
	me->receive_damage("jingli", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"duanjia-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;
	if (random(me->query_skill("yiyang-zhi", 1)) > 80
		&& objectp(weapon = me->query_temp("weapon"))
		&& weapon->query("skill_type")=="staff"
		&& weapon->query_temp("yiyang")) {
		victim->apply_condition("yyz_damage", random(me->query_skill("yiyang-zhi", 1)/2) + 
			victim->query_condition("yyz_damage"));
        victim->set_temp("yyzenemy", me->query("id"));
	}
}
