// Code of ShenZhou
//xiantian-gong.c ���칦

#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int lvl = (int)me->query_skill("xiantian-gong", 1);
	        mapping skl; 
        string *sname;
        int i, k=0;
	int t = 1, j;
	for (j = 1; j < lvl / 10; j++) t *= 2;
	        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("this_skill") > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail
("�����ڲ�ͬ���������ײ����������������书��\n");
        }



//	if ( me->query("gender") == "����" )
//		return notify_fail("����������������������������������ϣ��Թ����޸�����֮������޵ã�\n");

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ��������������������������������\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("�������������������ϣ���Υ��������徻֮�⣬"
			+RANK_D->query_respect(me)+"���޴˹������������\n");

	if ((int)me->query_skill("force", 1) < 10 
	  || (int)me->query_skill("force", 1)/2 < lvl/3 )
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if (lvl > 10 && (int)me->query("shen") < t * 100
	     && me->query_skill("taoism", 1) < 100) 
		return notify_fail("�����������̫���ˡ�\n");

	return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("xiantian-gong", 1) < 150 )
                return notify_fail("������칦��Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ���칦������֣��������ķ��ɡ�\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰ���칦��\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰ���칦��\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰ���칦��\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "����͸֧��������");
        me->receive_damage("qi", 60, "����͸֧��������");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}

