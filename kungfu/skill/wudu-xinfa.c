// wudu-xinfa �嶾�ķ�
// By Xuanyuan
#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("wudu-xinfa", 1);
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

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ�����������������������嶾�ķ���\n");

        if ( me->query("gender") == "����" && lvl > 80)
                return notify_fail("����Ϊ���ӣ�������������嶾�ķ���\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("�嶾�ķ������������ϣ���Υ��������徻֮�⣬"
                        +RANK_D->query_respect(me)+"���޴˹������������\n");

        if ((int)me->query_skill("force", 1) < 10 
          || (int)me->query_skill("force", 1)/2 < lvl/3 )
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if (lvl > 10 && (int)me->query("shen") > - t * 100
             && me->query_skill("yunu-jue", 1) < 100) 
                return notify_fail("��ϰ�嶾�ķ�Ҫ�ĺ������������Ļ�������\n");

        return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("wudu-xinfa", 1) < 150 )
                return notify_fail("����嶾�ķ���Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ�嶾�ķ�������֣��������ķ��ɡ�\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰ�嶾�ķ���\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰ�嶾�ķ���\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰ�嶾�ķ���\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "����͸֧��������");
        me->receive_damage("qi", 60, "����͸֧��������");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"wudu-xinfa/" + func;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"����һ�Դ����붨��ͷ������"HIB"����ɫ������"NOR"��",
		"start_self"	: HIW"���Ϣ������Ĭ���ڹ���ʼ�˹����ˡ�\n"NOR,
		"start_other"	: HIW"ֻ��"+ me->name() +"��Ŀ���£�Ƭ��֮ʱ��ͷ��ð��˿˿����ɫ������\n"NOR,
		"finish_self"	: HIY"����һ�ᣬ������ȥ���㿴������ɫ�ö��ˡ�\n"NOR,
		"finish_other"	: me->name() +"�Ұ׵���ɫ�������󣬻��������ۣ�վ��������\n",
		"unfinish_self" : "�㽥�������������󾢲��̣����ò��������ڰ��˵���Ϣ�ջء�\n",
		"unfinish_other": me->query("eff_qi") < me->query("max_qi")*3/4 ?
				  "�͵���"+ me->name() +"��һ�ţ����������Ѫ��\n" :
				  "�͵���"+ me->name() +"��һ�ţ��³����Ϻ���Ѫ��\n",
	]);
}