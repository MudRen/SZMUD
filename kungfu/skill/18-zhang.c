// Code of ShenZhou
// 18-zhang.c
// Modified by xQin 1/99

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int sanhui(object me, object victim, object weapon, int damage);

nomask int parry_available() { return 1; }
string *parry_msg = ({
	"$p��������һ�С�������β�������ֻ���һ�ơ�$P��$n���������׺ݣ�����Ӳ�ӣ�����ܿ���\n",
	"ֻ��$p����Բ��������ֱ�ƣ�ʹ�С����������������ǰ��һ�д��Ƿ�����ȴ����˫��֮�䲼��һ����ڡ�\n",
	"$p���²��ҵ�����˫�Ʒ��裬���Լ�ȫ������������֮�¡���һ�ص���������Ԩͣ���ţ�ֱ�ް��������\n",
});

string query_parry_msg(object weapon, object victim) 
{ 
	object me = victim->select_opponent();

        if ( victim->query_temp("weapon") || victim->query_skill("18-zhang", 1) < 100
        || victim->query_skill_prepared("strike") != "18-zhang" )
                return SKILL_D("parry")->query_parry_msg(weapon);
               
        else {
//		call_out("baiwei", 0, victim,me);
//		return parry_msg[random(sizeof(parry_msg))];

        string *slbw = ({
                "$n������������һ�С�������β������ȥ�����ǽ���ʮ�����еľ������У�$p���鼱֮��ʹ������������������������\n",
                "$n���ò�������������һ�С�������β����������$P����һ�ƣ�\n",
                "������һ˲֮�䣬$p��æת��ͬʱһ�С�������β����$P���ֺ�����\n",
        });
		message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
		return COMBAT_D->do_attack(victim, me, me->query_temp("weapon")) + "";
                }
}
/*
void baiwei(object victim, object me) 
{
        string *slbw = ({
                "$n������������һ�С�������β������ȥ�����ǽ���ʮ�����еľ������У�$p���鼱֮��ʹ������������������������\n",
                "$n���ò�������������һ�С�������β����������$P����һ�ƣ�\n",
                "������һ˲֮�䣬$p��æת��ͬʱһ�С�������β����$P���ֺ�����\n",
        });
        if (!me) return;
		message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
	        COMBAT_D->do_attack(victim, me, me->query_temp("weapon"));
}
*/
mapping *action = ({
([	"action": "$Nʹ�����������졹��Ծ���գ��Ӹ��»����������˫���絶�Ƽ���������$n$l��ȥ",
	"dodge": 20,
	"parry": 15,
	"force": 480,
	"damage": 25,
	"lvl": 5,
	"skill_name": "��������",
	"damage_type": "����",
	"weapon" : "��Ե"
]),
([	"action": "$N���˾�����˫��������磬ƽ�Ƴ�ȥ����һ�С���������ֿ����أ����������������",
	"dodge": 15,
	"parry": 25,
	"force": 400,
	"damage": 30,
	"lvl": 10,
	"skill_name": "��������",
	"damage_type": "����"
]),
([	"action": "$N�߼�������˫���뷢��ʩ��һ�С��轥��½����Ю��һ�ɾ�������$n$l���Ʒ�����������ͣ�������ٱ����������",
	"dodge": 20,
	"parry": 20,
	"force": 330,
	"damage": 35,
	"lvl": 15,
	"skill_name": "�轥��½",
	"damage_type": "����"
]),
([	"action": "$N����ͦ������������ơ���ȥ��磬����һ�С�������β�����������ģ����Ƹ���һ�£������������",
	"dodge": 15,
	"parry": 25,
	"force": 600,
	"damage": 110,
	"lvl": 20,
	"skill_name": "������β",
	"damage_type": "����"
]),
([	"action": "$N��������ʳ����ָ����ȭ���ƣ���$n$l��ȥ������һ�С�Ǳ�����á�������ͬʱ���ι��á������󹳣�ʹ$p��������",
	"dodge": 15,
	"parry": 25,
	"force": 450,
	"damage": 40,
	"lvl": 25,
	"skill_name": "Ǳ������",
	"damage_type": random(2)?"����":"����"
]),
([	"action": "$N���Ƶ��أ����ƴӿ�仺��ʰ�𣬻��˸���Ȧ��������ǰ��˫���������򣬽�������$n����һ�ơ�����󴨡�",
	"dodge": 20,
	"parry": 20,
	"force": 380,
	"damage": 45,
	"lvl": 30,
	"skill_name": "�����",
	"damage_type": "����",
	"weapon" : "�ƾ�"
]),
([	"action": "$n����һ����Ӱ������������δ������������$N�����ĳ���ʹ���ǵ�ʮһ�ơ�ͻ��������",
	"dodge": 15,
	"parry": 25,
	"force": 400,
	"damage": 50,
	"lvl": 35,
	"skill_name": "ͻ������",
	"damage_type": "����"
]),
([	"action": "$Nһ�С��𾪰����˫����ʩ���������Ʊ�������һ�㣬��$nֱ�ƹ�ȥ�����ǽ���ʮ���������������һ��",
	"dodge": 25,
	"parry": 15,
	"force": 420,
	"damage": 55,
	"lvl": 40,
	"skill_name": "�𾪰���",
	"damage_type": "����"
]),
([	"action": "$N��һ����������һ�죬һ�ơ���Ծ��Ԩ��������ǰ̽������ٿ�ش����Ƶ��´��˹�ȥ������$n$l",
	"dodge": 30,
	"parry": 10,
	"force": 450,
	"damage": 60,
	"lvl": 45,
	"skill_name": "��Ծ��Ԩ",
	"damage_type": "����"
]),
([	"action": "$N���Ƹߣ����Ƶͣ�ͬʱ�ĳ���˫�ƺ������죬ʹ��һ��Ȧ�ӣ�һ�С�˫��ȡˮ�����ͻ�$n$l",
	"dodge": 20,
	"parry": 20,
	"force": 470,
	"damage": 65,
	"lvl": 50,
	"skill_name": "˫��ȡˮ",
	"damage_type": "����"
]),
([	"action": "$N����ǰ�������ƴ�������״�����ʹһ�С���Ծ�Ԩ������Ծ�ڰ�գ����Ƹ��ַ�������֮ǰ����$nһ��",
	"dodge": 30,
	"parry": 10,
	"force": 500,
	"damage": 70,
	"lvl": 55,
	"skill_name": "��Ծ�Ԩ",
	"damage_type": "����"
]),
([	"action": "$N������ǰ��һ�С�ʱ����������$n�������ƣ�ÿһ�ƶ��Ǵ�ÿ���Х����ɳ��ʯ��������ͬС��",
	"dodge": 15,
	"parry": 25,
	"force": 520,
	"damage": 75,
	"lvl": 60,
	"skill_name": "ʱ������",
	"damage_type": "����",
	"weapon" : "�Ʒ�"
]),
([	"action": "$Nʹ��һ�С����Ʋ��꡹��ǰһ�ƣ���һ�ƣ�����$n����ת������ʱ��$pȫ������$P��������֮��",
	"dodge": 20,
	"parry": 20,
	"force": 550,
	"damage": 80,
	"lvl": 65,
	"skill_name": "���Ʋ���",
	"damage_type": "����"
]),
([	"action": "$Nʹ�����������ڡ���˫�������������$n$l��������ǿ���������̺��£�������֮�о��������������",
	"dodge": 10,
	"parry": 30,
	"force": 580,
	"damage": 85,
	"lvl": 70,
	"skill_name": "��������",
	"damage_type": "����"
]),
([	"action": "$N��ۺ�ɨ���Ƶ�$n����ǰ�����С���ս��Ұ��ʮ������ۼ�$p��$P��ۣ����ƺ���������$p$l֮��",
	"dodge": 20,
	"parry": 20,
	"force": 600,
	"damage": 90,
	"lvl": 75,
	"skill_name": "��ս��Ұ",
	"damage_type": "����"
]),
([	"action": "$N��������΢̧����ȭ���ƣ�ֱ�����ƣ�һ��һ���Ĵ��˳�ȥ������һ�С���˪��������һ��֮�и��Ტ�ã��������",
	"dodge": 25,
	"parry": 15,
	"force": 600,
	"damage": 95,
	"lvl": 80,
	"skill_name": "��˪����",
	"damage_type": random(2)?"����":"����"
]),
([	"action": "$N˫��ʹһ�С�����ެ��������彫��ȥ������һ��һ�����������£��͵�����$n$lб�Ƴ�ȥ",
	"dodge": 20,
	"parry": 20,
	"force": 330,
	"damage": 20,
	"lvl": 85,
	"skill_name": "����ެ",
	"damage_type": "����"
]),
([	"action": "$N����΢�����ұ����䣬���ƻ��˸�ԲȦ������һ����������ȥ������һ�С������лڡ�",
	"dodge": -20,
	"parry": 25,
	"force": 650,
	"damage": 120,
	"lvl": 90,
	"skill_name": "�����л�",
	"damage_type": "����"
])
});

int valid_enable(string usage) { return  usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ʮ���Ʊ�����֡�\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("��Ļ���������򲻹����޷�������ʮ���ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
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
	int x = 1 + random(8);
	int y = 3 + random(10);

	string *sanhui_msg = 
	({
		"$N������������һ�������ƺ���һ��������$n��ȥ������һ�С������лڡ��������������Ͳ��ɵ�",
		"$Nһ�Ƽȳ���������ǰ������һ�С������лڡ���������ǰ�ƣ�˫����������һ����ɽ������ѹ������",
		"$N��������һ�С������лڡ���ǰ������������������������������ŭ�ο�ӿ���Ʋ��ɵ�������һ�����εĸ�ǽ����$n��ǰ����",
	});

	if ( me->query_skill_mapped("force") == "huntian-qigong" )
	{
		if ( me->query_temp("sanhui") > 0 && me->query_temp("sanhui") <= 3 )
		{
			return ([
			"action": sanhui_msg[me->query_temp("sanhui")-1],
			"dodge": -20,
			"parry": 25,
			"force": 650,
			"damage": 120,
			"damage_type": "����",
			"post_action": (: sanhui :) ]);
		}
		else if ( random(me->query_skill("strike")) > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000 && me->query("jiali") > 150 )
		{
			me->add("neili", -50);
			return ([
			"action": HIY"$Nһ�С������лڡ���ƽ�Ƴ�ȥ�����Ƴ�ȥ�������赭д����һ��������ɲʱ֮������"+ chinese_number(y) +"���ᾢ��һ��ǿ��һ�������ص�����ֱ���޼᲻�ݣ���ǿ����"NOR,
			"dodge": -20+random(20),
			"parry": 25+random(20),
			"force": 650+random(150),
			"damage": 120+random(50),
			"damage_type": random(2)?"����":"����" ]);
		}
		else if ( random(me->query_skill("strike")) > 210 && random(me->query_skill("force")) > 150 && me->query("neili") > 500 && me->query("jiali") > 100 )
		{
			me->add("neili", -30);
			return ([
			"action": YEL"$N̤������������һ����һ�С������лڡ����ػ�ȥ����һ��"+ chinese_number(x) +"�ַ���"+ chinese_number(10-x) +"���գ�����ȥ�����أ�ʵ�Ƿ�ͬС��"NOR,
			"dodge": -20+random(100),
			"parry": 25+random(100),
			"force": 650+random(50),
			"damage": 120+random(20),
			"damage_type": random(2)?"����":"����" ]);
		}
	}

	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�����������������ʮ���ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"18-zhang/" + action;
}
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( me->query_temp("sanhui") ) 
		me->delete_temp("sanhui");
}
*/

int sanhui(object me, object victim, object weapon, int damage)
{
	if( damage > 0 && me->query_temp("sanhui") ) 
		me->delete_temp("sanhui");
}

mapping *query_skilldbase() {return action;}