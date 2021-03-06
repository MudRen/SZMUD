
//xuantie-jian (玄铁剑法)
//UPDATE BY SCATTER
//VERSION 1.0 BETA
//2001/08/05
// update by april 2001.12.18

// COLOR DEFINE
// RED - 红色              HIR - 亮红色
// GRN - 绿色              HIG - 亮绿色
// YEL - 土黄色            HIY - 黄色
// BLU - 深蓝色            HIB - 蓝色
// MAG - 浅紫色            HIM - 粉红色
// CYN - 蓝绿色            HIC - 天青色
// WHT - 浅灰色            HIW - 白色

/*
[61] about xuantie-jian 招式改                不在爱你(chchong)(Wed Aug 29)
----------------------------------------------------------------------
玄铁剑更新招式：
顺刺开天，逆击分海，横削断山，反撩揽月，
倒劈惊雷，斜扫寒冰，平抹黄沙，竖挑梅花，


$N剑气凝重，如山峦巍耸，一招「顺刺开天」直刺$n面门！
$N剑招一沉，一式「逆击分海」手中的$w扫向$n腰间，出招之际有一股秉然正气！
只见$N有手$w挺出，剑走龙蛇，白光如虹，一招「横削断山」攻向$n。
$N突然招式凌厉，右手递出$w，青光闪烁一招「反撩揽月」撩向$n脸上！
$N真气布满全身，将$w舞得大开大和，脚踏中宫，一式「倒劈惊雷」，$w带着风声朝$n劈去。
突然$N手中$w方向横转，一招「平抹黄沙」，隐约中代有风沙咆哮的声音扫向$n。
$N手中$w突然斜转绕过$n攻势，一招「斜扫寒冰」招式之快让人匪夷所思，直接劈向$n肩头。
$N一抖手中$w，一招「竖挑梅花」只见剑身上射出点点寒光向$n射去！

因为xuantie-jian 有反扑归真的境界所以在加两句没有招式的描述，用来最后过了120lv 在出
save
$N突然之间招数全无，只是极平常的一刺，却已经意在剑前，朝$n身上刺去，然而招式越是平平威力却是越大！
$N手中$w剑气如风，含劲而无式，举手投足之间隐含极浑厚的内劲削向$n身前，犹如剑法已经反扑归真一般无招自胜！


如果无招的描述不够的话，告诉我，我可以在补几句：）
*/



#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$N剑气凝重，如山峦巍耸，一招「顺刺开天」直刺$n面门",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "顺刺开天",
        "damage_type":  "刺伤"
]),
([      "action":"$N剑招一沉，一式「逆击分海」手中的$w扫向$n腰间，出招之际有一股秉然正气",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 20,
        "skill_name" : "逆击分海",
        "damage_type":  "刺伤"
]),
([      "action":"只见$N右手$w挺出，剑走龙蛇，白光如虹，一招「横削断山」攻向$n",
        "force" : 350,
		"dodge" : 10,
        "parry" : 10,
        "damage": 50,
        "lvl" : 40,
        "skill_name" : "横削断山",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然招式凌厉，右手递出$w，青光闪烁一招「反撩揽月」撩向$n脸上",
        "force" : 280,
    "dodge" : 15,
        "parry" : 15,
        "damage": 60,
        "lvl" : 60,
        "skill_name" : "反撩揽月",
        "damage_type":  "割伤"
]),
([      "action":"$N真气布满全身，将$w舞得大开大和，脚踏中宫，一式「倒劈惊雷」，$w带着风声朝$n劈去",
        "force" : 220,
    "dodge" : 8,
        "parry" : 8,
        "damage": 70,
        "lvl" : 80,
        "skill_name" : "倒劈惊雷",
        "damage_type":  "割伤"
]),
([      "action":"突然$N手中$w方向横转，一招「平抹黄沙」，隐约中带有风沙咆哮的声音扫向$n",
        "force" : 350,
        "dodge" : 10,
        "parry" : 10,
        "damage": 80,
        "lvl" : 100,
        "skill_name" : "平抹黄沙",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w突然斜转绕过$n攻势，一招「斜扫寒冰」招式之快让人匪夷所思，直接劈向$n肩头",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 90,
        "lvl" : 120,
        "skill_name" : "斜扫寒冰",
        "damage_type":  "刺伤"
]),
([      "action":"$N一抖手中$w，一招「竖挑梅花」只见剑身上射出点点寒光向$n射去",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 100,
        "lvl" : 140,
        "skill_name" : "竖挑梅花",
        "damage_type":  "刺伤"
])

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");


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
        level   = (int) me->query_skill("xuantie-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        //**** ADD BY SCATTER (BUG FIX)
        object weapon; 
        if( !objectp(weapon = me->query_temp("weapon")) 
                || (string)weapon->query("skill_type") != "sword" ) 
                return notify_fail("你使用的武器不对。\n"); 
        //**** EOF ADD BY SCATTER (BUG FIX)

        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力不够练玄铁剑法。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了");
        return 1;
}


string perform_action_file(string action)
{
	return __DIR__"xuantie-jian/" + action;
}

