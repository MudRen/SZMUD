// Code of ShenZhou
// medicine.c ҩ��ѧ

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}


int valid_learn(object me)
{
        if( !me->query_temp("mark/½") )
                return notify_fail("�����ڲ���ѧϰҩ��ѧ��\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("ҩ��ѧ�ÿ�ѧ(learn)����ߡ�\n");
}

/*
string perform_action_file(string action)
{
	return __DIR__"medicine/" + action;
}
*/

