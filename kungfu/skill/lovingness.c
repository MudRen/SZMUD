// lovingness.c	��������
// by April 2001.11.04

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	return notify_fail("����˭�ܽ��㰮���أ�\n");
}

/*
int practice_skill(object me)
{	
	return notify_fail("���������һ������ϰ���顣\n");
}
*/