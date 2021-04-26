// Code of ShenZhou
// shiba-pan.c ̩ɽ�ɽ�����̩ɽʮ���̡�
// maco 1999.1.22
// testing..........

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

int ruhe(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action":"$Nչ�����ƣ����潣�ߣ�$w���һ�գ��ұ�һ�䣬�������ۣ���·���س��ȣ����ǡ���ʮ�ˡ�������",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "��ʮ��",
	"post_action": (: ruhe :),	
        "damage_type":  "����"
]),
([      "action":"$N�岽һת��ʮ��һ�أ�$w��·ԽתԽ�Ӻ�����������ʮ�ˡ�����ʹ���վ��ޱ�",
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 10,
        "skill_name" : "��ʮ��",
	"post_action": (: ruhe :),	
        "damage_type":  "����"
]),
([      "action":"$Nչ����·��ˢ��һ����һ�С�ʯ�ػ�����$w���ֿ���$n$l",
        "force" : 240,
        "dodge" : 10,
        "parry" : 10,
        "damage": 25,
        "lvl" : 20,
        "skill_name" : "ʯ�ػ���",
	"post_action": (: ruhe :),	
        "damage_type":  "����"
]),
([      "action":"$N$wһ�Σ����һ���������һ�С��������ơ���ת������������΢����$wб��$n$l",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 30,
        "lvl" : 20,
        "skill_name" : "��������",
	"post_action": (: ruhe :),	
        "damage_type":  "����"
]),
([      "action":"$N�������䷽λ���ܸ߷��ͣ�����Ȧת$w��һ�С������ա���$wֱ��$n$l��ȥ���漲",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 30,
        "lvl" : 20,
        "skill_name" : "������",
	"post_action": (: ruhe :),	
        "damage_type":  "����"
]),
([      "action":"$NͻȻһ������ͦ����$n�̵���һ�С�������Ȫ����һ���ȳ�����������������Ѹ������",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "damage": 40,
        "lvl" : 30,
        "skill_name" : "������Ȫ",
	"post_action": (: ruhe :),	
        "damage_type":  "����"
]),

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
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


	if(me->query_temp("ruhe_count") > 15 || me->query_temp("ruhe_hit")){
        me->add("jing", -100);	
        me->add("neili", -100);	
	me->set_temp("ruhe_finish");	
	me->delete_temp("ruhe_count");	
	me->delete_temp("ruhe_hit");	
        return ([
	"action":HIY"$N���ּ����ѱϣ�$w"+HIY"���У�����̩ɽ�ɽ����������ľ��ա������Ρ�����һ����׼��$n��һ��Ӧ�����ţ�ʵ��������ٱ��������"NOR,
        "force" : 450+random(20),
        "dodge" : 70,
        "parry" : 70,
        "damage": 120,
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }
	else if((int)me->query_skill("sword",1)> random(300)+120
 	&& me->query("neili") > 200 
	&& me->query_temp("ruhe")){
        me->add("neili", -20);
        return ([
	"action":YEL"$N$w"+YEL"ٿ����$n�̳�������������ÿһ���Ľ��нԲ�Ȼ�й��⣬�������ӣ��ڲ���䣬���ǡ����򽣡�"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 55+random(55),
        "skill_name" : "����",
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+100
	&& me->query("neili") > 100
	&& me->query_temp("ruhe")){
        me->add("neili", -10);
        return ([
	"action":HIC"$N��Ȼ��$n����������$w"+HIC"ʹ������������ˮ�����������߼��ᳵ������·֮�⣬��������������з��ӵ����쾡��"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 33+random(33),
        "skill_name" : "�����",
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }


        level   = (int) me->query_skill("shiba-pan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 60)
                return notify_fail("��ľ���������̩ɽʮ���̡�\n");
        me->receive_damage("jingli", 30);
        return 1;
}

int ruhe(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
		CYN"����$N������ָ���㣬����׼��$n����Ų��λ���ּ�ͦ�����У�\n"NOR,
		CYN"����$n���书��·�ѱ�$N�������������ۼ��ѱܿ�$N��������"+weapon->name()+CYN"����ֱ�ƶ�����\n"NOR,
        });
        if(damage==RESULT_DODGE && (int)me->query_skill("sword",1) 
> random(150)+100 && me->query_temp("ruhe")) {
                message_vision(msg[random(sizeof(msg))], me,victim);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
                return;
	   }
}


string perform_action_file(string action)
{
        return __DIR__"shiba-pan/" + action;
}
