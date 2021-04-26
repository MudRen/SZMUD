// Code of ShenZhou
// shaolin-shenfa.c ������

inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ��һέ�ɽ�����ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ\n",
	"dodge"  : 10
]),
([	"action" : "$nһʽ�������Ӳ�����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
	"dodge"  : 20
]),
([	"action" : "$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
	"dodge"  : 30
]),
([	"action" : "$nһʽ������Ӱ����һת��䣬����˷�Ʈ����������$n����Ӱ����$N������롣\n",
	"dodge"  : 40
]),
([	"action" : "$nһʽ���������ա���ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
	"dodge"  : 50
]),
([	"action" : "$nһʽ������˫�ɡ��������������������ݷ����У���$Nͷ����Ծ������\n",
	"dodge"  : 60
]),
([	"action" : "$nһʽ��������ˮ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
	"dodge"  : 70
]),
([	"action" : "$nһʽ���ɷ�鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�\n",
	"dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shaolin-shenfa");

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

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
*/
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 40 )
		return notify_fail("��ľ���̫���ˣ���������������\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shaolin-shenfa/" + action;
}
