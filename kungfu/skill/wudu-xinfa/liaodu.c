// liaodu.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹�������������\n");

	if ((int)me->query_condition("chilian_poison") > 0) {
        if ((int)me->query_skill("wudu-xinfa", 1) < 40)
                return notify_fail("����嶾�ķ���Ϊ���������������ƶ����衣\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("��������������������ƶ����衣\n");

        if ((int)me->query_condition("chilian_poison") > me->query_skill("wudu-xinfa",1) )
                return notify_fail("���еĳ������ƶ����������������\n");

        write( HIW "��ȫ�������������������ʼ�˹�������\n" NOR);
        message_vision(
                HIW "$N����������³�һ�ں���ɫ����Ѫ��\n" NOR,
                me);
        me->apply_condition("chilian_poison", 0);
        me->add("neili", -200);
   }
   else write("�㲢δ�ж���\n");

        return 1;
}
