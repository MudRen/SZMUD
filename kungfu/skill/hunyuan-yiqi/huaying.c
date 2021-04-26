// Code of ShenZhou
// huaying.c ����Ӱ
// by Felix 5/2002

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int tddg);

int exert(object me, object target)
{
	int ddg, tddg, time;

	if( me->query("family/family_name") != "������")
		return notify_fail("�㲻�����ֵ��������ʩչ����Ӱ��\n");

	if( me->query_skill("shaolin-shenfa", 1) < 100)
		return notify_fail("������������δ�����޷�ʩչ����Ӱ��\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 100)
		return notify_fail("��Ļ�Ԫһ����Ϊ���������޷�ʩչ����Ӱ��\n");

	if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
		return notify_fail("�����õĲ��ǻ�Ԫһ�������޷�ʩչ����Ӱ��\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("���Ѿ������˽�շ�ħ��ͨ������ͬʱʩչ����Ӱ��\n");

	if( (int)me->query_temp("huaying") )
		return notify_fail("���Ѿ���ʩչ����Ӱ��\n");

	time = me->query_skill("shaolin-shenfa", 1)/30;
	if ( time < 3) time = 3;
	if ( time > 10) time = 10;
	
	ddg = me->query_skill("dodge");

	tddg = me->set_temp("apply/dodge", ddg*11/10);

	me->add("neili", -50);

	message_vision(YEL
	"\n$N����һ�������˲���ɼ��ý��³���������������һ�Ż�Ӱ�������ۻ����ҡ�\n"NOR, me);

	me->set_temp("huaying", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :),time );

	return 1;
}

void remove_effect(object me, int tddg)
{
	me->set_temp("apply/dodge", tddg*10/11);

	me->delete_temp("huaying");

	message_vision(YEL
		"\nֻ����Ӱ����ɢȥ��$Nվ���ָ������Ρ�\n"NOR, me);
}