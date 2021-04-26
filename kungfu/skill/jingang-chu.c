// Code of ShenZhou
// jingang-chu.c, ��ս�ħ��
// qfy, chage, paoshou Sept 27, 1996

inherit SKILL;

mapping *action = ({
([	"action": "$N��ɫׯ�ϣ�������ţ�ʹ��һ�С����������������$wɨ��$n��$l",
	"force" : 150,
	"dodge":  -5,
	"damage": 20,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����",
	"lvl" : 0,
	"skill_name" : "�������",
]),
([	"action": "$N����ŭ�ݣ����д�ȣ���̤��һʽ����շ�ħ����$w����$n��ͷ����",
	"force" : 200,
	"dodge": -5,
	"damage": 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����",
	"lvl" : 10,
	"skill_name" : "��շ�ħ",
]),
([	"action": "$Nһ�С���������������������дʣ���Ȼ�۷���⣬��������$w��ɨ$n��$l",
	"force" : 260,
	"dodge": -10,
	"damage": 40,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����",
	"lvl" : 20,
	"skill_name" : "�������",
]),
([      "action": "$Nһ�С���Ȥ��������������$w����չ�������Ľ��䣬���ۻ�$w����$n��$l",
        "force" : 320,
        "dodge": -10,
        "damage": 40,
        "damage_type": "����",
        "lvl" : 30,
        "skill_name" : "��Ȥ����",
]),
([      "action": "$Nһʽ���������ޡ����ڳ��ֻؾ������ȷ�����$w��β���ػ���$n",
        "force" : 380,
        "dodge": -10,
        "damage": 40,
        "damage_type": "����",
        "lvl" : 40,
        "skill_name" : "��������",
]),
([	"action": "��Ȼ��$Nһ������֮ɫ������$w�����뻡ʹ��������Ѫ����������$n��$l",
	"force" : 410,
	"dodge": -10,
	"damage": 45,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "����",
	"lvl" : 50,
	"skill_name" : "����Ѫ��",
]),
([      "action": "$Nһʽ��������ħ�������������������ԣ���$w���һƬ������$n��������",
        "force" : 440,
        "dodge": -10,
        "damage": 70,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 60,
        "skill_name" : "������ħ",
]),
([      "action": "$N��Ŀ������������������һ�����ʩչ����ħ������������$w���Ƴ����ֱ����$n��$l",
        "force" : 470,
        "dodge": -10,
        "damage": 75,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 70,
        "skill_name" : "��ħ����",
])
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20
	&& (int)me->query_skill("xiaowuxiang", 1) < 20){
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
	level   = (int) me->query_skill("jingang-chu",1);
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
                return notify_fail("��ı�����������ս�ħ�ơ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������ս�ħ�ơ�\n");
	me->receive_damage("jingli", 20);
        if(me->query_skill("jingang-chu", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("jingang-chu", 1) > 150)
        me->receive_damage("jingli", 5);
	return 1;
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("jingang-chu", 1) >= 150 )
                return __DIR__"jingang-chu/" + action;
}
