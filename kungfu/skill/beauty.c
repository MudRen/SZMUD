// Code of ShenZhou
// beauty.c פ����

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if (me->query("gender") == "����") 
		return notify_fail("�������ү��Ҳ��ѧ�����������\n");

	return 1;
}

int reduce_age(object me)
{
	int level = me->query_skill("beauty", 1);
	int mud_age = me->query("mud_age");
	int reduce_age;
	if (level > 200) level = 200;
	if (mud_age <= 864000)
		reduce_age = mud_age*level/200/86400;
	else
		reduce_age = (mud_age/1000+1928)*level/20/2592;
	if (reduce_age > 0) return reduce_age;
	return 0;
}

int practice_skill(object me)
{	
	return notify_fail("פ�����ÿ�ѧ(learn)����ߡ�\n");
}
