// Code of ShenZhou
// shenghuo-xuangong.c	����  ʥ������
// Zhangchi 2/2000

inherit FORCE;

#include <ansi.h>
#include "/kungfu/skill/force_list.h"

string check() 
{
	return "force";
}

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	mapping skill;
	string *skname;
	int i, n = 0;

	skill = this_player()->query_skills();
	skname = sort_array(keys(skill), (: strcmp :) );

	if ((int)me->query_skill("force", 1) < 10 )
		return notify_fail("��Ļ����ڹ�����㣬����ѧʥ��������\n");

	if(me->query_skill("shenghuo-xuangong", 1) > 99)
	{
		for(i=0; i<sizeof(skill); i++) 
		{
			if (SKILL_D(skname[i])->check() == "force")
        	        n++;  
		}
		if ( n >=2 && !me->query_skill("qiankun-danuoyi", 1) ) 	// if learned qkny,
									// can have 2+ forces.
			return notify_fail("�����ڲ�ͬ���������ײ���޷�����ѧϰʥ��������\n");
	}

	return 1;
}

int practice_skill(object me)
{
	int cost;


        if ( me->query_skill("shenghuo-xuangong", 1) < 180 )
                return notify_fail("���ʥ��������Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");

        if ( me->query_temp("weapon") )
                return notify_fail("��ϰʥ������������ֻ����������ɡ�\n");

        if ( (int)me->query("qi") < 100 )
                return notify_fail("�������������ϰʥ��������\n");

        if ( (int)me->query("jingli") < 100 )
                return notify_fail("��ľ���������ϰʥ��������\n");

        if ( (int)me->query("neili") < 100 )
                return notify_fail("�������������ϰʥ��������\n");

	cost = (int)me->query_skill("shenghuo-xuangong", 1)/3;	// cost 60 when qkyq 180, 
								// 100 when 300 and so on.

	me->add("neili", -cost);
	me->receive_damage("jingli", cost, "����͸֧��������");
	me->receive_damage("qi", cost, "����͸֧��������");

        return 1;
}


string exert_function_file(string func)
{
	object me = this_player();
	mapping skill;
	string *skname;
	int i, n = 0;

	skill = me->query_skills();
	skname = sort_array(keys(skill), (: strcmp :) );

	for(i=0; i<sizeof(skill); i++) 
	{
		if (SKILL_D(skname[i])->check() == "force")
       	        n++;  
	}

	if ( n >=2 && !me->query_skill("qiankun-danuoyi", 1) )	// if learned qkny, can exert
	{							// even when have 2+ forces
		tell_object(me, "�����ڲ�ͬ���������ײ������ʹ��Ǭ��һ������\n");
		return 0;
	}

	return __DIR__"shenghuo-xuangong/" + func;
}
