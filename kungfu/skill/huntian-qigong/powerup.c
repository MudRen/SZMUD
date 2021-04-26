// Code of ShenZhou
// powerup.c ������������
// fear 12/99 reduced neili cost, added parry effect

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ���û��������������Լ���ս������\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹�\���ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -skill*6/5);
        me->add("jingli", -skill/5);
        me->receive_damage("qi", 0);

        message_vision(
        HIR "$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������좦\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge",  skill/3);
        me->add_temp("apply/parry",  skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/8);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/parry", - amount);
        me->delete_temp("powerup");
        tell_object(me, HIY"��Ļ�������������ϣ��������ջص��\n"NOR);
}
