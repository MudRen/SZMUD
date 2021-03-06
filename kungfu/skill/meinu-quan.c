//美女拳法 
//meinu-quan.c
// Code By Scatter
// Chinese By Lisser
// V. 2.0

/*
【美女拳法】

    美女拳法每一招都是摸拟一位古代美女。女子的姿态心神本就变化既多且速，
而历代名女性格各有不凡之处，颦笑之际、愁喜之分，自更难知难度。将千百年来
美女变幻莫测的心情神态化入武术之中，凡夫俗子，如何能解？美女拳法使出来娇
媚婀娜，男子无法修习。

  貂蝉拜月，西子捧心，红玉击鼓，绿珠坠楼，
  文姬归汉，班姬题扇，萍姬针神，燕姬梦兰，
  蛮腰纤纤，紫玉成烟，洛神凌波，古墓幽居。

  特殊攻击法：
    ○天罗地网势
      指令：perform luowang
      条件：美女拳法有效等级120，玉女心经有效等级100。
      特点：双拳舞起天罗地网，敌人短时间内不能躲闪和还击。
*/
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "只见$N使出"+HIM"「貂蝉拜月」"+NOR"，向着天空深深一拜，趁$n不备挥出一拳",
        "force" : 15,
        "dodge" : 30,
        "lvl" : 0,
        "skill_name" : "貂蝉拜月",
        "damage_type" : "内伤"
]),

([      "action" : "$N一招"+HIM"「西子捧心」"+NOR"，双手从胸口处向$n递出",
        "force" : 30,
        "dodge" : 25,
        "lvl" : 20,
        "skill_name" : "西子捧心",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招"+HIM"「红玉击鼓」"+NOR"，双臂交互快击，扫向$n",
        "force" : 50,
        "dodge" : 20,
        "lvl" : 40,
        "skill_name" : "红玉击鼓",
        "damage_type" : "跌伤"
]),
([      "action" : "$N使一招"+HIM"「绿珠坠楼」"+NOR"，扑地攻向$n下盘",
        "force" : 70,
        "dodge" : 15,
        "lvl" : 60,
        "skill_name" : "绿珠坠楼",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双掌连拍数下，使出"+HIM"「文姬归汉」"+NOR"，接着连绵不断的拍出",
        "force" : 100,
        "dodge" : 10,
        "lvl" : 80,
        "skill_name" : "文姬归汉",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手在$n面前展开，好像打开扇子一般，右手向$n连出数拳，这正是一招"+HIM"「班姬题扇」"+NOR,
        "force" : 130,
        "dodge" : 30,
        "lvl" : 100,
        "skill_name" : "班姬题扇",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N伸指戳出，却是一招"+HIM"「萍姬针神」"+NOR"，插向$n面门",
        "force" : 160,
        "dodge" : 25,
        "lvl" : 130,
        "skill_name" : "萍姬针神",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招"+HIM"「燕姬梦兰」"+NOR"，如梦如醒，身子向$n倒去，双手直连数拳",
        "force" : 190,
        "dodge" : 20,
        "lvl" : 160,
        "skill_name" : "燕姬梦兰",
        "damage_type" : "抓伤"
]),
([      "action" : "$N一招"+HIM"「蛮腰纤纤」"+NOR"，腰肢轻摆避开$n的攻击，右掌向$n打去",
        "force" : 200,
        "dodge" : 15,
        "lvl" : 190,
        "skill_name" : "蛮腰纤纤",
        "damage_type" : "瘀伤"
]),
([      "action" : "只见$N飞身贴到$n身旁，左手一招"+HIM"「紫玉成烟」"+NOR"自下而上向$n直击",
        "force" : 210,
        "dodge" : 15,
        "lvl" : 200,
        "skill_name" : "紫玉成烟",
        "damage_type" : "跌伤"
]),
([      "action" : "$N脚下翩若惊鸦、矫若游龙，犹如在水上漂行一般逼近$n，并向$n连出数拳，却是一招"+HIM"「洛神凌波」"+NOR,
        "force" : 215,
        "dodge" : 30,
        "lvl" : 210,
        "skill_name" : "洛神凌波",
        "damage_type" : "抓伤"
]),
([      "action" : "$N使一招"+HIM"「古墓幽居」"+NOR"，右手支颐，左手轻轻挥出，长叹一声，脸现寂寥之意",
        "force" : 220,
        "dodge" : 25,
        "lvl" : 220,
        "skill_name" : "古墓幽居",
        "damage_type" : "内伤"
])


});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="xiaohun-zhang" || combo=="suhan-zhi"; }
int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练习美女拳法必须空手。\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 10)
                return notify_fail("你对玉女心经了解不够, 无法学习美女拳法。\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练美女拳法。");
        return 1;
}


int practice_skill(object me)
{

        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练美女拳法。\n");

        if (me->query_skill("riyue-quan", 1) < 50)
                me->receive_damage("jingli", 20);
        else
                me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

mapping query_action(object me, object weapon) 
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
                return __DIR__"meinu-quan/" + action;
}
