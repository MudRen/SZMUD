// Code of ShenZhou
// necromancy.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spell"; }

int valid_learn(object me)
{
if( (int)me->query_skill("medicine") < (int)me->query_skill("cursing")*2/3 )
return notify_fail("��Ļ���ҽ����Ϊ�������޷����������Ľ�ͷ����\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return __DIR__"cursing/" + spell;
}


int practice_skill(object me)
{	
return notify_fail("��ͷ��ֻ��ͨ����������ߡ�\n");
}

int learn_skill(object me)
{
return notify_fail("��ͷ��ֻ��ͨ����������ߡ�\n");
}

