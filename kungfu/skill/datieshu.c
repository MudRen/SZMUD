// Code by Scatter
// V. 1.0
// datieshu.c 打铁术

inherit SKILL;

string type() { return "knowledge2"; }

void skill_improved(object me)
{

}


int valid_learn(object me)
{
        if( !me->query_temp("tiejiang/enable_1") )
                return notify_fail("你现在不能学习打铁术。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("打铁术要靠学(learn)或实际经验来提高。\n");
}

