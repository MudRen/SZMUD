// Code of ShenZhou
// zhao.c for ding-force
// ������

#include <ansi.h>

int exert(object me, object target)
{
        int lv, dur, drop;
        string str;
	object ob;

        if( !me->is_fighting() )
                return notify_fail("�ȸ��˴��ʱ���ðɣ�\n");
	if (me->query_temp("huti"))
		return notify_fail("���Ѿ���������ֻ��幦�ˡ�\n");

        lv = (int)me->query_skill("ding-force", 1);
        dur = (int)me->query("neili");

        if (lv > 150)
        {
                drop = 200 * 150 / lv;
                dur = (dur - drop)/drop;
                str = HIR + me->name() + "������ɣ����浤�����һ��������\n"
                + HIG + "һ���������������ͻȻ����һֻ�ƽ���Ӱ�" +
                me->name() + "�������档\n" + NOR;
        }
        if (dur < 1)
                return notify_fail("��������������ý����֡�\n");

	seteuid(geteuid(me));
	ob =new("/u/ding/zhao.c");
	ob->move(me);
	ob->wear(me);
       
	me->add("neili", -drop);
        me->apply_condition("zhao", dur);
	me->set_temp("huti", 1);
        write(HIG + "����������ֻ��幦��\n" + NOR);
        message("vision", str, environment(me), me);
        return 1;
}

