// Code of ShenZhou
#include <ansi.h>
#include <mudlib.h>


inherit SKILL;
inherit F_DAMAGE;

string *skill_name = ({
        "����",
        "����",
        "�г�",
        "�س�",
        "�ٳ�",
        "����",
});

mapping *action = ({
	([
		"action":"$N����Сָһ�죬һ���������ٳ�Ѩ�м������������$n��$l",
		"force" : 500,
		"dodge" : 500,
//		"damage" : 100,
		"weapon": "���ν���",
		"lvl" : 0,
		"damage_type" : "����"
		]),
		([
		"action":"$N�����󽣡�������ȥ���仯��΢��$n��ɫ��㵼����$lһʹ",
		"force" : 530,
		"dodge" : 500,          
		"weapon": "���ν���",
		"lvl" : 10,
		"damage_type" : "����"
		]),
		([
		"action":"$N��ָһ�������г彣����ʽ��ǰ��������",
		"force" : 550,
		"dodge" : 500,
		"weapon": "���ν���",
        "lvl" : 30,
        "damage_type" : "����"
		]),
		([      
		"action":"$N��ָ���������г彣���󿪴��أ�����������$n��ʱ�ϴ�������ɫ�Ǳ�",
		"force" : 580,
		"dodge" : 600,
		"weapon": "���ν���",
		"lvl" : 45,
		"damage_type" : "����"
		]),
		([
		"action":"$N����Сָһ��һ�࣬�����󽣡���ζ��׾�������ݺᣬ$nĪ���䷽�������м�",
		"force" : 600,
		"dodge" : 600, 
		"weapon": "���ν���",
		"lvl" : 60,
		"damage_type" : "����"
		]),
		([
		"action":"$N����ʳָ��$n��ָ��������Ȼ��Ȼ��ʳָ��ӿ�������ǡ������񽣡��С�����������һ��",
		"force" : 600,
		"dodge" : 600,
		"weapon": "���ν���",
		"parry" : 120,
		"lvl" : 75,
		"damage_type" : "����"
		]),
		([      
		"action":"$N���������ݺ���裬�󿪴��أ����ɺ�ΰ��ÿһ���̳�������ʯ���쾪���������֮��",
		"force" : 600, 
		"dodge" : 600,
		"weapon": "���ν���",
		"lvl" : 150,
		"damage_type" : "����"
		]),
});  

int valid_enable(string usage)
{
        return usage == "finger" || usage == "parry";
}

int valid_learn(object me)
{
        int fi,ff,fl,fy;
        fy = (int)me->query_skill("yiyang-zhi", 1);
        fl = (int)me->query_skill("liumai-shenjian", 1);
        ff = (int)me->query_skill("force", 1);
        fi = (int)me->query_skill("finger", 1);

        if ( fl  >= 20 && fy < 140 && fy <= fl )
                return 
notify_fail("���һ��ָ��򻹲������޷�����������������񽣡�\n");

        if  ( fl >= 160 || fi < 140 )
                return 
notify_fail("��Ļ���ָ����������޷�����������������񽣡�\n");

        if ( ff < 140 || ff/2 < fl/3 )
                return 
notify_fail("��Ļ����ڹ���򻹲������޷�����������������񽣡�\n");

        return 1;
}


int practice_skill(object me)
{
                if ((int)me->query("jingli") < 60)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("������������������񽣡�\n");
        me->receive_damage("jingli", 10);
        me->add("neili", -10);
        return 1;

}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("liumai-shenjian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
        return skill_name[level/30];
}

string perform_action_file(string action)
{
    return __DIR__"liumai-shenjian/" + action;
}

void skill_improved(object me)
{
        int level = me->query_skill("liumai-shenjian",1);
        int lm_lvl = me->query("liumai_lvl");
        int i;

        if ( level/15*15 == level ) {
                tell_object(me, HIG "��ԡ�" + skill_name[level/30-1] + "���ѻ�Ȼ��ͨ��\n"NOR);
                if (lm_lvl < level) {
                        tell_object(me, HIG"��ʱ���һ��ָ������Ҳ�����ߡ�\n"NOR);
                        for (i=0; i< level; i++)                
                                me->improve_skill("yiyang-zhi", level);
                }
        }

        if ( level/30*30 == level ) 
                if (lm_lvl < level) {
                        tell_object(me, HIY"��ʱ��" + skill_name[level/60-1] +"���ڻ��ͨ������ָ����ʹ���ν���������һ���˽⣬ָ����Ϊ��������һ�㡣\n"NOR);
                        me->improve_skill("finger", level*70);
                }

        if ( lm_lvl < level ) me->set("liumai_lvl", level);
                
}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
int damage_bouns;

if (victim->query("combat_exp") > 50) 
{
return "aaaaaaaaaaaa";
}
}
*/
