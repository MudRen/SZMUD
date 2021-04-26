// xidu.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() ||target->is_fighting()  )
                return notify_fail("ս�����˹�������������\n");

   if (me->query_condition("snake_poison") > 0 ||
       me->query_condition("xx_poison") > 0 ||
       me->query_condition("chilian_poison") > 0 ||
        me->query_condition("bt_poison") > 0)
        return notify_fail("���Լ������о綾���޷�Ϊ����������\n");

	if ((int)target->query_condition("chilian_poison") > 0) {
        if ((int)me->query_skill("wudu-xinfa", 1) < 70)
                return notify_fail("����嶾�ķ���Ϊ�����������˳������ƶ����衣\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("����������������˳������ƶ����衣\n");

        message_vision(
                HIY "$N��������������������$n����....\n\n"
                "ͻȻ�䣬$N���������$n�³�һ�ں���ɫ����Ѫ��\n"
                "��$N��ǰ�����Ǻ���һƬ��\n" NOR,
                me, target );

        me->apply_condition("chilian_poison", target->query_condition("chilian_poison"));
        target->apply_condition("chilian_poison", 0);

        me->add("neili", -150);
   }
   else write(target->name()+"��δ�ж���\n");

        return 1;
}
