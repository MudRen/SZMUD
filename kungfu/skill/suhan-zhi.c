
// 素寒指法
// suhan-zhi.c
// V. 1.2

/*
[70] about 素寒指                             不在爱你(chchong)(Fri Aug 31)
----------------------------------------------------------------------
手挥五弦，红线盗盒，木兰弯弓，班姬赋诗，;嫦娥窃药，柳荫联句，竹帘临池，红拂夜奔。
$N左手虚晃，在$n一呆之际，立即乘隙而入，一招「红线盗盒」向$n手腕的“会宗穴”点去。
$N一招「手挥五弦」右手快似闪电，倏的穿出五指，连点$n的胸前大穴。
$N身形一转，一步跨到$n身后一式「木兰弯弓」，右手食指疾出，指向$n的背后。
$N向左踏出一步，左手轻扬，右手食指挟着轻柔内力疾点$n，招式光明坦荡，正是一式「班姬赋诗」。
$N突然纵身而起，一式「红拂夜奔」连翻三个空心筋斗，白光忽闪，一指点向$n。
$N忽然低头，一式「嫦娥窃药」，左掌虚晃向$n打去，右指却暗中向$n的腰间点去。
$N左手中指划出一个个的圈子，一招「竹帘临池」，顿时裹得$n眼花缭乱，不知所措。
$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式「柳荫联句」，点向$n的后脑。
*/

inherit SKILL;

mapping *action = ({
([      "action" : "$N左手虚晃，在$n一呆之际，立即乘隙而入，一招「红线盗盒」点向$n手腕的“会宗穴”点去",
        "force" : 60,
        "dodge" : -5,
        "lvl" : 0,
        "skill_name" : "红线盗盒",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「手挥五弦」右手快似闪电，倏的穿出五指，连点$n的胸前大穴",
        "force" : 70,
        "dodge" : -5,
        "lvl" : 0,
        "skill_name" : "手挥五弦",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形一转，一步跨到$n身后一式「木兰弯弓」，右手食指疾出，指向$n的背后",
        "force" : 90,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "木兰弯弓",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向左踏出一步，左手轻扬，右手食指挟着轻柔内力疾点$n，招式光明坦荡，正是一式「班姬赋诗」",
        "force" : 120,
        "dodge" : 5,
        "damage": 10,
        "lvl" : 9,
        "skill_name" : "班姬赋诗",
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然纵身而起，一式「红拂夜奔」连翻三个空心筋斗，白光忽闪，一指点向$n",
        "force" : 160,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 18,
        "skill_name" : "红拂夜奔",
        "damage_type" : "刺伤"
]),
([      "action" : "$N忽然一低头，一招「嫦娥窃药」，左掌虚晃向$n脸上打去，右手却暗中向$n的腰间点去",
        "force" : 210,
        "dodge" : 20,
        "damage": 15,
        "lvl" : 27,
        "skill_name" : "嫦娥窃药",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手中指划出一个个的圈子，一招「竹帘临池」，顿时裹得$n眼花缭乱，不知所措",
        "force" : 270,
        "dodge" : 25,
        "damage": 20,
        "lvl" : 36,
        "skill_name" : "竹帘临池",
        "damage_type" : "刺伤"
]),
([      "action" : "$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式「柳荫联句」，点向$n的后脑",
        "force" : 510,
        "dodge" : 50,
        "damage": 10,
        "lvl" : 60,
        "skill_name" : "柳荫联句",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="meinu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("素寒指法必须空手。\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("你的玉女心经火候不够，无法学素寒指法。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练素寒指法。\n");
    if (me->query("gender") != "女性")
        return notify_fail("素寒指法只有女弟子才可以学。\n");
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
        level   = (int) me->query_skill("suhan-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练素寒指法。\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 20 )
                return notify_fail("你的玉女心经修为还不够。\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("suhan-zhi", 1) >= 30 )
                return __DIR__"suhan-zhi/" + action;
}