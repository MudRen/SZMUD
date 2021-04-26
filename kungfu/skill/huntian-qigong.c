// Code of ShenZhou
//huntian-qigong.c
//modified by Ryu, 1/29/97

inherit FORCE;
#include <ansi.h>
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
	int i, k=0;

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("huntian-qigong", 1) > 99){

	for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 ) return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
        }


	if ((int)me->query_skill("force", 1) < 10
	  ||(int)me->query_skill("force", 1)/2 < i/3 )
		return notify_fail("��Ļ����ڹ�����㣬����ѧ����������\n");

	return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("huntian-qigong", 1) < 150 )
                return notify_fail("��Ļ���������Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ��������������ֻ����������ɡ�\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰ����������\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰ����������\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰ����������\n");

	if ( me->query_skill("huntian-qigong", 1) < 250 ) {
        	me->add("neili", -80);
        	me->receive_damage("jingli", 80, "����͸֧��������");
        	me->receive_damage("qi", 80, "����͸֧��������");
	}
	else {
		me->add("neili", -100);
                me->receive_damage("jingli", 100, "����͸֧��������");
                me->receive_damage("qi", 100, "����͸֧��������");
	}

        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"huntian-qigong/" + func;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"	: HIW+BLK"�㻺�������������Ⱥ����������칦��������ȫ��\n"NOR,
		"start_other"	: HIW+BLK+ me->name() +"����������ͷ����ʱð����������ͷ�������£�ȫ��������ѡ�\n"NOR,
		"finish_other"	: WHT"����"+ me->name() +"����һ��쳱ӿ�ϣ��㼴��ȥ���ֳɻҰף������ף��ױ���ת�����Ρ�\n"NOR,
		"unfinish_other": HIW+BLK+ me->name() +"�۾���������һ�ߣ�����һ̲��Ѫ��\n"NOR,
	]);
}