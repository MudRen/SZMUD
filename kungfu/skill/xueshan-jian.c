// Code of ShenZhou
// xueshan-jian.c �����ǡ�ѩɽ���� 
// maco 

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N�ὣ��ɨ�����С�����ӭ�͡��������ǳ��ţ���ʵ�޻���żȻ���âһ�֣��ּ�������ȴ�����к��������غ���",
        "force" : 100,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "����ӭ��",
        "damage_type" : "����"
]),
([      "action" : "$N����$w������һ�Ž������������$n$l�������趯��Ѹ�����ף���һ�С�����˫÷������һ�У�ȴ�����̣�һ���̳�������ִ�һ��",
        "force" : 120,
        "dodge" : -10,
        "parry" : 15,
        "damage": 30,
        "lvl" : 5,
        "skill_name" : "����˫÷",
        "damage_type" : "����"
]),
([      "action" : "$n��ȡ���������ƣ�ʹ����һ�С���֦��б�����������������������������Ƚ���·�ӣ�����ٿ��һ����б��$n$l����ʽ���ӣ�ȴ����һ�������ĺݾ���",
        "force" : 140,
        "dodge" : 10,
        "parry" : -5,
        "damage": 25,
        "lvl" : 10,
        "skill_name" : "��֦��б",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ������ָ��Ѩ�����ţ�����΢̧���ڳ����ƺ����롹��ʽ�������ܼ�֮�У�$w���Ƶ�����ݳ����й�ֱ����������ָס��$n$l",
        "force" : 170,
        "dodge" : 5,
        "parry" : -10,
        "damage": 35,
        "lvl" : 10,
        "skill_name" : "�ƺ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�����̣������̳���ʹ������һ�С�˫���������������Į��ɳ�������۵���̬������$w����֮����Ȼ����",
        "force" : 190,
        "dodge" : -10,
        "parry" : -5,
        "damage": 40,
        "lvl" : 15,
        "skill_name" : "˫������",
        "damage_type" : "����"
]),
([      "action" : "$N$wͦ��ʹһ�С���ɳ��ʯ������Ю���磬�ھ�ֱ�ὣ�⣬�����㣬ֱ��$n$l��ȥ������Ѹ�ͣ������ݺ�",
        "force" : 210,
        "dodge" : 20,
        "parry" : -5,
        "damage": 45,
        "lvl" : 20,
        "skill_name" : "��ɳ��ʯ",
        "damage_type" : "����"
]),
([      "action" : "$N$w΢����бָ$n����һ�С���ɫ��ơ�ʹ���������ޣ��������ʣ����ѩɽ���������裬�����ޱ�",
        "force" : 230,
        "dodge" : 0,
        "parry" : 45,
        "damage": 55,
        "lvl" : 20,
        "skill_name" : "��ɫ���",
	"damage_type": random(2)?"����":"����"
]),
([      "action" : "$N�����з棬�͵�һ������$n$lֱ�̹�ȥ�����С�����Խ�롹������Ȼ���ýݺ�����������������֮��",
        "force" : 250,
        "dodge" : 10,
        "parry" : 0,
        "damage": 45,
        "lvl" : 25,
        "skill_name" : "����Խ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ὣ��ȫ�������������С���ɳçç����΢֮��ʹ�����쾡�£��������п���ɳ֮��ѹ��$wʹ������ʸ�鶯�����к���",
        "force" : 280,
        "dodge" : 0,
        "parry" : 10,
        "damage": 50,
        "lvl" : 30,
        "skill_name" : "��ɳçç",
	"damage_type": random(2)?"����":"����"
]),
([      "action" : "$N����ת�С�˷����𡹣�$w����ѩ������֮�ˣ�˷�����֮�ƣ�����Ѹ�ݣ�һ�д̳�����Ȼ�佣����ʢ��ȥ�Ʋ���������������������ȴ���÷������Ͷ���",
        "force" : 300,
        "dodge" : -5,
        "parry" : 5,
        "damage": 50,
        "lvl" : 35,
        "skill_name" : "˷�����",
        "damage_type" : "����"
]),
([      "action" : "$N�������Ử��һ����һ�С�����Ǽ�ѡ���������˸�У�$Nһ����Х��ˢˢˢ��չ���������Ľ����������$wֱ��$n��$l",
        "force" : 320,
        "dodge" : 0,
        "parry" : 5,
        "damage": 55,
        "lvl" : 40,
        "skill_name" : "����Ǽ��",
        "damage_type" : "����"
]),
([      "action" : "$N����������ͦ���̳�����ת���棬б��$n$l����һ�С�ѩ���צ��������λ���ɣ�������ѩɽ�ɽ����ľ���",
        "force" : 350,
        "dodge" : 0,
        "parry" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "ѩ���צ",
        "damage_type" : "����"
]),
([      "action" : "����$N$w������㽣�⣬һ�С�÷ѩ��������������ʵ��ʵ�����飬���⽣�����ã�������ѩ�㣬������÷֦������˷���$n���˹���������ҫ�ۣ��������ѩ���㽫����",
        "force" : 380,
        "dodge" : 10,
        "parry" : -10,
        "damage": 75,
        "lvl" : 50,
        "skill_name" : "÷ѩ����",
	"damage_type": random(2)?"����":"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("sword",1) < 30)
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
        int i, level;
        object target;

        level   = (int) me->query_skill("xueshan-jian",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( me->query_temp("xuehua") )
	{
		return ([
		"action": HIC"$N�����ᶶ��һɲ���г�$n����������ÿһ����ƾ����������ó�"+HIW"��ѩ��������"+HIC"���ַ�֮�죬ʵ�������ױȣ�����������ֻһ˲��֮��"NOR,
		"force" : 450+random(60),
		"dodge" : 30,
		"damage": 60+random(60),
	        "skill_name" : "ѩ������",
		"damage_type" : "����" ]);
	}
	if( random(4)==1 && random(level) > 150)
	{
		return ([
		"action" : HIY"$N����$w"+HIY"΢΢�����������������ޣ�����"+HIW"��������Ӱ��"NOR+HIY"��ѩɽ�������΢��һ�У�����÷���ڷ���ҡҷ�����������м�����÷����÷�ࡢ÷֦��÷�ɵ���̬������Ʈ�ݣ������֮"NOR,
        	"force" : 400,
        	"dodge" : -10,
        	"parry" : -20,
        	"damage": 120,
        	"lvl" : 60,
        	"skill_name" : "������Ӱ",
		"damage_type": random(2)?"����":"����"]);
	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���������ѩɽ������\n");
        me->receive_damage("jingli", 30);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xueshan-jian",1);
	jiali = me->query("jiali");
        if( me->query_temp("xuehua")  ) {
	victim->receive_wound("qi", random(jiali));
	return HIR"ֻ��$n$l����Ѫ���������㽣�۲������ǣ��ѱ�"+weapon->name()+HIR"��������Ĵ������㡣\n"NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"xueshan-jian/" + action;
}
