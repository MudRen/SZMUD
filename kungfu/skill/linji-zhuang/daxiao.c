// Code of ShenZhou
// daxiao.c
// xuy 4/22/97

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);
	int amount;

	if (level < 150) return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("�������������ǿ��\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	
	if ( me->query_temp("linji/daxiao") )
		return notify_fail("���Ѿ��˹����ھ�����С�ˡ�\n");

	me->set_temp("linji/daxiao", 1);
	write( HIY "����Ϣ�������������д�С��ׯ��ֻ��һ��ů�������ţ����ػ�������ȫ��������һ�ܣ����뵤��������\n" NOR);
	message("vision",
		HIY + "ֻ��" + me->name() + "��Ϣ������ͷ��Ʈ��һ���ư�������̬����ƣ����\n" NOR,
		environment(me), me);

	amount = me->query("max_jing") - me->query("max_qi");
	if (amount < 0) amount = 0;

	amount = amount*level/400;

	me->add("max_qi", amount);
	me->add("max_jing", -amount);
	me->receive_curing("qi", amount);
	if ( (int)me->query("eff_jing") > (int)me->query("max_jing") ) 
		me->set("eff_jing", (int)me->query("max_jing") );
	me->add("neili", -4*level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, amount :), 1800);

	return 1;
}

void remove_effect(object me, int level)
{
	me->add("max_qi", -level);
	me->add("max_jing", level);
	if ((int)me->query("eff_qi") > (int)me->query("max_qi") )
		me->set("eff_qi", (int)me->query("max_qi") );
	me->receive_curing("jing", level);
	me->delete_temp("linji/daxiao");

	tell_object(me, HIG"���д�С��ׯ�Ѿã��ָֻ���ԭ�о�����\n"NOR);
}
