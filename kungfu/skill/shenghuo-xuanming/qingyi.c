// Code of ShenZhou
// qingyi.c �������

#include <ansi.h>

int exert(object me, object target)
{
	int dex, dex2, amount;

        if( !me->is_fighting() )
                return notify_fail("�������ֻ����ս����ʹ�á�\n");

	if (me->query_temp("qingyi"))
		return notify_fail("���Ѿ���ʹ����������ˡ�\n");

	if (((int)me->query_encumbrance()*100/(int)me->query_max_encumbrance()) > 50)
		return notify_fail("�㸺��̫�࣬��ôҲʹ����������졣\n");

        if( me->query_dex() < 30 )
                return notify_fail("�����������ʩչ������죡\n");

        if( me->query_skill_mapped("force") != "shenghuo-xuanming" )
                return notify_fail("�����õĲ���ʥ���������޷�ʹ��������죡\n");

	if (me->query_skill_mapped("dodge") != "qingfu-shenfa")
		return notify_fail("�����õĲ������������޷�ʹ��������죡\n");

        if( me->query_skill("force") < 135 )
                return notify_fail("���ʥ���������δ�����޷�ʩչ������죡\n");

        if( me->query_skill("dodge") < 135 )
                return notify_fail("����������Ϊ���㣬������ʹ��������죡\n");

        if( me->query("neili") < 1000 )
                return notify_fail("�����������ʹ��������죡\n");

        message_vision(HIW"$N������һ����Ϣ,���Ӿ�����ӯ����࣬������$N������Х�����ξ�������һ�㣬�����ɱ���������Ϊһ�Ű�Ӱ��\n" NOR, me);

	dex = me->query("dex");		// original dex
	dex2 = me->query_dex();		// temp dex

	dex2 = dex2 * (dex/10);		// this makes original dex important, players need to reconsider 
					// their gift selection

	me->add_temp("apply/dexerity", dex2);
	me->add_temp("apply/strength", -(dex2/15) );	// reduce some bili to compensate dex increase.
	me->add("neili", -(dex2*4) );
	me->set_temp("qingyi",1);

        amount = me->query_skill("qingfu-shenfa") /5;

	call_out("remove_effect",amount,me,dex2);
        me->start_busy(1+random(2));

        return 1;
}

int remove_effect(object me, int dex2)
{
	message_vision(HIW"$N΢΢���˿������������������ָ�������\n"NOR,me);
	me->add_temp("apply/dexerity", -dex2);
	me->add_temp("apply/strength", dex2/15);
	me->delete_temp("qingyi");

	return 1;
}