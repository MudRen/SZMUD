// Code of ShenZhou
// mahayana.c ������ͷ�

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl, lvl2;
	
	lvl = (int)me->query_skill("mahayana", 1);
	lvl2= (int)me->query_skill("persuading", 1);

	if( (lvl >= 60 && lvl2 <= lvl && lvl2 < 150) || lvl2 <= lvl/2 )
		return notify_fail("��˷�̳����ն�������������������˲��ܼ�����ߴ�����ͷ���Ϊ��\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("������ͷ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
