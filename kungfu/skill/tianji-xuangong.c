// Code of ShenZhou
// tianji-xuangong.c �һ� �������
// Ryu

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, nh;
	nb = (int)me->query_skill("qimen-dunjia", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("tianji-xuangong", 1);

	if ( nb < 120 && nb <= nh )
		return notify_fail("������Ŷݼ���Ϊ�������޷�������������������\n");

	if ( nf < 10 || nf/2 < nh/3 )
		return notify_fail("��Ļ����ڹ���򻹲������޷�������������\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("�������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianji-xuangong/" + func;
}
