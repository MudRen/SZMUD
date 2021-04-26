// Code of ShenZhou
// feifeng-bian.c �ɷ�޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N���绬��������$wһ����ʹ��һʽ�����չ�᡹��$wѸ���ޱȵطִ�$n���������࣬$n��ʱ����֧穣������ֽ�",
	"dodge":  5,
	"damage": 10,
	"force" : 120,
	"lvl" : 0,
	"skill_name" : "���չ��",
	"damage_type":	"����"
]),
([	"action":"$N����һ�ݣ�Ծ�ڰ�գ�һʽ���ʷ����ࡹ������$w�������£������鶯֮��������$n$l",
	"dodge":		 15,
	"damage":		 25,
	"force" : 		160,
	"lvl" : 		12,
	"skill_name" : "�ʷ�����",
	"damage_type":	"����"
]),
([	"action":"$N��߳һ����һ�С����������$N�ƺ���ϵ���ƣ����������˿���룬����֮������$nȫ�������ڱ�Ӱ֮��",
	"dodge":		30,
	"damage":		35,
	"force" : 		220,
	"lvl" : 		24,
	"skill_name" : "����ʽ",
	"damage_type":	"����"
]),
([      "action":"$N����һ������������ԴԴ������ע��$w�����ʹ��һʽ������Ϸ���$w��ز���裬ֱ�������ƿ�һ�㣬ֱ��$n$l",
        "dodge":                 40,
        "damage":                45,
        "force" :               260,
        "lvl" :                 36,
        "skill_name" : "����Ϸ��",
        "damage_type":  "����"
]),
([      "action":"$Nһ����Х�������趯����$w������һ�С����ɷ��衹�����������Ӱ����ǵص���$n�������Ƶ�����֮��",
        "dodge":                 50,
        "damage":                55,
        "force" :               320,
        "lvl" :                 60,
        "skill_name" : "���ɷ���",
        "damage_type":  "����"
]),
([      "action":"$N��¶΢Ц�������ǰһ����������ü������ʹ��һʽ��������项������һƬ��ͣ�����Ҳƽ������������˿����������ȴ����ȻĪ��",
        "dodge":                 60,
        "damage":                70,
        "force" :               360,
        "lvl" :                 72,
        "skill_name" : "�������",
        "damage_type":  "����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	mapping fam;
	object weapon;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("����������㣬û�а취���ɷ�޷�������Щ���������ɡ�\n");

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("��Ŀ����������̫ǳ��\n");

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
	level   = (int) me->query_skill("feifeng-bian",1);
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
		return notify_fail("��ľ����������ɷ�޷���\n");
	me->receive_damage("jingli", 25 );
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("feifeng-bian", 1) >= 10 )
		return __DIR__"feifeng-bian/" + action;
}

