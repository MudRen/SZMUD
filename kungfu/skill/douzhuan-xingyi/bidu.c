// Code of ShenZhou
// Code of ShenZhou
// bidu.c


#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹��ƾ���������\n");

        if ((int)me->query_skill("douzhuan-xingyi", 1) < 40)
                return notify_fail("��Ķ�ת���ƹ���������\n");
        if( (int)me->query("jingli") < 50 )
                return notify_fail("��ľ���������\n");
        if( (int)me->query("jingli") < 300 )
                return notify_fail("��ľ���������\n");

        if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
                return notify_fail("�����ڲ���Ҫ�ƾ���\n");

        write( HIW "��Ĭ���ڹ�,�Ƴ�һЩ����,�о��ö��ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + "��ס��ʹ���һ���˿ڣ����ڹ��Ƴ�һ˿���ʡ�\n" NOR,
                environment(me), me);

        me->receive_curing("jing", (int)me->query_skill("force")/2 );
        me->add("neili", -30);
        me->receive_wound("qi", 5);
        me->set("jiali", 0);

        return 1;
}
