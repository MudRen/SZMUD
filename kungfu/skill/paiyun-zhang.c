// Code Of ShenZhou
// Yo
// 排云掌 Paiyun-zhang
// Keny's Skills

#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({
"$n身形扭曲，有于魅影，翻身躲过了$N的这一击。\n",
"$n手臂回转，施出一式「云中魅影」，顺势闪到一旁。\n",
"$n身子扭屈，一招「云中魅影」，把所有$N的功击也避过了，就如一夥影子躲穿于$N身旁一样。\n",
"$n如魅影一般，左扭，右旋，一式「云中魅影」，避过了$N的无数攻击。 \n",
"$n身形飘忽，有如魅影一式「云中魅影」，转了几转，躲过了$N这一招。\n",
"$n运掌，如魅影般，施出「云中魅影」躲过了$N的攻击。\n",
});

string *parry_msg = ({
        "$p身子扭屈，一招"+HIC"「云中魅影」"+NOR"，把所有$n的功击也避过了，就如一夥影子躲穿于$N身旁一样。\n",
        "$p有如鬼影，左扭，右旋，一式"+HIC"「云中魅影」"+NOR"，避过了$N的无数攻击。 \n",
"$p冲前大叫起来，一招"+RED"「虚云劲」"+NOR"当前击去，这一掌好比千千万万的狂气一涌而上，向$n打去，正好和$N的攻击双击而平。 \n",
});

string  *msg = ({
"$N云起掌劲，无匹、无敌、无止、连出三掌，掌掌击于$n的要害。",
"$N身形一变，如魅影般转到$n身前，相距不过一尺，双掌已经打到$n的$l",
"但见黑影闪处，$N双掌击向$n的$l，势如雷霆，避不可避",
"$N跳跃半空，映如弯月，掌间运以内劲重重的击向$n，$n若中了此掌必苦苦叫喊",
});

mapping *action = ({
([      "action": "$N使出「流水行云」，掌势如水云一样，一气呵成，每一掌也连接得天依无逢的逼向$n，$n也难以招架",
        "dodge": 20,
        "parry": 50,
        "force": 480,
        "damage": 100,
        "lvl": 0,
        "skill_name": "流水行云",
        "damage_type": "瘀伤",
]),
([      "action": "$N跳跃半空，映如弯月，落地间一式「披云戴月」，掌间运以内劲重重的击向$n，$n若中了此掌必苦苦叫喊",
        "dodge": 15,
        "parry": 25,
        "force": 400,
        "damage": 130,
        "lvl": 10,
        "skill_name": "披云戴月",
        "damage_type": "瘀伤"
]),
([      "action": "$N暗内运功，双掌合已，掌使「翻云复雨」，双掌突然幻化无数掌击向$n，好比天雨密细，$n讯间难以挡架",
        "dodge": 20,
        "parry": 20,
        "force": 330,
        "damage": 135,
        "lvl": 15,
        "skill_name": "翻云复雨",
        "damage_type": "瘀伤"		
]),
([      "action": "$N凌跃于空、两掌提力，便是排云掌中的「排山倒海」，掌风好如翻海势，分于两边打向$n，$n不禁打了个抖",
        "dodge": 15,
        "parry": 25,
        "force": 600,
        "damage": 110,
        "lvl": 20,
        "skill_name": "排山倒海",
        "damage_type": "瘀伤"
]),
([      "action": "$N掌使一招「乌云蔽日」.此式普出,招如其名，天间好象铸成了一片乌云，$N以惊人速度闪至$n面前，重重的击出五六掌，使$n大吃一惊",
        "dodge": 15,
        "parry": 25,
        "force": 450,
        "damage": 160,
        "lvl": 25,
        "skill_name": "乌云蔽日",
        "damage_type": random(2)?"擦伤":"瘀伤"
]),
([      "action": "$N一式「从云心锁」，旋力发于双掌，力道横行已将$n的攻击化为零，讯间再连起了四、五掌击于$n$l",
        "dodge": 20,
        "parry": 20,
        "force": 380,
        "damage": 145,
        "lvl": 30,
        "skill_name": "从云心锁",
        "damage_type": "瘀伤",
]),
([      "action": "$N驻重心于下左脚搭前，双掌伸合向前，一式「撕天排云」，内力于双掌中股动整装待发，$N如剥开云暮，双掌以万马之力攻向$n",
        "dodge": 15,
        "parry": 25,
        "force": 400,
        "damage": 150,
        "lvl": 35,
        "skill_name": "撕天排云",
        "damage_type": "瘀伤"
]),
([      "action": "$N一招「云海波涛」，掌势好如海浪无常，一时高，一时底，一掌左，一掌右不断的击向$n$l，$n难以分辨如何招架好",
        "dodge": 25,
        "parry": 15,
        "force": 420,
        "damage": 155,
        "lvl": 40,
        "skill_name": "云海波涛",
        "damage_type": "瘀伤"
]),
([      "action": "$N利用内力把左掌慢慢焰起，火到红时便是一式「焚云无定」，$N以千军力重重的击向$n$l，逍有移神就会被击中",
        "dodge": 30,
        "parry": 10,
        "force": 450,
        "damage": 160,
        "lvl": 45,
        "skill_name": "焚云无定",
        "damage_type": "瘀伤"
]),
([      "action": "$N眨一下眼就不见了人，$n突然间发现$N从头顶出现，并以一式「殃云天降」，重重压下，顿时无法躲避",
        "dodge": 20,
        "parry": 20,
        "force": 470,
        "damage": 160,
        "lvl": 50,
        "skill_name": "殃云天降",
        "damage_type": "瘀伤"
]),
([ "action":"$N运功股动内力造成了一个股霞气丛丛的包围了$n，$n突间感到全神被硬掌击中，原来$N已使出了排云掌中的奇招「云莱仙境」",
        "dodge": 30,
        "parry": 10,
        "force": 500,
        "damage": 170,
        "lvl": 55,
        "skill_name": "云莱仙境",
        "damage_type": "瘀伤"
]),
([      "action": "$N以一招「愁云惨淡」，把双掌不断护旋，形成了一个巨大气流冲向$n，此气流好比一、两倍的$n大",
        "dodge": 15,
        "parry": 25,
        "force": 520,
        "damage": 175,
        "lvl": 60,
        "skill_name": "愁云惨淡",
        "damage_type": "内伤",
])
});

int valid_enable(string usage) 
{ 
    return usage == "strike" || usage == "dodge" || usage == "parry"; 
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
        int i, level, neili, force,damage;


        level   = (int) me->query_skill("paiyun-zhang",1);
        force = me->query_skill("force");
                damage= (random(force)+force)/2;
                if(damage>300) damage=300;

        neili = me->query("neili");
        if (level > 120 && force > 180 && neili > 500 
            && me->query("max_neili") > 1200
            && (random(me->query_int()) > 25
                        || random(me->query_dex()) > 27)){
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 150+random(neili/100),
                   "dodge" : 40+random(neili/100),
                   "damage": damage,
                   "damage_type" : "内伤",
                   ]);
            }
           for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_parry_msg(object weapon, object victim) 
{ 
        if ( victim->query_temp("weapon") || victim->query_skill("paiyun-zhang", 1) < 100
        || victim->query_skill_prepared("strike") != "paiyun-zhang" )
                return SKILL_D("parry")->query_parry_msg(weapon);
        else
                return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练排运掌。\n");
        me->receive_damage("jingli", 60);
        me->add("neili", -40);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"paiyun-zhang/" + action;
}
