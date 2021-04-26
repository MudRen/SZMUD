// youming-guizhao.c ��ڤ��צ
// Modified by Xuanyuan 12/2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([     "action" : "$N��צǰ�죬����˿˿����������һʽ��Ԫ����ϡ����͵���$n�Ķ��Ų���",
       "force" : 150,
       "dodge" : 5,
       "lvl" : 0,
       "weapon" : "�����ָ",
       "damage_type" : "ץ��"
]),
([     "action" : "$N˫�����ģ�����һ����ǽ����$n����Ȼһצ�����ȴ��ġ�������ǽֱ��$n��$l",
       "force" : 180,
       "dodge" : 200,
       "lvl" : 20,
       "weapon" : "�����ָ",
       "damage_type" : "����"
]),
([     "action" : "$Nʹ����Ѫ������˫צ����$n��ס$l��������������������һ������Ҫ��$n�����Ƭ",
       "force" : 250,
       "dodge" : 200,
       "lvl" : 40,
       "weapon" : "�����ָ",
       "damage_type" : "ץ��"
]),
([     "action" : "$N˫צ£ס$n��ʹһʽ�����������������ڹ���צ��͸��$n���ڣ�ֱϮ����ؽ�",
       "force" : 300,
       "dodge" : 250,
       "lvl" : 50,
       "damage_type" : "ץ��"
]),
([     "action" : "$N��͸ָ�⣬��$n����ʵʵ��ץʮ��צ��������Ϯ�塹��������������ס$n",
       "force" : 400,
       "dodge" : 250,
       "weapon" : "�����ָ",
       "lvl" : 60,
       "damage_type" : "ץ��"
]),
([     "action" : "$Nһʽ���������֡�����צ���·����γ�����צӰ���ұ�һ�죬���Ȱ�ץ��$n��$l",
       "force" : 450,
       "dodge" : 350,
       "weapon" : "�����ָ",
       "lvl" : 80,
       "damage_type" : "ץ��"
]),
([     "action" : "$N̽����ǰ��˳��$n���ֱ���Եֱ�ϣ�����Ϊצ��һ�С��»�Ԧħ��ץ��$n��$l",
       "force" : 550,
       "dodge" : 400,
       "lvl" : 100,
       "weapon" : "�����ָ",
       "damage_type" : "ץ��"
]),
([     "action" : "$N��շ��䣬һצͻǰ����ħצ���¡�����ȫ������ָ�⣬����ޱȵز���$n",
       "force" : 600,
       "dodge" : 400,
       "lvl" : 120,
       "weapon" : "�����ָ",
       "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("��צ��������֡�\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("��Ļ���צ����򲻹����޷�ѧϰ��\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("�������̫�����޷�����ڤ��צ��\n");
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
       level   = (int) me->query_skill("youming-guizhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query_skill("youming-guizhao", 1) < 199 )
                return notify_fail("�����ڤ��צ��Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
				return notify_fail("����ڤ��צ������֡�\n");
		if ((int)me->query("jingli") < 40)
				return notify_fail("�������̫���ˡ�\n");
		if ((int)me->query("neili") < 20)
				return notify_fail("���������������ڤ��צ��\n");
		me->receive_damage("jingli", 30);
		me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youming-guizhao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   if(me->query_temp("lingjiu/youming") && !me->query_temp("youming_hit")) {
        me->set_temp("youming_hit", 1);
        me->set_temp("apply/name", ({ me->query("name")+"�Ĺ�Ӱ" }));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);       
        me->delete_temp("apply/name");
        me->delete_temp("youming_hit");
        }
}

