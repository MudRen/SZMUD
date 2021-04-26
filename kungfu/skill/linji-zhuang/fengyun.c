// Code of ShenZhou
// fengyun.c
// xuy 4/22/97

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);

	if (level < 120) return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("�������������ǿ��\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	
	if ( me->query_temp("linji/fengyun") )
		return notify_fail("���ʱ��֫�ٺ������ĵ��������ٴ��˹���\n");

	me->set_temp("linji/fengyun", 1);
	write( HIY "�㰵�˷�����ׯ����˼����Ʈ��֮���л�����Ĭ���絴��֮Ѹ�ٽ�����\nһ�ɵ���������ע��֫�ٺ�������������������ࡣ\n" NOR);
	message("vision",
		HIY + "ֻ��" + me->name() + "΢��˫�ۣ���������һȦ����˲Ϣ��һ����������"+me->name()+"�����ָ�������\n" NOR,
		environment(me), me);

	me->add("neili", -level);
	level /= 10;
	me->add_temp("apply/dexerity", level);
	me->add_temp("apply/attack", -level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "recover", me, level :), 500);

	return 1;
}

void recover(object me, int level)
{
	me->add_temp("apply/dexerity", -level);
	me->add_temp("apply/attack", level);
	me->delete_temp("linji/fengyun");

	tell_object(me, HIG"������й��Ѿã��Ծ����ĳ�����һЩ��\n"NOR);
}
