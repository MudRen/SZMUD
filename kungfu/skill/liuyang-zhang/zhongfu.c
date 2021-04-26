// Code of ShenZhou
// zhongfu.c
// modified by xuanyuan 29/07/2001
/*
����е��������������ƻ��裬�����򶡴�����������������а����ڹ�����ת��ڤ����������ʱ�ѽ����о�
ˮ�����߰�Ƭ��������������������ơ�
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int sp, dp, i;
        object obj;

	if( !target ) target = offensive_target(me);

       	if(me->query("lingjiu/shengsi")!=1)
			    return notify_fail("�������������������֣����ǲ�������δ߶������ַ���\n");

	if( !objectp(target) || target == me 
	|| target->query("id") == "mu ren" 
	|| target->query("id") == "shangshan" 
	|| target->query("id") == "mengzhu" 
	|| target->query("id") == "fae" )
		return notify_fail("��Ҫ��˭��������������\n");

//	if( !userp(target) )
//		return notify_fail("��ֻ���������������������\n");

//	if( !me->is_fighting() || !target->is_fighting() || !living(target) )
//		return notify_fail("�������ս���в�������������\n");

	if (!objectp(obj=present("jiudai", me)))
            return notify_fail("������û�оƴ������ܻ�ˮΪ����\n");

	if( target->query("zf")) 
		return notify_fail("�����Ѿ��������������ˣ�\n");

	if ((int)me->query_skill("xiaowu-xiang", 1)<150
		&& (int)me->query_skill("bahuang-gong", 1)<150
		&& (int)me->query_skill("beiming-shengong", 1)<150)
		return notify_fail("�����ң���ڹ�������������������������\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	

        if( (int)me->query_skill("liuyang-zhang",1) < 150 )
                return notify_fail("�����ɽ�����ƹ������������������������\n");
                
        if ( me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("��û�б���ɽ�����ƣ�\n"); 

        if( (int)me->query("neili",1) < 1000 )
		return notify_fail("���������������������������\n");

	message_vision(
		WHT "$NͻȻ�ӱ����ͳ�һ���ƴ������Լ����ĵ���Щ��ˮ��

$N���������а����ڹ�����ת����������ʱ�ѽ����о�ˮ�����߰�Ƭ����������
�̳�һ�ư��ߣ��͵���$n���ؿ����˹�ȥ��\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query_kar();
	sp *= me->query("combat_exp")/1000;
	dp *= target->query("combat_exp")/1000;
	

	if( random(sp) > random(dp) ) 
	{
		tell_object(target, HIR "��ֻ���ؿ�һ�ƣ�һ˿����ֱ��θ�������һƬ�հ�ãȻ��֪���룡\n" NOR);
		tell_object(me, HIG "�����ָ��İ�������" + target->name() + "���ؿڣ������Ѿ������������ˡ�\n" NOR);
	
                target->set("zf",me->query("id"));
                target->apply_condition("zf_poison",12);
		target->set("zf_lv",me->query_skill("bahuangh-gong",1));
		
		me->start_busy(random(10));
		target->add("jingli", -random(50));
		target->start_busy(random(3));
		me->add("neili", -125);
		me->add("jingli", -5);
	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ����һ�����Ѱ��߱��˻�ȥ��\n" NOR, me, target);
		tell_object(me, HIG "�������ָһ�����������һ�����ã��Ͼ��˹��ֿ���\n" NOR); 
		me->add("jingli", -15);
		me->add("neili", -125);
		me->add("qi", -200);
		me->start_busy(random(10));
		
		}

	return 1;
}


