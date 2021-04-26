// Code of ShenZhou
// zixia-shengong.c ��ɽ ��ϼ��
// qfy July 4, 1996.

inherit FORCE;
string check() { return "force"; }

#include <ansi.h>
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	        mapping skl; 
        string *sname;
        int v, k=0;
        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("zixia-gong", 1) > 99){

       for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
        }

	if ( (int)me->query_skill("force", 1)  <  10 
	   ||(int)me->query_skill("force", 1)/2 < (int)me->query_skill("zixia-gong", 1)/3 )
		return notify_fail("��Ļ����ڹ���򻹲������޷������ϼ����\n");

	if ( me->query("gender") == "����" && (int)me->query_skill("zixia-gong",1) > 49)
		return notify_fail("�����޸����ԣ���ϼ�����Ѹ���һ��¥��\n");

	if ( (int)me->query_skill("zixia-gong", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
		return notify_fail("���ܸ����а���ڹ�ǣ������ϼ��ˮ�����ݣ����Ѹ���һ��¥��\n");

	return 1;
}

int practice_skill(object me)
{
	if ( me->query_skill("zixia-gong", 1) < 150 )
		return notify_fail("�����ϼ����Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
	if ( !present("zixia book", me) )
		return notify_fail("����ƾ�޾ݣ������ϰ��ϼ����\n");
	if ( me->query_temp("weapon") )
		return notify_fail("��ϰ��ϼ��������֣��������ķ��ɡ�\n");
	if ( (int)me->query("qi") < 70 )
		return notify_fail("�������������ϰ��ϼ����\n");
	if ( (int)me->query("jingli") < 70 )
		return notify_fail("��ľ���������ϰ��ϼ����\n");
	if ( (int)me->query("neili") < 70 )
		return notify_fail("�������������ϰ��ϼ����\n");

	me->add("neili", -60);
	me->receive_damage("jingli", 60, "����͸֧��������");
	me->receive_damage("qi", 60, "����͸֧��������");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"zixia-gong/" + func;
}

mapping curing_msg(object me, object target)
{
	string xb;
	if (me->query("gender") == "Ů��")xb = "��";
	else xb = "��";
	return ([
		"start_self"	: MAG"��͵���������ʹ��ϼ�����ˣ���Ϣ�������ƣ�����ģ����񽬣������أ�ߵ��������ͨ�������硣\n"NOR,
		"start_other"	: MAG+me->name()+ "�͵�������������������ʼ�˹����ˡ�\n"NOR,
		"finish_self"	: "�������ϼ�����˶�ʱ��һ��������������ת�ް��������Ѿ�ƽ��������վ��������\n",
		"finish_other"	: MAG"����"+ me->name()+ "ͷ����������������������ʢ����Ȼ��һ����Х��վ��������\n"NOR,
		"start_healother_other":MAG+ me->name()+ "����������ϼ���������İ�"+target->name()+"�������Ŵ�Ѩ������ؽ���������"+target->name()+"����....\n",
		"start_healother_self" :(["me" : MAG+"������������ϼ���������İ�"+target->name()+"�������Ŵ�Ѩ��\n����ؽ���������"+xb+"�����ڣ�Ϊ"+xb+"�˹����ˡ�\n",
					"target" : MAG+ me->name()+ "����������ϼ���������İ���ĸ������Ŵ�Ѩ��\n����ؽ���������������ڣ�Ϊ���˹����ˡ�\n",])
	]);
}
