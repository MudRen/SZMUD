// Code of ShenZhou
// snowyu fix yun reverse then pxj guimei dodge 
// Scatter, BUG MESSAGE

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ��ʹ�Լ��ľ�����ת��\n");
        if( (string)me->query_skill_mapped("dodge") != "chanchubu" )
                return notify_fail("��û��ʹ�ñ����Ṧ,������о�����ת? \n");

        if( (int)me->query("neili") < 200  ) 
                return notify_fail("�������������\n");
        if( (int)me->query_temp("reverse") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -200);

        message_vision(
        HIY "ֻ��$N���не�������̺���������������ͷ�½���֮�Σ�˫�ֳŵأ�������ȥ��\n" NOR, me);
        //ͻȻһ�����ͷ�½��ϣ�����ŷ�������ڵĹ��򣬾�������
        me->add_temp("apply/dodge",  skill/2);
        me->set_temp("reverse", 1);

        call_out("remove_effect", skill/2 ,me,skill/2);

//      if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        object player = this_player();
        
        amount = me->query_skill("force")/-2 ;//      me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("reverse");
        tell_object(me, "��ľ�����ת������ϣ������ظ�һ��������\n");
}
