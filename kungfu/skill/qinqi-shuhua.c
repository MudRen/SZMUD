// qinqi-shuhua.c 琴棋书画

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
//          if ( me->query("int") < 24 && me->query_int() < 32)
                if ( me->query_int() < 30)
	 return notify_fail("琴棋书画乃是极其风雅之事，" +RANK_D->query_respect(me)+"似乎太过于俗气了些。\n");
         if ((int)me->query_skill("literate", 1)*2 < (int)me->query_skill("qinqi-shuhua",1))
                return notify_fail("你自觉造诣以到了顶峰，琴棋书画再也没有提高。\n");
	if(me->query("family/master_name") != "何足道" )
	return notify_fail("你一个练武的粗人，学这些酸腐文人的东西干什么？\n");	
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("琴棋书画只能靠学(learn)来提高。\n");
}
