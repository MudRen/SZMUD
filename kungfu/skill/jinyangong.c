// Code of ShenZhou
///kungfu/skill/jinyangong.c ���㹦
// sdong 07/24/98

inherit SKILL;

mapping *action = ({
([	"action" : "$n��ͷһ�ͣ����μ���������һ�С������伣����$N��������������ա�\n",
	"dodge"  : 10,
	"skill_name" : "�����伣"
]),
([	"action" : "$n���ΰεض���ʹ��һ�С�����˷�������������˷�����$n����Ӱ��$N��ʱãȻʧ�룬����ȫʧ��\n",
	"dodge"  : 20,
	"skill_name" : "����˷�"
]),
([	"action" : "$n����һ�ݣ�Ծ�ڰ�գ�һ�С��������족���ڿ��������������������ȵ�����$N���\n",
	"dodge"  : 30,
	"skill_name" : "��������"
]),
([	"action" : "$n�ۼ����й�������Ȼһ�С����жݱ䡱��������������һ�࣬�պñܿ�$N���͹���\n",
	"dodge"  : 40,
	"skill_name" : "���жݱ�"
]),
([	"action" : "$n��Хһ��������һԾ��һʽ��������������ڿշ������ɣ������ܿ�$N�Ĺ���\n",
	"dodge"  : 50,
	"skill_name" : "�������"
]),
([	"action" : "$n����һ����һʽ������ת��������Ȼת��$N���$N����һ���ա�\n",
	"dodge"  : 60,
	"skill_name" : "����ת��"
]),
([	"action" : "$n���λζ���ʹ��һ�С��������ޡ�������ʵ�ң���ǰ�����������޵�����$N������\n",
	"dodge"  : 70,
	"skill_name" : "��������"
]),
([	"action" : "$n����ƮȻ����ʹ��һ�С��������ա�����̬Ʈ�ݣ�����$N������\n",
	"dodge"  : 80,
	"skill_name" : "��������"
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("jinyangong");

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
	if( (int)me->query("jingli") < 40 )
		return notify_fail("��ľ���̫���ˣ����������㹦��\n");
	me->receive_damage("jingli", 30);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"jinyangong/" + action;
}
