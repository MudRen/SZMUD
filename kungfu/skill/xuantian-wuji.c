// xuantian-wuji �����޼���

#include <ansi.h>
inherit FORCE;
string check() {return "force";}
#include "/kungfu/skill/force_list.h"


int valid_enable(string usage)
{
	return usage == "force";
}


int valid_learn(object me)
{
int lvl = (int)me->query_skill("xuantian-wuji", 1);
int t = 1, j; 
mapping skl;
string *sname;
int i,k=0;
skl=this_player()->query_skills();
sname=sort_array(keys(skl), (: strcmp :) );
if(me->query_skill("xuantian-wuji", 1) > 99){
for(i=0; i<sizeof(skl); i++) {
if (SKILL_D(sname[i])->check() == "force")
k++;
}

if ( k >=2 ) 
return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n"); 
}

    if ( (int)me->query_skill("force",1) < 10 )
   return notify_fail("��Ļ����ڹ���򻹲�����\n");

    if (lvl > 10 && (int)me->query("shen") < t * 100)
   return notify_fail("�����������̫���ˡ�\n");

    return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("xuantian-wuji", 1) < 180 )
                return notify_fail("��������޼�����Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ�����޼���������ֻ����������ɡ�\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰ�����޼�����\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰ�����޼�����\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰ�����޼�����\n");

	if ( me->query_skill("xuantian-wuji", 1) < 250 ) {
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
	return __DIR__"xuantian-wuji/" + func;
}
mapping curing_msg(object me)
{
return ([
"start_other" :HIY+me->name()+"�����ڵ��ϣ������������޼������ˡ� \n"NOR,
"start_self" :HIY"�����������������޼�������ͨ��ȫ���Ѩ���������ˡ� \n"NOR,
"unfinish_other":HIY"����һ�ᣬ"+me->name()+"�е�ȫ��̩ͨ�˺ܶ࣬�������ϵ����ƻ�ûȬ���� \n"NOR,
"unfinish_self":HIY"��е�ȫ��̩ͨ�˺ܶ࣬�������ϵ����ƻ�ûȬ���� \n"NOR,
"finish_other":HIY+me->name()+"վ�����������е�ȫ��̩ͨ�� \n"NOR,
"finish_self":HIY"��վ�����������е�ȫ��̩ͨ�� \n"NOR,
]);
}
