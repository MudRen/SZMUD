// Code of ShenZhou

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl, lvl2;
	
	lvl = (int)me->query_skill("qimen-dunjia", 1);
	lvl2 = (int)me->query_skill("literate", 1);


	if ( lvl > lvl2 && (lvl-lvl2) > 100)
		return notify_fail("���Ŷݼ׶�����˵̫����ˡ�\n");


	if ( lvl > 100 && me->query_int()-15 < lvl/10 )
		return notify_fail("���Ŷݼ׶�����˵̫����ˡ�\n");

	if ( lvl > 100 && me->query("qmdj_use")*10 < lvl-100 )
		return notify_fail("�������Ŷݼ��ϵ�Ӧ�ò��㣬���Լ�����ᡣ\n");
	return 1;
}

int practice_skill(object me)
{       
	return notify_fail("���Ŷݼ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
