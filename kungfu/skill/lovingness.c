// lovingness.c	象征爱情
// by April 2001.11.04

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	return notify_fail("又有谁能教你爱情呢？\n");
}

/*
int practice_skill(object me)
{	
	return notify_fail("你神经兮兮地一个人练习爱情。\n");
}
*/