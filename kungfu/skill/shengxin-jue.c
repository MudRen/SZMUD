// Code of ShenZhou
// Keny's skill
// ʥ�ľ�

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

        if(me->query_skill("shengxin-jue", 1) > 99){

       for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
        }

	if ( (int)me->query_skill("force", 1)  <  10 
           ||(int)me->query_skill("force", 1)/2 < (int)me->query_skill("shengxin-jue", 1)/3 )
                return notify_fail("��Ļ����ڹ���򻹲������޷����ʥ�ľ� ��\n");

        if ( me->query("gender") == "����" && (int)me->query_skill("shengxin-jue",1) > 49)
                return notify_fail("�����޸����ԣ�ʥ�ľ����Ѹ���һ��¥��\n");


        if ( (int)me->query_skill("shengxin-jue", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
                return notify_fail("���ܸ����а���ڹ�ǣ����ʥ�ľ�ˮ�����ݣ����Ѹ���һ��¥��\n");

	return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("shengxin-jue", 1) < 150 )
                return notify_fail("���ʥ�ľ���Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
	if ( me->query_temp("weapon") )
                return notify_fail("��ϰʥ�ľ�������֣��������ķ��ɡ�\n");
	if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰʥ�ľ���\n");
	if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰʥ�ľ���\n");
	if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰʥ�ľ���\n");

	me->add("neili", -60);
	me->receive_damage("jingli", 60, "����͸֧��������");
	me->receive_damage("qi", 60, "����͸֧��������");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"shengxin-jue/" + func;
}

mapping curing_msg(object me)
{
	return ([
"start_other" :WHT+me->name()+"�����ڵ��ϣ�ɢ����һ�����ɫ�������� \n"NOR,
"start_self" :WHT"��������ɢ����һ�����ɫ����������ͨ��ȫ���Ѩ���������ˡ� \n"NOR,
"unfinish_other": WHT"����һ�ᣬ"+me->name()+"�������ǹ������� \n"NOR,
"unfinish_self": WHT"��е�ȫ��̩ͨ�˺ܶ࣬�������ǹ������� \n"NOR,
"finish_other": WHT+me->name()+"վ�����������������ǹ������� \n"NOR,
"finish_self": WHT"��վ�����������������ǹ������� \n"NOR,
	]);
}
