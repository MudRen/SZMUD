//逍遥仙(Abian)
// liumang-quan.c -流氓拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N在地上爬来爬去，抓住了$n的小腿，使出了一招「拖泥带水」，大力的打向$n的$l",
	"force" : 200,
        "dodge" : 15,
        "parry" : 30,
	"damage": 50,
	"lvl" : 0,
	"skill_name" : "拖泥带水",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N跳到$n的背上，重重的使了「鬼敲后脑」,$n痛的叫了一声，$N又提起拳头去打$n的$l",
	"force" : 300,
        "dodge" : 30,
        "parry" : 30,
	"damage": 100,
	"lvl" : 20,
	"skill_name" : "鬼敲后脑",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N「呸」的吐了一口痰，嘴巴就恶狠狠的往$n的$l使出了「动口不动手」",
	"force" : 500,
        "dodge" : 25,
        "parry" : 30,
	"damage": 200,
	"lvl" : 40,
	"skill_name" : "动口不动手",
        "damage_type" : "咬伤"
]),
([	"action" : "$N紧紧的握住了拳头，打出了「我最摇摆」。拳头朝着$n的$l打去。",
	"force" : 600,
        "dodge" : 100,
        "parry" : 100,
	"damage": 400,
	"lvl" : 60,
	"skill_name" : "我最摇摆",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wrestling"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("当流氓必须空手。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的内功太弱，无法学流氓拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练流氓拳。\n");
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
	level   = (int) me->query_skill("liumang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练流氓拳。\n");

        if( (int)me->query_skill("force", 1) < 5
        &&  (int)me->query_skill("cuff", 1) < 5
        &&  (int)me->query_skill("parry", 1) < 5
        &&  (int)me->query_skill("dodge", 1) < 5 )
                return notify_fail("没有一点功夫底子，要怎麽练流氓拳。\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

