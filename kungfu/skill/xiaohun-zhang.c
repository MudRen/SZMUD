//戚然销魂掌
//xiaohun-zhang.c
//Scatter
//V. 2.1
//11/17/01
/*
  更改项目
	-杀伤力所相对的等级升高
	-命中率保持

*/


#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N好像心事重重，一招"+HIB"「庸人自扰」"+NOR"对$n不理不采的拍出一掌",
        "force" : 50,
        "dodge" : 5,
        "parry" : 20,
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "庸人自扰",
        "damage_type" : "瘀伤"
]),


([      "action" : "$N抬头向天，浑若不见,呼的一式"+HIB"「杞人忧天」"+NOR"向$n头顶空空拍出，手掌斜下，掌力化成弧形，四散落下",
        "force" : 80,
        "dodge" : 5,
        "parry" : 20,
        "damage": 10,
        "lvl" : 15,
        "skill_name" : "杞人忧天",
        "damage_type" : "瘀伤"
]),

([      "action" : "只见$N飞身到$n身旁，一招"+HIB"「孤形只影」"+NOR"，左掌平出闪过一道光影，直奔$n",
        "force" : 97,
        "dodge" : 15,
        "parry" : 20,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "孤形只影",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N用一招"+HIB"「空谷徘徊」"+NOR"施展轻功在$n周围徘徊，不时向$n拍出一掌",
        "force" : 114,
        "dodge" : 15,
        "parry" : 20,
        "damage": 10,
        "lvl" : 45,
        "skill_name" : "空谷徘徊",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N突然站在原地不动，待$n出招未到时，突然左掌斜斜送出，直奔$n的各大要穴，正是一招"+HIB"「呆若木鸡」"+NOR,
        "force" : 136,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 60,
        "skill_name" : "呆若木鸡",
        "damage_type" : "瘀伤"
]),

([      "action" : "$n向$N攻出数招，只见$N一招"+HIB"「想入非非」"+NOR"，双掌交替向$n迎去，速度之快让人不知所措",
        "force" : 160,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 75,
        "skill_name" : "想入非非",
        "damage_type" : "瘀伤"
]),

([      "action" : "只见$N一式"+HIB"「饮恨吞声」"+NOR"将左掌立于胸前，如同自保，同时右掌推出，左掌紧随其后向$n推出",
        "force" : 183,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 90,
        "skill_name" : "饮恨吞声",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N神情恍惚，心神不宁，一招"+HIB"「六神不安」"+NOR"让$n放松了对$N防范反向$N进攻，突然$N左掌向$n迎面而来",
        "force" : 200,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 105,
        "skill_name" : "六神不安",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N绝无半点防御姿式，待得$n攻到近肉寸许，突然间手足齐动，左掌右袖，双足头锤，连得胸背腰腹尽皆有招式发出，一招"+HIB"「无中生有」"+NOR"尽向$n攻去",
        "force" : 202,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 120,
        "skill_name" : "无中生有",
        "damage_type" : "瘀伤"
]),

([      "action" : "只见$N面带苦色，一式"+HIB"「若有所失」"+NOR"右掌自上而下劈向$n头顶",
        "force" : 204,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 135,
        "skill_name" : "若有所失",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N右手飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，一招"+HIB"「拖泥带水」"+NOR"向$n打去",
        "force" : 206,
        "dodge" : 35,
        "parry" : 20,
        "damage": 10,
        "lvl" : 160,
        "skill_name" : "拖泥带水",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N突然头下脚上，倒过身子，使出"+HIB"「倒行逆施」"+NOR"向$n拍出一掌",
        "force" : 208,
        "dodge" : 35,
        "parry" : 20,
        "damage": 10,
        "lvl" : 190,
        "skill_name" : "倒行逆施",
        "damage_type" : "瘀伤"
]),


([      "action" : "$n向$N欺身而近，刚要触到$N身上，突觉$N的小腹肌肉颤动，同时胸口向内一吸，倏地弹出，正是出其不意的"+HIB"「心惊肉跳」"+NOR,
        "force" : 210,
        "dodge" : 35,
        "parry" : 20,
        "damage": 10,
        "lvl" : 240,
        "skill_name" : "行尸走肉",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N突然之间脸上喜怒哀乐，怪状百出,这招"+HIB"「面无人色」"+NOR"让人一见，登时心神难以自制",
        "force" : 270,
        "dodge" : 45,
        "parry" : 20,
        "damage": 10,
        "lvl" : 300,
        "skill_name" : "面无人色",
        "damage_type" : "瘀伤"
]),

([      "action" : "$N面色惨白，一招"+HIB"「魂不守舍」"+NOR"不自主地左右手交错着向$n推出数掌",
        "force" : 320,
        "dodge" : 45,
        "parry" : 20,
        "damage": 10,
        "lvl" : 350,
        "skill_name" : "魂不守舍",
        "damage_type" : "瘀伤"
]),

([      "action" : "$n渐渐逼近，$N只感到一股压力，随手推出一掌，正是绝处逢生的"+HIB"「穷途末路」"+NOR,
        "force" : 350,
        "dodge" : 50,
        "parry" : 20,
        "damage": 10,
        "lvl" : 400,
        "skill_name" : "穷途末路",
        "damage_type" : "瘀伤"
])


});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="meinu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("戚然销魂掌必须空手。\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("你玉女心经的了解不够, 无法学戚然销魂掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练戚然销魂掌。\n");
    if (me->query("gender") != "男性")
        return notify_fail("只有男弟子才可以学。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/*
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xiaohun-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
*/

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练戚然销魂掌。\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("xiaohun-zhang", 1) >= 30 )
                return __DIR__"xiaohun-zhang/" + action;
}
mapping query_action(object me, object weapon) 
{
           int i, level; 
           object target; 
           string jmsg;
           level = (int)me->query_skill("xiaohun-zhang", 1); 
           switch(me->query_temp("perform/jingtao"))
           {
               case 1:jmsg = "$N面色惨白，一招「魂不守舍」不自主地左右手交错着向$n推出数掌"NOR;break;
                 case 2:jmsg = "$N突然头下脚上，倒过身子，使出「倒行逆施」向$n拍出一掌"NOR;break;
                 case 3:jmsg = "只见$N面带苦色，一式「若有所失」右掌自上而下劈向$n头顶"NOR;break;
           }
           target = me->select_opponent(); 
           if( me->query_temp("perform/jingtao") && target ) 
           {
return (["action":jmsg, 
           "dodge": -20,
           "parry": 25,
           "force": 650,
           "damage": 120,
           "damage_type": "瘀伤"]);
           }
                   else {
           for(i = sizeof(action); i > 0; i--) 
                   if(level > action[i-1]["lvl"]) 
                           return action[NewRandom(i, 20, level/5)]; 
            }
}
