// Code of ShenZhou
// taiji-gong.c ̫����
// xQin 2/00

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( me->query_skill("taiji-gong") < 10 || me->query_skill("taiji-jian") < 50
		|| me->query_skill("taiji-quan") < 50 )
		return notify_fail("�����ڻ�����ѧϰ̫��ϵ�Ĺ���\n");

	return 1;
}
