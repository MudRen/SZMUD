// Code of ShenZhou
// tiyunzong.c ������
// xQin 4/99

inherit SKILL;

mapping *action = ({
([	"action" : "$p��һ�������͵���˫��һ�ţ��������\n",
	"dodge"  : 10,
]),
([	"action" : "Σ����$p��һ��������˫�ۼ����ϴ����ࡣ\n",
	"dodge"  : 20,
]),
([	"action" : "$p����ݳ�������ͷ����һ�㣬���ȵķɳ�����֮�⡣\n",
	"dodge"  : 30,
]),
([	"action" : "$p���������Ծ��һתһ�ۣ��������ɵ�����һ�ԡ�\n",
	"dodge"  : 40,
]),
([	"action" : "��$p�������٣�������ǰ�߳���������Ȼ�����������ɵĿ����$P��\n",
	"dodge"  : 50,
]),
([	"action" : "$pһ����Х����������ڰ��������һ��ת�ۣ�ƮȻ��������֮�⡣\n",
	"dodge"  : 60,
]),
([	"action" : "��Ȼ��$p���ΰ����ڿ��м�����������ת�ĸ�Ȧ�ӣ���ת���ߣ�����һ��ת�ۣ��������ɵ���������֮�⡣\n",
	"dodge"  : 70,
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level = (int)me->query_skill("tiyunzong");

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
	return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("��ľ���̫���ˣ��޷���ϰ�����ݡ�\n");
	me->receive_damage("jingli", 30);
	return 1;
}
