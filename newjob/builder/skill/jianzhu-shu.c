// ����ѧ
// jianzhu-shu.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("jianzhu-shu", 1);
	
	if( (int)me->query_skill("caishi-shu") < 20 )
		return notify_fail("��Ļ���������ʵ������ѧϰ��һ���Ľ������ܡ�\n");
		
	if( (int)me->query_skill("kanfa-shu") < 20 )
		return notify_fail("��Ļ���������ʵ������ѧϰ��һ���Ľ������ܡ�\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("����ѧֻ�ܿ�ѧϰ����ߡ�\n");
}
