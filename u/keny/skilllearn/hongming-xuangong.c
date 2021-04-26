// Code of ShenZhou
//hongming-xuangong.c ��ڤ����
// snowbird august 1999
// 1.1.1.1

#include <ansi.h>

inherit FORCE;
#include "/kungfu/skill/force_list.h"

string check() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl; 
	string *sname;
	int i, k=0, nb, nk, lvl = (int)me->query_skill("hongming-xuangong", 1);

	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );

	if (me->query_skill("this_skill") > 99) {
        for(i=0; i<sizeof(skl); i++)
			if (SKILL_D(sname[i])->check() == "force") k++;
		if (k >=2) return notify_fail ("�����ڲ�ͬ���������ײ����������������书��\n");
	}

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	return 1;
}

int practice_skill(object me)
{
	if ( me->query_skill("kurong-changong", 1) < 150 )
		return notify_fail("��ĺ�ڤ������Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
	if ( me->query_temp("weapon") )
		return notify_fail("���к�ڤ����������֡�\n");
	if ( (int)me->query("jing") < 110 )
		return notify_fail("��ľ��񲻺ã��޷���ϰ��ڤ������\n");
	if ( (int)me->query("jing") < 60 )
		return notify_fail("��ľ���������ϰ��ڤ������\n");
	if ( (int)me->query("neili") < 110 )
		return notify_fail("�������������ϰ��ڤ������\n");

	me->add("neili", -100);
	me->receive_damage("jingli", 50, "����͸֧��������");
	me->receive_damage("jing", 100, "����͸֧��������");

        return 1;
}


string exert_function_file(string func)
{
	return __DIR__"hongming-xuangong/" + func;
}
