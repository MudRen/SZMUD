// youming-guizhao.c 幽冥鬼爪
// Modified by Xuanyuan 12/2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([     "action" : "$N左爪前伸，带着丝丝蓝阴鬼气，一式「元神出窍」，猛得向$n的顶门插下",
       "force" : 150,
       "dodge" : 5,
       "lvl" : 0,
       "weapon" : "五根手指",
       "damage_type" : "抓伤"
]),
([     "action" : "$N双掌连拍，筑起一道气墙推向$n，忽然一爪「鬼魅穿心」冲破气墙直插$n的$l",
       "force" : 180,
       "dodge" : 200,
       "lvl" : 20,
       "weapon" : "五根手指",
       "damage_type" : "刺伤"
]),
([     "action" : "$N使出「血鬼锁」双爪游向$n扣住$l，气劲激发往左右两下一拉，便要将$n割成碎片",
       "force" : 250,
       "dodge" : 200,
       "lvl" : 40,
       "weapon" : "五根手指",
       "damage_type" : "抓伤"
]),
([     "action" : "$N双爪拢住$n，使一式「炼狱鬼嚎」，阴毒内功随爪尖透入$n体内，直袭各大关节",
       "force" : 300,
       "dodge" : 250,
       "lvl" : 50,
       "damage_type" : "抓伤"
]),
([     "action" : "$N力透指尖，向$n虚虚实实连抓十五爪，「妖风袭体」带动无数阴气缠住$n",
       "force" : 400,
       "dodge" : 250,
       "weapon" : "五根手指",
       "lvl" : 60,
       "damage_type" : "抓伤"
]),
([     "action" : "$N一式「索命妖手」，左爪上下翻动形成无数爪影，右臂一伸，鬼魅般抓向$n的$l",
       "force" : 450,
       "dodge" : 350,
       "weapon" : "五根手指",
       "lvl" : 80,
       "damage_type" : "抓伤"
]),
([     "action" : "$N探手上前，顺着$n的手臂攀缘直上，变手为爪，一招「孤魂驭魔」抓向$n的$l",
       "force" : 550,
       "dodge" : 400,
       "lvl" : 100,
       "weapon" : "五根手指",
       "damage_type" : "抓伤"
]),
([     "action" : "$N凌空飞落，一爪突前，「魔爪天下」积聚全身功力于指尖，快绝无比地插向$n",
       "force" : 600,
       "dodge" : 400,
       "lvl" : 120,
       "weapon" : "五根手指",
       "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练爪功必须空手。\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("你的基本爪功火候不够，无法学习。\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力太弱，无法练幽冥鬼爪。\n");
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
                return notify_fail("你的幽冥鬼爪修为不够，只能用学(learn)的来增加熟练度。\n");
		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
				return notify_fail("练幽冥鬼爪必须空手。\n");
		if ((int)me->query("jingli") < 40)
				return notify_fail("你的体力太低了。\n");
		if ((int)me->query("neili") < 20)
				return notify_fail("你的内力不够练幽冥鬼爪。\n");
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
        me->set_temp("apply/name", ({ me->query("name")+"的鬼影" }));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);       
        me->delete_temp("apply/name");
        me->delete_temp("youming_hit");
        }
}

