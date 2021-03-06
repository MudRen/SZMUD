//Code by Scatter
//V 2.0
//feiyan-gong(飞燕功)

inherit SKILL;

mapping *action = ({
([      "action" : "$n身形一纵，跃在半空，在空中翻了一翻，一招「三燕投林」，飘然落在$N身后。\n",
        "dodge"  : 10,
        "skill_name" : "三燕投林"
]),
([      "action" : "突然$n清啸一声，纵身一跃，腾空飞起丈许，一式「玉女投梭」，尽数避开$N的攻击。\n",
        "dodge"  : 20,
        "skill_name" : "玉女投梭"
]),
([      "action" : "$n一式「绿珠坠楼」，身体贴地滑行，真叫人匪夷所思，眼见$N的攻击已然扑空。\n",
        "dodge"  : 30,
        "skill_name" : "绿珠坠楼"
]),
([      "action" : "只见$n纵身高跃，半空中一折一转，脚下一式「倒踩莲花」将$N的招式尽数躲开。\n",
        "dodge"  : 40,
        "skill_name" : "倒踩莲花"
]),
([      "action" : "$n身形飘然而起，使出一招「分身化影」，长袖飘飘，姿态灵逸，闪过$N凌厉的攻击。\n",
        "dodge"  : 50,
        "skill_name" : "分身化影"
]),
([      "action" : "$n一式「玉蜂聚巢」，陡然间身形拔起，直冲云霄，直如鹰隼，几个回旋已落在数丈之外。\n",
        "dodge"  : 60,
        "skill_name" : "玉蜂聚巢"
]),
([      "action" : "$n一式「玉蜂聚巢」，陡然间身形拔起，直冲云霄，直如鹰隼，几个回旋已落在数丈之外。\n",
        "dodge"  : 70,
        "skill_name" : "玉蜂聚巢"
]),
([      "action" : "$n一式「玉蜂聚巢」，陡然间身形拔起，直冲云霄，直如鹰隼，几个回旋已落在数丈之外。\n",
        "dodge"  : 80,
        "skill_name" : "玉蜂聚巢"
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("feiyan-gong");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
                  return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练飞燕功。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
