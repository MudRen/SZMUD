// Code of ShenZhou
// songshan-jian.c ��ɽ���� 
// maco 

#include <ansi.h>
#include <combat.h>

inherit SKILL;
int next_sword(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action":"$N$wһ�����ٽ���������������ʹһ�С��������ڡ������ǵ�ϵ���ڵ���ɽ������ͻȻ�佣��һ�£�$w����һ���׺磬��$nֱ�̹���",
	"force" : 100,
        "dodge" : 5,
	"parry" : 5,
	"damage": 0,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"$Nһ�����϶��£���$n$lֱ����ȥ����һ�С�������ɽ����ƽƽ���棬������һ���죬�ӿ��м������£�ȷ�п�ɽ��ʯ������",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "������ɽ",
	"damage_type":	"����"
]),
([	"action":"$N��������һ�֣�����$w�����ӳ���ʹ����һ�С����ż�ɽ���������ûʣ��Ƶ�������$wֱɨ$n$l",
	"force" : 260,
        "dodge" : 8,
	"parry" : 8,
	"damage": 70,
	"lvl" : 20,
	"skill_name" : "���ż�ɽ",
	"damage_type":	"����"
]),
([	"action":"$N����ʹ��һ�С�ǧ��������������������������ʵʵ���������࣬��һ����$n���г���������ת��һб��$wת��$n$l����",
	"force" : 330,
        "dodge" : 10,
	"parry" : 0,
	"damage": 80,
	"lvl" : 30,
	"skill_name" : "ǧ������",
	"damage_type":	"����"
]),
([	"action":"$N��·���飬ʹ��һ�С����両�ࡹ��$w���������������������ˢˢˢ��������������$n������",
	"force" : 400,
        "dodge" : 15,
	"parry" : 15,
	"damage": 70,
	"lvl" : 32,
	"skill_name" : "���両��",
	"damage_type":	"����"
]),
([	"action":"$N����$w������������һ�С�����ء��������࣬����ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ���������֮������֮ʦ������",
	"force" : 450,
        "dodge" : 15,
	"parry" : 15,
	"damage": 100,
	"lvl" : 50,
	"skill_name" : "�����",
	"damage_type":	"����"
]),
([	"action":"$N����$w������Ҽ�����ȥ��ʹ����ɽ�����ڽ�����������������$w�����ߣ�������������������ֱ������һ������һ�㣬���ڽ�ز�������ۻ�",
	"force" : 500,
        "dodge" : 10,
	"parry" : 10,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type":	"����"
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

        int i, level, xuli;
	level   = (int) me->query_skill("songshan-jian",1);
	xuli = me->query_temp("songshan_xuli");

	if (me->query_temp("s_hit"))
	return ([
	"action":HIW"ͻȻ�亮��һ����$N����$w"+HIW"ֱ����$n�������𵴶���������ʵ��Ǭ��һ�����ͻ���һ��֮�������������֮�ƣ�"NOR,
        "force" : 500 + xuli/5,
	"dodge" : 10,
        "parry" : 10,
        "damage": 200 + xuli/10,
	"post_action": (: next_sword :),	
        "damage_type":  "����"
]);

	
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
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������ɽ������\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songshan-jian/" + action;
}


int next_sword(object me, object victim, object weapon, int damage)
{
	int wap,wdp;
	object ob;
	ob = victim->query_temp("weapon");
        if(victim->query("eff_qi") < 0 && victim->query("qi") < 0) 
        {
        message_vision(HIW"�����Ž��������"+weapon->name()+HIW"һ����$n���ֱ������������һ���Ƶ�֮�������˵��Ƿ�����˼��ֻ�������һ����$n�ѱ�ն�����أ�\n"NOR, me,victim );
        
        }
        	
        else if( damage==RESULT_PARRY && objectp(ob = victim->query_temp("weapon")) ) 
        {
                
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str()
                        + (int)me->query("jiali")
                        + (int)me->query_skill("songshan-jian")/3
                        + me->query_temp("songshan_xuli");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query("jiali")
                        + (int)victim->query_skill("parry")/3;
                wap = random(wap/2)+wap/2;

                if( wap > 3 * wdp ) {
	message_vision(HIY"$N����"+weapon->name()+HIY"�����߾�����������һ���죬��$n��"+ob->name()+HIY"һײ��������ʮ���������ȥ��$n����"+ob->name()+HIY"��ϣ��۳���ʮ�ص��ڵ��£�\n"NOR, me,victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�����" + ob->query("name"));
//                      ob->set("value", (int)ob->query("value") / 10);
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > 2 * wdp ) {
                        message_vision(HIW"����$N����"+weapon->name()+HIW"�����߾���$n�ֱ����飬���ھ�ʹ��"+ob->name()+HIW"��ʱ���֣�\n" NOR,me,victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } else {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }

        return 1;
}
