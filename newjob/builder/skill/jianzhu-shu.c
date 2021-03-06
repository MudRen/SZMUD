// 建筑学
// jianzhu-shu.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("jianzhu-shu", 1);
	
	if( (int)me->query_skill("caishi-shu") < 20 )
		return notify_fail("你的基本功不扎实，不能学习高一级的建筑技能。\n");
		
	if( (int)me->query_skill("kanfa-shu") < 20 )
		return notify_fail("你的基本功不扎实，不能学习高一级的建筑技能。\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("建筑学只能靠学习来提高。\n");
}
