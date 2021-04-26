// Code of ShenZhou
// dulong-dafa.c �ߵ�  ������
// ywz Nov 11 1996 .

inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
	mapping skills;
	string *sname;

	int lvl = (int)me->query_skill("dulong-dafa", 1);
	int t = 1, i, j;
	int other_force = 0;

	for (j = 1; j < lvl / 10; j++) t *= 2;

	if (!me->query("yijin_wan"))
		return notify_fail("��δ����ʳ�����ı�̥�׾��裬û�и������޷�ѧϰ�����󷨡�\n");

	if (me->query("yijin_wan") < me->query("age") - 13 )
		return notify_fail("��δ��ÿ�갴�ڷ�ʳ�����ı�̥�׾��裬�޷�����ѧϰ�����󷨡�\n");

	if ( (int)me->query_skill("force", 1)  <  10 
	   ||(int)me->query_skill("force", 1)/2 < lvl/3 )
		return notify_fail("��Ļ����ڹ���򻹲������޷���ᶾ���󷨡�\n");

	skills = me->query_skills();
	sname = keys(skills);
	for(i=0; i<sizeof(skills); i++) {
		if( sname[i] != "dulong-dafa" && SKILL_D(sname[i])->valid_enable("force") ) {
			other_force = 1;
			break;
		}
	}

	if ( (int)me->query_skill("dulong-dafa", 1) >= 45
	&& other_force
	&& (int)me->query_int() < 40 )
		return notify_fail("�����Ͼ��б����ڹ����붾������㣣����Ѹ���һ��¥��\n");

	if ( (int)me->query_skill("dulong-dafa", 1) >= 90
	&& other_force
	&& (int)me->query_int() < 50 )
		return notify_fail("���������ڹ����붾����ˮ�����ݣ������󷨺��Ѹ���һ��¥��\n");

	if (lvl > 10 && (int)me->query("shen") > t * 100
	&& ( me->query_skill("taoism", 1) || me->query_skill("buddhism", 1)) )
		return notify_fail("���в�����ѧϰ�����󷨡�\n");

	return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"dulong-dafa/" + func;
}
