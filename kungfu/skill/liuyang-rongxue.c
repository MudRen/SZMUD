// Code of ShenZhou
//liuyang-rongxue.c ������ѩ��

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("liuyang-rongxue", 1);

	if ( me->query("gender") == "����" )
		return notify_fail("������ѩ���ǵ�����������һ�ɴ�����������޸��������ᶮ������֮���\n");

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ����������������������������ѩ����\n");

        if ( me->query("gender") == "Ů��" && lvl > 99)
                return notify_fail("����������������ޣ������������������ѩ����\n");

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������ѩ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

