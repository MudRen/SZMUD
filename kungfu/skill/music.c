// Code of ShenZhou
//music.c ����ʮ����
//����ʮ���ɣ���Ϊ���ӡ�������̫�ء����ӡ���ϴ��������ި�������ӡ��������������䡢Ӧ�ӡ������Թ����У���˵����Ƶ�������Ϊ�ɣ��ŷ��֮������ʮ���ɡ��������ң��߹����̡��ǡ�΢����������һ��Ϊ���ӣ�����Ϊ���������Ϊ���ǡ����̡���������������ި������

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl, lvl2;
	
	lvl = (int)me->query_skill("music", 1);

	if ( lvl > 100 && me->query_int()-15 < lvl/10 )
		return notify_fail("���������ޣ�������������и��ߵ��⾳��\n");

	return 1;
}

int practice_skill(object me)
{       
	return notify_fail("��������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
