//YUNU-JIANFA (玉女剑法)
//UPDATE BY SCATTER
//VERSION 1.2 BETA
//2001/07/30
// updated by april 2001.12.18

// COLOR DEFINE
// RED - 红色              HIR - 亮红色
// GRN - 绿色              HIG - 亮绿色
// YEL - 土黄色            HIY - 黄色
// BLU - 深蓝色            HIB - 蓝色
// MAG - 浅紫色            HIM - 粉红色
// CYN - 蓝绿色            HIC - 天青色
// WHT - 浅灰色            HIW - 白色

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N一式"+HIY"「花前月下」"+NOR"，自上而下，有如明月横空、星光铺地，手中$w飘飘然刺向$n$l",
	"force" : 120,
	"dodge" : 5,
	"parry" : 5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "花前月下",
	"damage_type":	"刺伤"
]),
([	"action":"$N使出"+HIG"「抚琴按箫」"+NOR"，轻叹一声，双眉微皱，手中$w怀中一抱，$w锵然跃出倏的化作几点星光，飞向$n的$l",
	"force" : 150,
	"dodge" : 5,
	"parry" : 5,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "抚琴按箫",
	"damage_type":	"刺伤"
]),
([	"action":"$N神情悠然，一招"+HIW"「扫雪烹茶」"+NOR"，手中$w从左向右横扫过去，忽然向下连刺$n的$l数剑",
	"force" : 180,
    "dodge" : 10,
	"parry" : 10,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "扫雪烹茶",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式"+MAG"「清饮小酌」"+NOR"，一手虚晃，有如提壶斟酒，另一手持$w却向$n$l接连挥出数剑",
	"force" : 210,
    "dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "清饮小酌",
	"damage_type":	"割伤"
]),
([	"action":"$N娇喝一声，一招"+WHT"「松下对弈」"+NOR"，$w亮出雪光，向$n劈砍下去",
	"force" : 240,
    "dodge" : 8,
	"parry" : 8,
	"damage": 50,
	"lvl" : 40,
	"skill_name" : "松下对弈",
	"damage_type":	"割伤"
]),
([	"action":"$N身子优雅地往前一探，舞动$w，使出"+HIY"「池边调鹤」"+NOR"，连续攻向$n数剑",
	"force" : 270,
	"dodge" : 10,
	"parry" : 10,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "池边调鹤",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式"+HIR"「小园艺菊」"+NOR"，姿势美妙地飞起，手中$w闪动着剑花，若有若无刺向$n的$l",
	"force" : 300,
	"dodge" : 15,
	"parry" : 15,
	"damage": 70,
	"lvl" : 60,
	"skill_name" : "小园艺菊",
	"damage_type":	"刺伤"
]),
([      "action":"$N飘然纵起丈余，一招"+WHT"「西窗夜话」"+NOR"身子贴地斜飞，尚未落地，$w已直刺$n的$l",
	"force" : 330,
    "dodge" : 5,
	"parry" : 5,
    "damage": 80,
    "lvl" : 70,
    "skill_name" : "西窗夜话",
    "damage_type":  "刺伤"
]),
([      "action":"$N峨眉一皱，侧身斜刺一剑，一招"+HIW"「冷月窥人」"+NOR"，$w带着冰冷剑气直刺$n的$l",
	"force" : 360,
	"dodge" : 8,
	"parry" : 8,
	"damage": 90,
	"lvl" : 80,
	"skill_name" : "冷月窥人",
	"damage_type":  "刺伤"
]),
([	"action":"$N身子一旋，忽然一式"+HIC"「云羞有影」"+NOR"，一手含羞遮脸，另一手反手一剑，$w从意想不到的位置刺向$n的$l",
	"force" : 390,
    "dodge" : 10,
	"parry" : 10,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "云羞有影",
	"damage_type":	"刺伤"
]),
([	"action":"$N柳腰轻扭，眉目含情，一式"+HIM"「琴心暗通」"+NOR"，手握$w，飘飘刺向$n的$l",
	"force" : 420,
    "dodge" : 10,
	"parry" : 10,
	"damage": 110,
	"lvl" : 100,
	"skill_name" : "琴心暗通",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形飘然高高跃起，在半空中柳腰一旋，忽然一式"+HIM"「皓腕玉镯」"+NOR"，手握$w，全身如闪电一般刺向$n的$l",
	"force" : 450,
    "dodge" : 20,
	"parry" : 20,
	"damage": 120,
	"lvl" : 110,
	"skill_name" : "皓腕玉镯",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("yunu-xinjing", 1) < 25 )
		return notify_fail("你的玉女心经火候太浅。\n");

	if( (string)me->query("gender") != "女性" )
		return notify_fail("你耍弄了几下，发现这路剑法巧柔纤细，身形婀娜，似乎只适合女子练习。\n");

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
	level = (int) me->query_skill("yunu-jianfa",1);
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
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力不够练玉女剑法。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunu-jianfa/" + action;
}