// Code of ShenZhou
// qfy July 4, 1996.

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if( me->query("family/family_name") != "��ң��")
                return notify_fail("�㲻��ѧС���๦��\n");

	if ( (int)me->query_skill("force", 1)  <  10 )
		return notify_fail("��Ļ����ڹ���򻹲������޷���������������\n");

	if ( me->query("gender") == "����" && (int)me->query_skill("xiaowuxiang",1) > 49)
		return notify_fail("�����޸����ԣ�С���๦���Ѹ���һ��¥��\n");

	if ( (int)me->query_skill("xiaowuxiang", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
		return notify_fail("���ܸ����а���ڹ�ǣ��С���๦���Ѹ���һ��¥��\n");

	if ( (int)me->query_skill("xiaowuxiang", 1) >= 110 
	&& (int)me->query_skill("huagong-dafa", 1) >= 1 
	&& (int)me->query_int() < 40 )
		return notify_fail("����а���ڹ���С���๦���Ѹ���һ��¥��\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("С���๦ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
}
