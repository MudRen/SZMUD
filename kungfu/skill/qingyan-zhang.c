// qingyan-zhang.c 五罗轻烟掌
// snowyu 2002/3
#include <ansi.h>
inherit SKILL;

mapping *action =
({
        ([
                "action" : "$N双掌变幻吞吐，一式「轻烟袅袅」拍向$n的$l",
                "force" : 90,
                "dodge" : 5,
                "parry" : 20,
                "damage": 10,
                "lvl" : 0,
                "skill_name" : "轻烟袅袅",
                "damage_type" : "瘀伤"
        ]),
        ([
                "action" : "$N身形微侧，右掌一式「烟雾缭绕」行云流水般向后斜斜拍出",
                "force" : 140,
                "dodge" : 10,
                "parry" : 15,
                "damage": 20,
                "lvl" : 10,
                "skill_name" : "烟雾缭绕",
                "damage_type" : "瘀伤"
        ]),
        ([
                "action" : "$N双掌来回盘旋，将$n的$l笼罩在掌风之下，一式「烟海云涛」向$n击去",
                "force" : 180,
                "dodge" : 15,
                "parry" : 20,
                "damage": 30,
                "lvl" : 20,
                "skill_name" : "烟海云涛",
                "damage_type" : "瘀伤"
        ]),
        ([
                "action" : "$N一式「云烟渺渺」，脸色一片苍白，双掌幻成漫天飞雪，雨点般向$n拍下",
                "force" : 210,
                "dodge" : 15,
                "parry" : 25,
                "damage": 35,
                "lvl" : 30,
                "skill_name" : "云烟渺渺",
                "damage_type" : "瘀伤"
        ]),
        ([
                "action" : "$N身形晃动，幻成数条幻影围绕着$n游走，忽的拍出一掌旋即闪开，好一式「烟雾弥漫」",
                "force" : 260,
                "dodge" : 15,
                "parry" : 25,
                "damage": 50,
                "lvl" : 40,
                "skill_name" : "烟雾弥漫",
                "damage_type" : "瘀伤"
        ]),
        ([
                "action" : "$N双掌一并，一式「烟消云散」合身冲进$n的怀里，意途拼个你死我活",
                "force" : 420,
                "dodge" : 40,
                "parry" : 30,
                "damage": 60,
                "lvl" : 50,
                "skill_name" : "烟消云散",
                "damage_type" : "瘀伤"
        ])
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yiyang-zhi" || combo=="jinyu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练五罗轻烟掌必需空手。\n");
        if ((int)me->query_skill("kurong-changong", 1) < 20
                && (int)me->query_skill("beiming-shengong", 1) < 20)
                return notify_fail("你的枯荣禅功火候不够，无法学五罗轻烟掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练五罗轻烟掌。\n");
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
        int i, j, pm, level;
       	object target;
	string *msg;

	level   = (int) me->query_skill("qingyan-zhang",1);
	pm = me->query_temp("piaomiao");
	target = me->select_opponent();
	weapon = me->query_temp("weapon");

	msg = ({ 
		HIM"\n$N脸色泛红，出招速突增快，一招快似一招。\n"NOR,
                HIW"\n$N左手掌散出的白烟突然转"NOR GRN"青"NOR HIW"，左手劲力也转化成另一种，两股内劲交错连击，威力渐增。\n"NOR,
                HIR"\n$N脸色渐渐转为暗红，身体四周由两股内劲所激发出的烟雾包围，双掌在烟雾中穿梭，所进招式也越增越多！\n"NOR,
                HBWHT BLK"\n只见$N脸上肌肉突然萎缩，形如枯木，身形灵动，出招速突陡然增快！\n"NOR,
	});

	if( pm > 1 && pm < 6 && !me->query_temp("piaomiao_attack")) {

		message_vision( msg[pm-2] , me, weapon);
		me->set_temp("piaomiao_attack", 1);
		for( j=0; j < pm-1; j++ )
		{
			me->add("neili", -50);
			COMBAT_D->do_attack(me, target, weapon);
		}
		me->delete_temp("piaomiao_attack", 1);
		me->add_temp("piaomiao", 1);

	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练五罗轻烟掌。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"qingyan-zhang/" + action;
}
