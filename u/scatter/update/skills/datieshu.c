// Code by Scatter
// V. 1.0
// datieshu.c ������

inherit SKILL;

string type() { return "knowledge2"; }

void skill_improved(object me)
{

}


int valid_learn(object me)
{
        if( !me->query_temp("tiejiang/enable_1") )
                return notify_fail("�����ڲ���ѧϰ��������\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("������Ҫ��ѧ(learn)��ʵ�ʾ�������ߡ�\n");
}

