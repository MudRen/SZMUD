// yueying-wubu.c  ��Ӱ�貽
inherit SKILL;

mapping *action = ({
([	"action" : "$n����һ�Σ�����һŤ��һ�С��Ǻ����𡹣����ض���\n",
	"dodge"  : 10,
]),
([	"action" : "$nһ�С��辡�һ��ȵ׷硹��$Nֻ����ǰһ����������$n����Ӱ��\n",
	"dodge"  : 20,
]),
([	"action" :  "$nһ�С�ɨ�����Ʒ粻����������΢�Σ��о����յرܿ���$N��һ�С�\n",
	"dodge"  : 30,
]),
([	"action" : "ֻ��$n�������һ����һ�С�����º�Ӱ�����󵴶�������һ�ԡ�\n" ,
	"dodge"  : 40,
]),
([	"action" : "$nһ�С�����Ū��Ӱ�������䷭�ɣ����$N��һ�С�\n",
	"dodge"  : 50,
]),
([	"action" : "ȴ��$n�����꽭��һ�طɡ����������һ�����ۣ��������ۡ�\n",
	"dodge"  : 60,
]),
([	"action" : "����$nһ������ˮ�仨��ȥҲ��������һ�ã�$N��һ�����˸��ա�\n",
	"dodge"  : 70,
]),
([	"action" : "ֻ��$nһ�С����ִ���ˮ�޺ۡ����������Σ����������ת���˳����ɿ��⡣\n",
	"dodge"  : 90,
]),
([	"action" :  "$nϢ���������������һ�С���������Ӱ�ڲ���������ƮȻ����\n",
	"dodge"  : 100,
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("yueying-wubu");
        return action[random(zhaoshu)];
}

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 45 )
		return notify_fail("�������̫���ˣ������������貽��\n");
	me->receive_damage("qi", 35);
	return 1;
}

