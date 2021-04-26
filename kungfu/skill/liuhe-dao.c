// Code of ShenZhou
// liuhe-dao.c ؤ�����ϵ���
// qfy September 10, 1996

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N���һ��������$w�󿪴��أ������ӵ�ʹ�����Ǳ����졹��ն��$n��$l",
	"force" : 180,
        "dodge" : 2,
        "parry" : 2,
	"damage" : 30,
        "lvl" : 0,
        "skill_name" : "�Ǳ�����",
        "damage_type":  "����"
]),
([      "action":"$N�˵���磬һ�С����Ǻ�ɽ�������ưԵ�֮��������$n��������Ϳ�����",
        "force" : 200,
        "dodge" : 0,
        "parry" : 5,
	"damage": 40,
        "lvl" : 10,
        "skill_name" : "���Ǻ�ɽ",
        "damage_type":  "����"
]),
([      "action":"$Nһ�š����է�ϡ���ͻȻ����$n���࣬Ѹ�͵�������ն����ʽ��Ȼ�ϳ�һ��ԲȦ",
        "force" : 230,
        "dodge" : 0,
        "parry" : 5,
	"damage": 50,
        "lvl" : 25,
        "skill_name" : "���է��",
        "damage_type":  "����"
]),
([      "action":"$N���챯Ц���漴�ӵ�ն��һʽ������޳�����$w��Ϊһ˿˿���⣬����$n$l",
        "force" : 280,
        "dodge" : 5,
        "parry" : 10,
	"damage": 60,
        "lvl" : 35,
        "skill_name" : "����޳�",
        "damage_type":  "����"
]),
([      "action":"$Nʩչ���ͺ�����������$n������$w���ſ�Ұ���磬�����ޱȵ���������",
        "force" : 320,
        "dodge" : 10,
        "parry" : 0,
	"damage": 75,
        "lvl" : 45,
        "skill_name" : "�ͺ�����",
        "damage_type":  "����"
]),
([      "action":"$N��ɫׯ�أ��ӵ�ʹ�����������ҡ���$w���϶�����$n����������һ�������׺䶥",
        "force" : 360,
        "dodge" : 0,
        "parry" : 5,
	"damage": 90,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("��Ļ����������̫ǳ��\n");
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
        int i, level, num=0;
	object ob;

        level = (int)me->query_skill("liuhe-dao",1);
	ob = me->select_opponent();
	
	if ( me->query_temp("lianhuan") ) {
	   num = 1+random(2);
	   message_vision(YEL"\n$N����������������"+chinese_number(num+1)+"����\n"NOR, me);
	for ( i = 1; i < num; i ++ ) {
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	   }
        }
	
	for(i = sizeof(action); i > 0; i -- )
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ������������ϵ�����\n");
        me->receive_damage("jingli", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuhe-dao/" + action;
}
