// jingheal.c
// by April 2001.11.01

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )	return notify_fail("ս�����˹��ƾ���������\n");

	if ((int)me->query_skill("yunu-xinjing", 1) < 60)
		return notify_fail("�����Ů�ľ���Ϊ��������\n");

	if ((int)me->query_skill("suxin-jue", 1) < 30)
		return notify_fail("������ľ���������\n");

	if( (int)me->query("jingli") < 200 )
		return notify_fail("��ľ���������\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
		return notify_fail("�����ڲ���Ҫ�ƾ���\n");

	write( HIW "��Ǳ��Ĭ����������������ľ������ƾ�����\n" NOR);
	message("vision",
		HIW + me->name() + "��Ĭ����Ǳ��Ĭ����������������ľ������ƾ�����\n" NOR,
		environment(me), me);

	me->receive_curing("jing", (int)(me->query_skill("force")+me->query_skill("suxin-jue",1))/10);
	me->add("neili",-100);
	me->add("jingli",-50);
	me->set("jiali", 0);

	return 1;
}
