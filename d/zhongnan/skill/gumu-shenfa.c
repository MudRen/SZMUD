// Code of ShenZhou
///kungfu/skill/gumu-shenfa.c ��Ĺ��
// sdong 07/24/98

inherit SKILL;

mapping *action = ({
([	"action" : "$n����ƮȻ������ָ�ᵯ��������Ů����ޱ����$N��������������ա�\n",
	"dodge"  : 10,
	"skill_name" : "��ޱ"
]),
([	"action" : "$n���ΰεض���ʹ��һ�С�ɢ������������裬$Nֻ���ۻ����ң�����ȫʧ��\n",
	"dodge"  : 20,
	"skill_name" : "ɢ��"
]),
([	"action" : "$n����һ�ݣ�Ծ�ڰ�գ��ڿ��з���һ����һ�С�Ͷ�㡱��ƮȻ����$N���\n",
	"dodge"  : 30,
	"skill_name" : "Ͷ��"
]),
([	"action" : "$n�ۼ����й�������������һ�࣬��Ȼһ�С���÷������ָ��ǰ��Σ�״��÷����$Nһ�ţ�������ʱʧ��׼ͷ��\n",
	"dodge"  : 40,
	"skill_name" : "��÷"
]),
([	"action" : "$n��Хһ��������һԾ���ڿշ������ɣ�һʽ��������������ܿ�$N�Ĺ���\n",
	"dodge"  : 50,
	"skill_name" : "���"
]),
([	"action" : "$n����һ����һʽ��ӳѩ��������һЦ�������������������ñܿ�$N������������\n",
	"dodge"  : 60,
	"skill_name" : "ӳѩ"
]),
([	"action" : "$n���λζ�����ȹ���裬�������޵�����$N������\n",
	"dodge"  : 70,
	"skill_name" : "��ȹ"
]),
([	"action" : "$n����ƮȻ����ʹ��һ�С����족������ƮƮ����̬���ݣ�����$N������\n",
	"dodge"  : 80,
	"skill_name" : "����"
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("gumu-shenfa");

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
		return notify_fail("��ľ���̫���ˣ���������Ĺ����\n");
	me->receive_damage("jingli", 30);
	return 1;
}
