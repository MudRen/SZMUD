// Code of ShenZhou
// cure.c
// RYU

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹��ƾ���������\n");

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("��Ŀ���������Ϊ��������\n");
	if( (int)me->query("jingli") < 50 )
		return notify_fail("��ľ���������\n");
	if( (int)me->query("jingli") < 300 )
                return notify_fail("��ľ���������\n");

	if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
		return notify_fail("�����ڲ���Ҫ�ƾ���\n");

	write( HIW "�������ϻ�һ���˿ڣ�����һЩ��Ѫ�����������ʼ�����ƾ���\n" NOR);
	message("vision",
		HIW + me->name() + "�����ϻ�һ���˿ڣ�����һЩ��Ѫ����ɫ�������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("jing", (int)me->query_skill("force")/2 );
	me->receive_wound("qi", 5);
	me->set("jiali", 0);

	return 1;
}
