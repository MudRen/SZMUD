// hengshan-jian.c 恒山剑法
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N提起$w，划了个半圈，斜斜向$n$l刺去",
    "force" : 120,
    "dodge" : 40,
    "damage" : 30,
        "lvl" : 0,
    "damage_type" : "刺伤",
]),
([  "action" : "$N突然间将$w交左手，反手刺出",
    "force" : 140,
    "dodge" : 35,
    "damage" : 35,
        "lvl" : 3,
    "damage_type" : "刺伤",
]),
([     "action" : "$N突然夸步向前，一招「十步杀一人」，手中$w向$n的$l劈出",
       "force" : 120,
       "dodge" : 20,
       "damage" : 55,
        "lvl" : 5,
        "damage_type":  "割伤"
]),
([     "action" : "$N身子往下一矮身，同时一挥手中$w，一招「脱剑膝前横」，向$n的$l横劈而出",
       "force" : 120,
       "dodge" : 20,
       "damage" : 55,
        "lvl" : 9,
        "damage_type":  "割伤"
]),
([      "action" : "$N剑招忽变，歪歪斜斜地使出一式「雨打飞花」，剑路全走斜势，飘逸无伦，偶尔又夹著一招正式，令$n极难捉摸",
        "force" : 140,
        "dodge" : -10,
        "damage" : 115,
        "lvl" : 20,
        "skill_name" : "雨打飞花",
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑刃平刺而出，锋朝左右，一招「大漠平沙」，$w上剑光渺茫莫测，辽阔无边地刺向$n的$l",
        "force" : 160,
        "dodge" : -5,
        "damage" : 111,
        "lvl" : 40,
        "skill_name" : "大漠平沙",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一振$w，一式「金针渡劫」，出招迅捷无伦，$w陡发嗤嗤声响，剑尖离$n$l已不及半尺",
        "force" : 220,
        "dodge" : 5,
        "damage" : 125,
        "lvl" : 60,
        "skill_name" : "金针渡劫",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w急转，使出一招「神驼骏足」，气度沉稳，直削$n$l，剑势如渊停岳峙，看似古拙，实则蕴藏无穷奥妙",
        "force" : 280,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 80,
        "skill_name" : "神驼骏足",
        "damage_type" : "割伤"
]),
([      "action" : "$N横剑当腹，摆一招「雪拥蓝桥」势，陡然带起一团冷森森的剑光，将$n周身环环裹住",
        "force" : 340,
        "dodge" : 15,
        "damage" : 135,
        "lvl" : 100,
        "skill_name" : "雪拥蓝桥",
        "damage_type" : "割伤"
]) ,
([      "action" : "$N剑尖斜指向地，使一招「木叶萧萧」，手腕一抖，剑光暴长，但听飒飒声响，转瞬间已连攻$n身上七八处要害",
        "force" : 380,
        "dodge" : 20,
        "damage" : 250,
        "lvl" : 120,
        "skill_name" : "木叶萧萧",
        "damage_type" : "刺伤"
]) ,
([      "action" : "$N斜出一剑，一招「峭壁断云」，剑势出奇险峻，精妙难言，$w迳削$n的$l，於凌厉剑势之中，暗伏极繁复的後著变化",
        "force" : 450,
        "dodge" : 20,
        "damage" : 270,
        "lvl" : 100,
        "skill_name" : "峭壁断云",
        "damage_type" : "割伤"
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail(HIC"你的内力不够。\n"NOR);
    return 1;
}


int practice_skill(object me)
{
        if ((int)me->query_skill("hengshan-jian",1) < 199)
           return notify_fail("此项技能只能大于二百级时能学习。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("hengshan-jian",1);
	if(me->query_temp("hengshan") 
	&& random(level) > 160 ){
        me->add("neili", -20);
        return ([
        "action":HIG"$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，巧妙无比，似左实右，已点在$n$l"NOR,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 400,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100 ){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N翻身剑，剑诀斜引，锋芒从半空中直泻下来，向$n的$l斩落"NOR,
        "force" : 480,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 350,
        "damage_type":"刺伤"]);
        }


        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
    return __DIR__"hengshan-jian/" + action;
}

