// Code of ShenZhou
// tiandi.c
// xuy 09/22/96

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);

	if (level < 30) return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("�������������ǿ��\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	
	if ( me->query_temp("linji/tiandi") )
		return notify_fail("���Ѿ�������ض�ׯ�۾��������ˡ�\n");

	me->set_temp("linji/tiandi", 1);
	write( HIY "��ϯ�ض������������죬������ض�ׯ����������������Ǳ����������������ض�����̩�����پ��Լ��������������ˡ�\n" NOR);
	message("vision",
		HIY + "ֻ��" + me->name() + "ϯ�ض������������죬���Ϻ��ʱ��ʱ�֣���һ�����������ĵ�վ��������\n" NOR,
		environment(me), me);

	me->add("max_qi", level);
	me->add("max_jing", level);
	me->add("max_jingli", level);
	me->receive_curing("qi", level);
	me->receive_curing("jing", level);
	me->receive_heal("jingli", level);
	me->add("neili", -4*level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, level :), 1800);

	return 1;
}

void remove_effect(object me, int level)
{
	me->add("max_qi", -level);
	me->add("max_jing", -level);
	me->add("max_jingli", -level);
	if ((int)me->query("eff_qi") > (int)me->query("max_qi") )
		me->set("eff_qi", (int)me->query("max_qi") );
	if ((int)me->query("eff_jing") > (int)me->query("max_jing") )
		me->set("eff_jing", (int)me->query("max_jing") );
	me->delete_temp("linji/tiandi");

	tell_object(me, HIG"���������֮������ɢ�����֮�䣬���ָֻ���ԭ�о�����\n"NOR);
}
