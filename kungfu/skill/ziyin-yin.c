// Code of ShenZhou
// ziyin-yin.c �����

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("shen") < 0 )
		return notify_fail("���а��̫�أ��޷�������ɽ�������\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("��ɽ�����ֻ�ܿ�ѧϰ����ߡ�\n");
}
