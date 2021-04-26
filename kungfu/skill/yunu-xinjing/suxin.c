// Code of ShenZhou
// suxin.c
// slow 31/5/02

#include <ansi.h>

int exert(object me, object target)
{
        int level = me->query_skill("yunu-xinjing", 1);

        if (level < 120) return notify_fail("����ڹ���Ϊ��������\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("�������������ǿ��\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("�������������\n");
	
        if ( me->query_temp("ngsuxin") )
                return notify_fail("���ʱ���ڰ���Ů�ľ����ķ��й���\n");

        me->set_temp("ngsuxin", 1);
write( HIW "�㰵����Ů�����ķ����Ѷ��������ġ�ʮ���١�ʮ���ࡱ������Ҫ�����ӵ����¡�\n" NOR);
	message("vision",
             HIW + "ֻ��" + me->name() + "΢��˫�ۣ���ϲ���֣���˼����,�Ѷ��������ġ�ʮ���١�ʮ���ࡱ������Ҫ�����ӵ����¡�\n" NOR,
		environment(me), me);

	me->add("neili", -level);
        me->add_temp("apply/armor",  level);
        me->add_temp("apply/defense",  level);

	me->start_call_out( (: call_other, __FILE__, "recover", me, level :), 500);

	return 1;
}

void recover(object me, int level)
{
        me->delete_temp("ngsuxin");
        me->add_temp("apply/armor",  -level);
        me->add_temp("apply/defense",  -level);

        tell_object(me, HIG"���й��Ѿã������ջ���Ů���ĵ��ķ���\n"NOR);
}
