// Code of ShenZhou
#include <ansi.h>
#include <mudlib.h>


inherit SKILL;
inherit F_DAMAGE;



mapping *action = ({
        ([
                "action":"$N��ɫ��ׯ������һ����������ʳָͻȻ����$n�ؿ�",
                "force" : 350,
                "dodge" : 30,
                "damage" : 50,
                "parry" : 35,
                "weapon": "���ν���",
                "skill_name" :  "�κ�����",  
                "lvl" : 10,
                "damage_type" : "����"
                ]),
                ([
                "action":"$NƮȻ�˺�������ָ�������죬һ������ָ����Ϯ$n�¸�",
                "force" : 400,
                "dodge" : 40, 
                "parry" : 30,   
                "damage" : 80,  
                "weapon": "���ν���",
                "skill_name" :  "�κ��޽�", 
                "lvl" : 50,
                "damage_type" : "����"
                ]),
                ([
                "action":"$N˿����Ϊ$n������˫�ֽ����У�һʽ���κ��޹顱�ѷ�ס��$n��������·",
                "force" : 450,
                "dodge" : 40,
                "parry" : 25,
		"damage": 100,
                "weapon": "���ν���",
                "skill_name" :  "�κ��޹�",
                "lvl" : 80,
                "damage_type" : "����"
                ]),
                ([      
                "action":"$N��ָ����������ָ���������ܡ�$n��ʱ�ϴ������Ǳ����",
                "force" : 500,
                "dodge" : 50,
                "parry" : 50,
		"damage": 130,
                "weapon": "���ν���",
                "skill_name" :  "�κ��޾�",
                "lvl" : 90,
                "damage_type" : "����"
                ]),
                ([
                "action":"$N��Ȼ�仯ָΪ�ƣ����κ����Ρ���ζ��׾�������㱻��$nĪ���䷽�������м�",
                "force" : 550,
                "dodge" : 55, 
		"damage": 170,
                "weapon": "���ν���",
                "skill_name" :  "�κ�����",
                "lvl" : 60,
                "damage_type" : "����"
                ]),
                ([
                "action":"$N����ǰ̽������ʳָ�������£��ѽ��κ�ָ����������",
                "force" : 550,
                "dodge" : 55,
                "parry" : 50,
                "damage" : 200,
                "weapon": "���ν���",
                "skill_name" :  "�κ��޼�",
                "lvl" : 75,
                "damage_type" : "����"
                ]),
                ([      
                "action":"$Nң����ָ��ȴ�ǰ�����Ҳ�ޣ�$n�ؿ�һ�����پ��������",
                "force" : 580, 
                "dodge" : 60,
                "parry" : 50,
                "damage" : 250,
                "weapon": "���ν���",
                "skill_name" :  "�κ���ָ",
                "lvl" : 90,
                "damage_type" : "����"
                ]),
});  

int valid_enable(string usage)
{
        return usage == "finger" || usage == "parry";
}

//int valid_combine(string combo) { return combo=="qinnashou" ; }

int valid_learn(object me)
{         
        int aa,bb;
        aa = (int)me->query_skill("douzhuan-xingyi",1);
        bb = (int)me->query_skill("canhe-zhi",1);
        
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���κ�ָ������֡�\n");
        if ( bb  >= 60 && aa < 140 && 5*aa <= 4*bb )
                return notify_fail("����ڹ��������޷�����������Ĳκ�ָ��\n");
        if ((int)me->query_skill("finger", 1) <50)
                return notify_fail("��Ļ���ָ����򲻹����޷�ѧ�κ�ָ��\n");
        return 1;
}


int practice_skill(object me)
{
                if ((int)me->query("jingli") < 60)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("��������������κ�ָ��\n");
        me->receive_damage("jingli", 20);
        me->add("neili", -10);
        return 1;

}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("canhe-zhi", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}


string perform_action_file(string action)
{
    return __DIR__"canhe-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("canhe-zhi", 1)) > 80 ) {
                victim->apply_condition("hh_damage",
                random(me->query_skill("canhe-zhi", 1)/3) + victim->query_condition("hh_damage"));
        }

        if ( victim->query_temp("jinzhongzhao") ) {
                victim->apply_condition("hh_damage", victim->query_condition("hh_damage")/3);
        }
}