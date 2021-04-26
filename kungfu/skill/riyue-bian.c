// Code of ShenZhou
// riyue-bian.c ���±޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N����������һ�С���ʯʽ��������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
	"dodge":		-5,
	"damage":		60,
	"force" : 		160,
	"lvl" : 		0,
	"skill_name" : "��ʯʽ",
	"damage_type":	"����"
]),
([	"action":		"$N����һת��һ�С��ϴ�ʽ��������$w��������ڿ�һ���͵���$n��ͷ����",
	"dodge":		-10,
	"damage":		 95,
	"force" : 		320,
	"lvl" : 		60,
	"skill_name" : "�ϴ�ʽ",
	"damage_type":	"����"
]),
([	"action":		"$N������ң�һ�С�����ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"dodge":		-15,
	"damage":		120,
	"force" : 		480,
	"lvl" : 		90,
	"skill_name" : "����ʽ",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	mapping fam;
	object weapon;

	fam = me->query("family"); 
	if( !mapp(fam) || fam["family_name"] != "������" )
		return notify_fail("�㲻���������ɣ�����ѧϰ����������±޷���\n");

	if ( fam["family_name"] == "������" && fam["generation"] > 36 )
		return notify_fail("���ʸ񲻹�������ѧϰ���±޷����ȵ����˱�����˵�ɡ�\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("����������㣬û�а취�����±޷�������Щ���������ɡ�\n");

	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");

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
	level   = (int) me->query_skill("riyue-bian",1);
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
		return notify_fail("��ľ������������±޷���\n");
	me->receive_damage("jingli", 10 );
	if( me->query_skill("riyue-bian",1) > 150 ) me->receive_damage("jingli", 5 );
	if( me->query_skill("riyue-bian",1) > 180 ) me->receive_damage("jingli", 10 );
	if( me->query_skill("riyue-bian",1) > 200 ) me->receive_damage("jingli", 15 );

	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
		return __DIR__"riyue-bian/" + action;
}

