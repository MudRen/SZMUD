  // Code by Scatter
// V. 1.0
// tiejiang.c 铁匠知识

inherit SKILL;

string type() { return "knowledge2"; }

void skill_improved(object me)
{

}


int valid_learn(object me)
{
        if( !me->query_temp("tiejiang/enable_1") )
                return notify_fail("你现在不能学习铁匠知识。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("铁匠知识要靠学(learn)或实际经验来提高。\n");
}
