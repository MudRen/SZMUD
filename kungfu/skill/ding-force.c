// Code of ShenZhou
// ding-force.c С������

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("С������ֻ�ܸ�С��ѧ�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"ding-force/" + func;
}

