// Code of ShenZhou
// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// by cleansword

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
        "force" : 180,
        "dodge":  -5,
        "damage": 30,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 0,
        "skill_name" : "���ӿ���",
]),
([      "action": "$N����$w���裬һ�С�ɽ��ӿ䣡��Ʋ��ɵ��ع���$n��$l",
        "force" : 200,
        "dodge": -5,
        "damage": 40,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 10,
        "skill_name" : "ɽ��ӿ�",
]),
([      "action": "$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
        "force" : 250,
        "dodge": -5,
        "damage": 45,
        "damage_type": "����",
        "lvl" : 20,
        "skill_name" : "ɽ������",
]),
([      "action": "$N����$wб�ڣ�����һ����Բ����һʽ������ѩ�ء���$n����Ӱ������ס",
        "force" : 300,
        "dodge": -5,
        "damage": 55,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 30,
        "skill_name" : "����ѩ��",
]),
([      "action": "$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
        "force" : 350,
        "dodge": -10,
        "damage": 60,
        "damage_type": "����",
        "lvl" : 50,
        "skill_name" : "���·ת",
]),
([      "action": "$N����$w����һ����һʽ��ӥ��Ⱥ�ء���$w��β��ס$n��·��һ��$w������$n������",
        "force" : 400,
        "dodge": -5,
        "damage": 70,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 80,
        "skill_name" : "ӥ��Ⱥ·",
]),
([      "action": "$N����һ�ݣ�Ծ�ڰ�գ�$w�߾ٹ��������һ����ʹһ�С���ɽѩ����������$w�ó���ʮ����Ӱ����$n����Ҫ��������ס",
        "force" : 450,
        "dodge": -15,
        "damage": 80,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "����",
        "lvl" : 100,
        "skill_name" : "��ɽѩ��",
]),
});


int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
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
        level   = (int) me->query_skill("tianshan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if (me->query_str() < 20)
                return notify_fail("��ı�����������ɽ�ȷ���\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ�����������ɽ�ȷ���\n");
        me->receive_damage("jingli", 20);
        if(me->query_skill("tianshan-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("tianshan-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
        return 1;
}

string perform_action_file(string action)
{
                  return __DIR__"tianshan-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
        string msg;
        int ap, dp, skill;
        string result;
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon")))
                return 0;
        
        skill=me->query_skill("tianshan-zhang",1);
        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("staff");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("parry");
        ap = (ap + random(ap*2))/2;
        
        if(me->query_temp("pifeng") && me->query("tianshan")) {
	        if ( random(ap+dp) > ap ) {
        	        result = HIW "\n$Nһ��ŭ�ȣ�����"+(string)weapon->query("name")+HIW"��ط������������Ը��ӵ����������ѱ档\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*4-skill);
        	        victim->start_busy(random(2));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(ap+dp) > ap ) {
                	result = HIB "\n$N�����ĵ�����"+(string)weapon->query("name")+HIB"��$nһ������$n�ƿ����ɣ��ȷ�ҲͻȻ���ù���Ī�⡣\n" NOR;
                	message_vision(result,me,victim);
	       	        victim->add("qi", -weapon->query("weapon_prop/damage")*5-skill*3/2);
        	        victim->start_busy(1+random(2));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(ap+2*dp) > ap ) {
                	result = YEL "\n$N������"+(string)weapon->query("name")+YEL"��$n����ɨȥ����$n����֮�ʣ��͵ط���һ����\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*6-skill*2);
        	        victim->start_busy(1+random(3));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else
        	{
                	result = HIR "\n$N��Ȼ�ȷ�һ�䣬�������ᣬ��������ù���Ī�⣬���²�����\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*3-skill*2);
        	        victim->start_busy(random(2));
	                damage = 0;
        
                	return ([ "result" : result, "damage" : damage ]);
        	}
     	}
}