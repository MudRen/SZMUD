// Code of ShenZhou
// zhutian-bu.c ���컯��

inherit SKILL;

mapping *action = ({
([	"action" : "$nһ�С���ع��������Žż�ǰ�ߣ�һ�����Ľ����ǰ�������⡣\n",
	"dodge"  : 10,
	"skill_name" : "��ع�"
]),
([	"action" : "$nһ�С����ͷ����ȫ���ʱ��û�˼����������ۣ�$N������ȫ���ڿմ���\n",
	"dodge"  : 20,
	"skill_name" : "���ͷ"
]),
([	"action" : "$nһ�С�ӥצ�ɡ����ڿ�һԾ���ڿ���һת��˫��ץ�أ�����������\n",
	"dodge"  : 30,
	"skill_name" : "ӥצ��"
]),
([	"action" : "$nһ�С���������������޹ǰ�����$N�Ĺ�����������ҡ�ڲ�������$N�޴����֡�\n",
	"dodge"  : 40,
	"skill_name" : "�����"
]),
([	"action" : "$nһ�С�����������˫��һ�٣�ȫ���ֱ�ذεض��𣬼�һ���䵽����Զ�ĵط���\n",
	"dodge"  : 50,
	"skill_name" : "������"
]),
([	"action" : "$nһ�С����¿ۡ���ͻȻ����Ϊ�����־�$N���������࣬������$N������\n",
	"dodge"  : 60,
	"skill_name" : "���¿�"
]),
});

string query_skill_name(int level)
{
	int zhaoshu = random(level/10);
	
	if ( zhaoshu >= sizeof(action) ) zhaoshu = sizeof(action)-1;

	return action[zhaoshu]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("zhutian-bu");

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
	if( (int)me->query("jingli") < 30 )
		return notify_fail("��ľ���̫���ˣ����������컯����\n");
	me->receive_damage("jingli", 30);
	return 1;
}
