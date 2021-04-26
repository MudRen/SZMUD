// Code of ShenZhou
// xiaoao-jianfa.c ��ң����
//��Լ�������������ڣ��������������Ų������ɽˮ��־��ϼ�̣������뻳����ң���졣

#include <combat.h>
#include <ansi.h>

inherit SKILL;
mapping *action = ({
([      "action" : "$N$w����������һʽ����Լ��������$w�����·��ض���������ǣ�ʱ��ʱ�ֵ�Ʈ��$n",
        "force" : 170,
        "dodge" : 15,
        "parry" : 15,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "��Լ����",
        "damage_type" : "����"
]),
([      "action" : "$N������ˮ�����Ƹ��ƣ�����΢��ݳ�һ�С��������ڡ���$w�滮��$n��$l",
        "force" : 210,
        "dodge" : 25,
        "parry" : 15,
        "damage": 30,
        "lvl" : 15,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ������������һ�С�������������������ָ�����⼴���������任�ղ���$n��$l",
        "force" : 270,
        "dodge" : 25,
        "parry" : 20,
        "damage": 55,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "һ�Ľ���֮Ʈ�ݣ�$N��������ȫ����$w��ô󿪴�ͣ���̤�й���һʽ�����Ų����$w���ŷ�����$n��$l��ȥ��",
        "force" : 340,
        "dodge" : 20,
        "parry" : 20,
        "damage": 60,
        "lvl" : 40,
        "skill_name" : "���Ų��",
        "damage_type" : "����"
]),
([      "action" : "$N$w��ӣ�һ�С�����ɽˮ��������㽣�ˣ���������һ��ӿ��$n",
        "force" : 380,
        "dodge" : 20,
        "parry" : 20,
        "damage": 70,
        "lvl" : 55,
        "skill_name" : "����ɽˮ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�־��ϼ�̡�������Ʈ��������$w�ֳ�һƬϼ�⣬��ס$N������һ������$n",
        "force" : 400,
        "dodge" : 30,
        "parry" : 20,
        "damage": 80,
        "lvl" : 65,
        "skill_name" : "־��ϼ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ֽ�����$nһ����$w��һ�С������뻳�������⻮��һ��һС����ԲȦ��£��$n��������",
        "force" : 430,
        "dodge" : 20,
        "parry" : 30,
        "damage": 85,
        "lvl" : 75,
        "skill_name" : "�����뻳",
        "damage_type" : "����"
]),
([      "action" : "$N���и��ݣ�һ�С���ң���졹���ϵݳ���$w��Ϊ��ʮ����â���л��㱣�Ʈ����$n",
        "force" : 450,
        "dodge" : 30,
        "parry" : 30,
        "damage": 95,
        "lvl" : 85,
        "skill_name" : "��ң����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenghuo-xuangong",1) < 20)
                return notify_fail("���ʥ����ڤ�����δ�������޷���ϰ��ң������\n");
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
        level   = (int) me->query_skill("xiaoyao-jianfa",1);
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
                return notify_fail("��ľ�������������ң������\n");
        me->receive_damage("jingli", 30, "����͸֧��������");
        return 1;
}


mixed hit_ob(object me, object victim, int damage)
{
        string msg;
        int ap, dp, zhencost,skill;
        string result;
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon")))
                return 0;
        
        skill=me->query_skill("xiaoyao-jianfa",1);
        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("sword");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("dodge");
        ap = (ap + random(ap*2))/2;
        
        if(me->query_temp("xiaoyao")) {
	        if ( random(ap+dp) > ap ) {
        	        result = HIG "\n$N����Ʈ����������������һ�����������ӵ������һת���Ѿ��۵�$n��ǰ��৵�һ����\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*4-skill*2);
        	        victim->start_busy(1+random(2));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(ap+dp) > ap ) {
                	result = HIG "\n$N����Ʈ�𣬳�Хһ��������"+(string)weapon->query("name")+HIG"�͵ش���$n��\n" NOR;
                	message_vision(result,me,victim);
	       	        victim->add("qi", -weapon->query("weapon_prop/damage")*5-skill*5/2);
        	        victim->start_busy(1+random(3));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(ap+2*dp) > ap ) {
                	result = HIG "\n$N��һ������һ������������$n��Ҫ����ͻȻ�й�ֱ����ֱȡ$n�����š�\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*6-skill*3);
        	        victim->start_busy(1+random(4));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else
        	{
                	result = HIG"\n����"+weapon->name()+HIG"һ���������ѵ�$n��ǰ��$n���ɵ������޴롣\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*3-skill*3/2);
        	        victim->start_busy(1+random(2));
	                damage = 0;
        
                	return ([ "result" : result, "damage" : damage ]);
        	}
     	}
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

        if ((int)victim->query_temp("xiaoyao")!=1) return damage;
        
        dp = (int)victim->query_skill("force",1);

        dp += victim->query_skill("xiaoyao-jianfa",1);
        
        ap = me->query_skill("force",1);
        if (objectp(weapon1))
                ap += me->query_skill("dodge");
        else
                ap *= 2;

        if ( random(ap+dp) > ap ) {
                
                if ( objectp(weapon2) && objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
                                victim->add("neili", -victim->query_skill("force",1)/3*2);
                                damage_bonus=-random(4000);
                                result = HIW"$n����һ�䣬תΪ���ƣ����⻮��һ����ԲȦ��$N����һ�����Ż��˹�����\n"NOR;
                        }
                }
                
                else if(objectp(weapon2) && !objectp(weapon1)){
                        if (damage + damage_bonus > 0)
                        {
                                damage_bonus=-random(4000);
                                result = HIW"$n΢΢һЦ�����������ֱָ$N����$Nֻ�����Ծ����\n"NOR;                      
                                me->add("neili", (-victim->query_skill("force",1)-me->query("jiali"))/3*2);
                        }

                } else{
                        if (damage + damage_bonus > 0)
                        {                 
                                victim->add("neili", -victim->query_skill("force",1)/3*2);
                                damage_bonus=-random(4000);
                                result = HIW"$n����һ�䣬תΪ���ƣ����⻮��һ����ԲȦ��$N����һ�����Ż��˹�����\n"NOR;
                        }                                
                }
        }
        return ([ "result" : result, "damage" : damage_bonus ]);
}






string perform_action_file(string action)
{
        return __DIR__"xiaoyao-jianfa/" + action;
}


