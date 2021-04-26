// Code of ShenZhou
// bitao-xuangong.c ��������
// kane May 4, 1997.

#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/force_list.h"

string check() { return "force"; }

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
        int i, k=0;

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("baitao-xuangong", 1) > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )return notify_fail ("�����ڲ�ͬ���������ײ����������������ڹ���\n");
        }


	if ( (int)me->query_skill("force", 1)  <  10 
	   ||(int)me->query_skill("force", 1)/2 < (int)me->query_skill("bitao-xuangong", 1)/3 )
		return notify_fail("��Ļ����ڹ���򻹲������޷�������������\n");

	if ( me->query("gender") == "����" && (int)me->query_skill("bitao-xuangong",1) > 59)
		return notify_fail("�����޸����ԣ������������Ѹ���һ��¥��\n");

	if ( (int)me->query_skill("bitao-xuangong", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
		return notify_fail("���ܸ����а���ڹ�ǣ�����������ˮ�����ݣ����Ѹ���һ��¥��\n");

	if ( (int)me->query_skill("bitao-xuangong", 1) >= 120 
	&& (int)me->query_skill("huagong-dafa", 1) >= 1 
	&& (int)me->query_int() < 40 )
		return notify_fail("����а���ڹ������������ˮ�����ݣ����Ѹ���һ��¥��\n");


	return 1;
}

int practice_skill(object me)
{
	if ( me->query_skill("bitao-xuangong", 1) < 180 )
		return notify_fail("��ı���������Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
	if ( me->query_temp("weapon") )
		return notify_fail("��ϰ��������������֣��������ķ��ɡ�\n");
	if ( (int)me->query("qi") < 70 )
		return notify_fail("�������������ϰ����������\n");
	if ( (int)me->query("jingli") < 70 )
		return notify_fail("��ľ���������ϰ����������\n");
	if ( (int)me->query("neili") < 70 )
		return notify_fail("�������������ϰ����������\n");
	if ( (int)me->query("potential") < 1)
                return notify_fail("���Ǳ�ܲ�����\n");

	me->add("neili", -36);
	me->receive_damage("jingli", 49, "����͸֧��������");
	me->receive_damage("qi", 49, "����͸֧��������");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"bitao-xuangong/" + func;
}

// move to luoying-shenfa
/*
mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	string msg;
	int ap, dp;


	if( !victim->query_temp("wuzhuan") ) return damage;
	
	if( !victim->is_busy() ) return damage;

	ap = me->query("combat_exp")/1000;
	dp = victim->query("combat_exp")/1000;
	dp += victim->query_skill("bitao-xuangong", 1);
	dp += victim->query_skill("qimen-dunjia", 1);
	dp = (dp + random(dp*2))/2;

	if( ap > dp ) return damage;

        victim->start_busy(1);
        victim->interrupt_me();
	msg = HIB "$Nһ����Х�����²������Ų�������ǰ�������������з���";
        msg += "���ȶ�Ӱ��˲��ֻ����ʮ����Ӱ������������߲�����\n"NOR;
        
	message_vision(msg, victim);
	return damage;
}

*/

mapping curing_msg(object me)
{
        return ([
"apply_short"	:me->name()+"��̤�����Է�λ�����������ˡ�",
"start_self"	:HIG"����»���̤�����Է�λ�������������оŹ���һ��Ǳ�˱��������������ơ�\n"NOR,
"start_other"	:HIG""+me->name()+"�����߶��������ɼ��ٽ���ת���Ƴ�����������ʱ��ʱ�֡�\n"NOR,
"finish_self"	:HIG"�㻺�����߶�ʱ���Ծ�����˳�������˾�ȥ���ڶ�����ľ֮λͣ���˲�����\n"NOR,
"finish_other"	:me->name()+"�����ѱϣ���������һ�����ˣ�ͣ�½Ų�������ȥ��ɫ�����������ӡ�\n",
"unfinish_self"	:"���������Ų�������������������Ϣ��̷��������ͣ�½Ų����ݻ����ˡ�\n",
"unfinish_other":me->name()+"ͣ�½Ų��������������ˣ���ɫ�������ö��ˡ�\n",
"halt_self"	:"��������Ϣ��Ӳ�����ؽ���Ϣѹ����ȥ��ͣ���˽Ų���\n",
"halt_other"	:me->name() +"����ͣ�²���������һ���³�һ����Ѫ������������֮ɢ�ݡ�\n",

        ]);
}
