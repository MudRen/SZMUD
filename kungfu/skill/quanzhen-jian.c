// Code of ShenZhou
// quanzhen-jianfa 全真剑法
// by sdong

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的「分花拂柳」，似左实右，已点在$n$1",
	"force" : 150,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "分花拂柳",
	"damage_type":	"刺伤"
]),
([	"action":"$N使一招「琴心三叠」，身形向上飘起，手中$w虚虚实实幻出三点寒光射向$n$l",
	"force" : 180,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "琴心三叠",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形绕$n一转，猛然一式「罡风扫叶」，将$w舞出满天剑影，挟着劲风向$n扫去",
	"force" : 250,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 60,
	"lvl" : 25,
	"skill_name" : "罡风扫叶",
	"damage_type":	"割伤"
]),
([	"action":"$N仰天长笑，身形飘然而起，在半空中身子一旋，一式「狂歌痛饮」手中$w狂风般地击向$n的$l",
	"force" : 380,
	 "dodge" : 15,
	"parry" : 15,
	"damage": 75,
	"lvl" : 32,
	"skill_name" : "狂歌痛饮",
	"damage_type":	"刺伤"
]),
([	"action":"$N左手捏着剑诀，左足踏开一招“定阳针”向上斜刺，$w锵然跃出倏的化作几点星光射向$n的$l",
	"force" : 220,
	 "dodge" : 8,
	"parry" : 8,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "定阳针",
	"damage_type":	"刺伤"
]),
([	"action":"$N向前迈去一大步，使出「探海屠龙」，手中$w舞成一个光球，迅若奔雷击向$n的$l",
	"force" : 350,
		  "dodge" : 10,
	"parry" : 10,
	"damage": 65,
	"lvl" : 48,
	"skill_name" : "探海屠龙",
	"damage_type":	"刺伤"
]),
([	"action":"$N运力一抖$w，一时「马蹴落花」，$w幻出点点剑花，飘然刺向$n的$l",
	"force" : 310,
		  "dodge" : 15,
	"parry" : 15,
	"damage": 35,
	"lvl" : 56,
	"skill_name" : "马蹴落花",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w一指，纵起丈余，一时「横行漠北」，$w雷霆般射向$n的$l",
	"force" : 310,
		  "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 62,
	"skill_name" : "横行漠北",
	"damage_type":	"刺伤"
]),
([      "action":"$N大喝一声，一招「白虹经天」，$w闪电般划出一道大圆弧劈向$n的$l",
	"force" : 390,
	 "dodge" : 5,
	"parry" : 5,
	 "damage": 65,
	 "lvl" : 70,
	 "skill_name" : "白虹经天",
	 "damage_type":  "割伤"
]),
([      "action":"$N身形向上飘起，突然一转身，头下脚上，双手握$w，一招「絮坠无声」，无声无息地攻向$n的$l",
		  "force" : 410,
		  "dodge" : 8,
		"parry" : 8,
		  "damage": 65,
		  "lvl" : 75,
		  "skill_name" : "絮坠无声",
		  "damage_type":  "刺伤"
]),
([	"action":"$N手中$w一抖，一招「照破万缘」，$w逼出耀眼光芒，奋力击向$n",
	"force" : 400,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 80,
	"skill_name" : "照破万缘",
	"damage_type":	"刺伤"
]),
([	"action":"$N忽然身形高高跃起，使出「浪迹天涯」，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
	"force" : 450,
	 "dodge" : 20,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "浪迹天涯",
	"damage_type":	"刺伤"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo" ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 10
		&& (int)me->query_skill("yunu-xinjing", 1) <20 )
		return notify_fail("你的内功火候太浅。\n");
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
        int i, count, level, used, level2, lvl, damage, level3;
 	string s_action;
	level   = (int) me->query_skill("quanzhen-jian",1);
        level2 = (int) me->query_skill("force",1);
        level3 = (int) me->query_skill("sword",1);
        for(i = sizeof(action); i > 0; i--)
	        if(level > action[i-1]["lvl"]){
	        	lvl = NewRandom(i, 20, level/5);
			if (wizardp(me)) tell_object(me, HIG"\n你用的是全真剑法中的"+action[lvl]["skill_name"]+"伤害力："+action[lvl]["damage"]+"。\n"NOR);
			if ( level > 200 ){
				if ( me->query_temp("sanqing",1) && random ( level3 + level / 2  ) > random ( level2 )){
					damage = ( level3 + level2 )/ (2 + random ( 5 ));
                                       s_action = action[lvl]["action"]+"！"HIY"\n$N这一招「"+action[lvl]["skill_name"]+"」，借助一剑化三清的内劲快速向$n攻出这一招！！！"NOR,
		                        me->add("jingli", -10);
		                        me->add("neili", -20);
					if (wizardp(me)) tell_object(me, HIG"\n不用三清的伤害力："+action[lvl]["damage"]+"   用三清后的伤害力"+(action[lvl]["damage"]+damage)+"    增加了"+damage+"伤害力。\n"NOR);
				}else{
					damage = level3 / (3 + random ( 6 ));
		                	s_action = action[lvl]["action"];
					if (wizardp(me)) tell_object(me, HIG"\n未到二百级的伤害力："+action[lvl]["damage"]+"   二百级后的伤害力"+(action[lvl]["damage"]+damage)+"    增加了"+damage+"伤害力。\n"NOR);
                		}
				return ([
			                "action":s_action,
			                "dodge":action[lvl]["dodge"],
			                "force":action[lvl]["force"],
			                "parry":action[lvl]["parry"],
			                "damage":action[lvl]["damage"] + damage,
			                "damage_type":action[lvl]["damage_type"],
			        ]);
                	}
	        	return action[lvl];
		}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练全真剑法。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
		  return __DIR__"quanzhen-jian/" + action;
}
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
		  string result;

	if(me->query_temp("sanqing",1))
	{
					 damage_bonus *=2;
//					 if( damage < 5 ) damage = 0;

					 result = HIY"$n身上的"NOR+HIR"通灵宝玉"NOR+HIY"忽然放出一道耀眼光芒，$N吓了一跳，手也松了下来。\n"NOR;

					 return ([ "result": result, "damage": damage_bonus+random(damage_bonus) ]);
	}

}
*/
/*
	if(me->query_temp("sanqing",1))
	{
		if(me->query("jing",1)<damage_bonus+20)
		{
			message_vision(HIM "$N连续攻击这么久，觉得颇为劳累，攻击威力大大下降！\n\n" NOR, me);
			::hit_ob(me, victim, damage_bonus, factor);
		}
		else
		{
			if(damage_bonus<10)damage_bonus=10;
			damage_bonus = 25;
			me->receive_damage("jing", 20);
			victim->receive_damage("qi", 20);
			victim->receive_damage("max_qi", 20);
//			victim->receive_damage("qi",damage_bonus,"用精过度死了");
//			victim->receive_damage("max_qi",damage_bonus,"用精过度死了");
//			me->receive_damage("jing",damage_bonus,"用精过度死了");
//			::hit_ob(me, victim, damage_bonus, factor);
			message_vision(HIR "$N一招击中，让$n受伤不轻！\n\n" NOR, me,victim);
			return 1;
		}
	}
	else ::hit_ob(me, victim, damage_bonus, factor);
}
*/
