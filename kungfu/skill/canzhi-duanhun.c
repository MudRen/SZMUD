// Code of ShenZhou
// bloody.c ��֫�ϻ�,for �Ǹ�PK�ҵ����ˣ���
//chaos 31/3/97 ��ҹ����ŭ���������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�ְ�ס$n����һ�ְ�ס��򢣬����һ�֣���$n�°�˺������",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$N����$n��һ��ҧס$n�ĺ���������һ��$n��ʳ�ܣ����ܣ�Ѫ��ȫ����˺��ϣ���ã���һ��������",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$N��ָ���$n����ǣ�����һ���⿪ͷ�ǣ���$n�Խ�һ��ץ�˳��������˼���",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$Nһ����ס$n������ҧ��$n�ظ��������ھͿеü����߹ǣ����¾Ͱ�$n�ظ�����˺���������ķε����������ɼ�",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$Nһ����Ц����ס$n������ץס$n˫�֣�ž��һ��������Ӳק���������ֱ����������Ӵ�Ѫ��ģ�����׹�ɭɭ",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$N��ס$n�ı���һ�þ�������һ�����죬$n�ļ�׵�Ƕϳ�ʮ�߶�ʮ�˽أ�$N�ٴ�$n������Ѫ���ܵس�����������ģ���ļ�׵��",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$Nץס$n�����ȣ�ʹ��һ˺����$n˺����Ƭ����Ѫ�Ľ���$n������ϡ���������һ��",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),
([      "action" : "$N��ָǶ��$n�۾���ʹ��ץ�Σ�һ��ץס$n���壬�þ�һ�ʣ�һŤ����һ����һ�¾Ͱ�$n��ͷק������",
	"force" : 20000,
	"dodge" : 100,
	"parry" : 100,
	"damage": 50000,
	"lvl" : 1,
//	"skill_name" : "",
	"damage_type" : "ץ��"
]),

});

int valid_enable(string usage) { return usage == "claw" || usage == "parry"; }

int valid_learn(object me)
{
	
		return notify_fail("�㲻��ѧ��֫�ϻꡣ\n");
	
}


mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	
		return notify_fail("�㲻������֫�ϻꡣ\n");
	
} 



