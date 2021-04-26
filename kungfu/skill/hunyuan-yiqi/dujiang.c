// Code of ShenZhou
// dujiang.c һέ�ɽ�
// by Felix 5/2002

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SSERVER;

void remove_effect(object me, int dh);

int exert(object me, object target)
{
	int dh, time;

	if( me->query("family/family_name") != "������")
		return notify_fail("�㲻�����ֵ��������ʩչһέ�ɽ���\n");

	if( me->query("family/generation") != 35)
		return notify_fail("��ı��ֲ��������޷����һέ�ɽ�������\n");

	if( me->query_skill("shaolin-shenfa", 1) < 200)
		return notify_fail("������������δ�����޷�ʩչһέ�ɽ���\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 200)
		return notify_fail("��Ļ�Ԫһ����Ϊ���������޷�ʩչһέ�ɽ���\n");
	
	if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
		return notify_fail("�����õĲ��ǻ�Ԫһ�������޷�ʩչһέ�ɽ���\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("���Ѿ������˽�շ�ħ��ͨ������ͬʱʩչһέ�ɽ���\n");

	if( (int)me->query_temp("dujiang") )
		return notify_fail("���Ѿ���ʩչһέ�ɽ���\n");

	if( !me->is_fighting() )
		return notify_fail("�������ս���в���ʹ��һέ�ɽ���\n");

	dh = (me->query_skill("dodge") + me->query_skill("force"))/5;

	time = me->query_skill("shaolin-shenfa", 1)/10;
	if ( time < 10) time = 10;

	message_vision(HIC
	"\n$N��Ȼ����ббԾ���ɸߣ����������ˮֱ���߿գ��ٶ�֮��������ϡ�\n"
	"��δ����ȥ�ƣ��ͼ��缲�籩������ʽ����ͷй�¡�\n"NOR, me);

	me->add_temp("apply/defense", dh);

	me->add_temp("apply/speed", dh);

	me->add("neili", -200);

	me->set_temp("dujiang", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dh :),time );

	return 1;
}

void remove_effect(object me, int dh)
{
	message_vision(HIC
		"\n$N�������˿����������ȥ�������ˡ�һέ�ɽ����ļ��ơ�\n"NOR, me);

	me->add_temp("apply/defense", -dh);

	me->add_temp("apply/speed", -dh);

	me->delete_temp("dujiang");
}