// Code of ShenZhou
// jiangshi-bu.c
// qfy July 8, 1996

inherit SKILL;

mapping *action = ({
([	"action" : "$nֱͦͦ������һ�ݣ��ܿ���$N���������ơ�\n",
	"dodge"  : 10
]),
([	"action" : "$nֱͦͦ������һ����������$N�Ĺ��ơ�\n",
	"dodge"  : 20
]),
([	"action" : "$n����һƮ��ͻȻ����$N�����\n",
	"dodge"  : 30
]),
([	"action" : "$nӲ������ֱԾ�𣬽�$N�Ĺ��ƻ������Ρ�\n",
	"dodge"  : 40
]),
([	"action" : "$nͻȻ����һԾ������һ�ԡ�\n",
	"dodge"  : 50
]),
([	"action" : "$nͻȻ����һ�����ܹ���$N�Ĺ��ƣ��ֽ�ֱ�ı���վ��\n",
	"dodge"  : 60
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("jiangshi-bu");

	if (level < 60 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}