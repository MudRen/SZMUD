// Code of ShenZhou
// zhixin.c
// xuy 09/22/96

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);

	if (level < 60) return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("�������������ǿ��\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	
	if ( me->query_temp("linji/zhixin") )
		return notify_fail("���Ѿ�����֮�Ķ�ׯ���������ˡ�\n");

	me->set_temp("linji/zhixin", 1);
	write( HIY "��΢һ�����˶�֮����ׯ��ȥ���������⣬�����������У�ֻ����̨�������������ƺ��������ӡ�\n" NOR);
	message("vision",
		HIY + "ֻ��" + me->name() + "΢һ�������¼��ڳ�����һ�������鶯������������ġ�\n" NOR,
		environment(me), me);

	me->add("neili", -4*level);
	level += me->query_skill("literate", 1);
	level = 1+random(level)/16;
	me->add_temp("apply/intelligence", level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "recover", me, level :), 1800);

	return 1;
}

void recover(object me, int level)
{
	me->add_temp("apply/intelligence", -level);
	me->delete_temp("linji/zhixin");

	tell_object(me, HIG"�������ѻ������������ƺ��������ֹ���Ѱ����\n"NOR);
}
