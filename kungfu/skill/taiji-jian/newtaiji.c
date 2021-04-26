 // Perform Taiji

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        object weapon;
        weapon = me->query_temp("weapon"); 

        if( !target ) target = offensive_target(me); 

        if( !target || !target->is_character() || !me->is_fighting(target) ) 
        return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if( !weapon || !objectp(weapon) || weapon->query("skill_type") != "sword" ) 
                return notify_fail("�����ý�����������⹥��������\n"); 
        if(!me->query("wudang/cantaiji"))
                return notify_fail("Ŀǰ��ڤ�ӻ�δ����������⹥��\n");
        
        message_vision(HIW"$N�����еĽ���׼$n���˹�ȥ������Ҫ���䵱��ѧ��̫������\n"NOR, me, target);
        message_vision(HIW"$N�����������ʶ����Ȼ��������֮ƽ��\n"NOR, me, target);
        target->start_busy(6);
        remove_call_out("msg_one");
        call_out("msg_one",1,me,target);
        return 1;
}

void msg_one (object me, object target)
{
        message_vision(HIC"��ʶ������컯��ƽ����˽\n"NOR, me, target);
        remove_call_out("msg_two");
        call_out("msg_two",1,me,target);
        return;
}

void msg_two (object me, object target)
{
        message_vision(HIG"��ʶ�����������\n��ʶ�˾��Ե���ʵ֮��\n"NOR, me, target);
        remove_call_out("msg_three");
        call_out("msg_three",1,me,target);
        return;
}

void msg_three (object me, object target)
{
        message_vision(HIY"��ʶ�����ﲻ�ܸ��Ŷ��Զ�\n"NOR, me, target);
        remove_call_out("msg_end");
        call_out("msg_end",1,me,target);
        return;
}

void msg_end (object me, object target)
{
        message_vision(HIR"$N����˵����������Ҫ��$n�����������䵱��ѧ֮�£� $n���аɣ�����\n"NOR, me, target);
        message_vision(HIG"ֻ��$N����$n��$nʹ�����Ź�����$N����\n����$Nʹ��̫����߾��硸�����˽�����$n������ȫ����һΪ�㡣\n"NOR, me, target);
        message_vision(NOR"( $n" + HIY + "���˼����ˣ������ƺ��������¡�)\n"NOR, me, target);

        remove_call_out("f_one");
        call_out("f_one",1,me,target);
        return;
}

void f_one (object me, object target)
{
        message_vision(HIY"$nʹ���Ṧ������$N�Ĺ���\n$N�ڿ���ת��һȦ�ý�����$n���ֲ���$n�������Ľ��������Ľ���һ��\n���ǲ���$N��$nʹ���䵱��̫��ȭ�е�ȭ�⡸������ǧ�𡹽����ٴβ���$n��\n$nʵ���мܲ�ס�����������˹�ȥˤ�����ϡ�\n"NOR, me, target);
        message_vision(NOR"( $n" + HIY + "���˼����ˣ������ƺ��������¡�)\n"NOR, me, target);
        
        message_vision(NOR"( $n" + RED + "�Ѿ���������״̬����ʱ������ˤ����ȥ�� )\n\n"NOR, me, target);
        target->set("qi", 100);
        me->start_busy(3);

        message_vision(HIG"$Nʹ���䵱�Ṧ���ڿ��еĽ��û���˧����վ�ڵ��ϡ�\n"NOR, me, target);
        remove_call_out("f_final");
        call_out("f_final",1,me,target);
        return;
}


void f_final (object me, object target)
{
        object weapon;
        weapon = me->query_temp("weapon"); 

        message_vision(HIY"$N�Ѿ�ץ��$n�����㣬ʹ���䵱�����ġ������־���\n"NOR, me, target);

        message_vision(HIG"$Nʹ���䵱�Ṧ���ڿ��еĽ��û���˧����վ�ڵ��ϡ�\n"NOR, me, target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIY"$NͻȻ����������ʹ��̫��ȭ��\n"NOR, me, target);
        
        weapon->unequip(); 
        target->set("qi", 1);
        target->unconcious();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIG"$N�������ջص��\n"NOR, me, target);

        return;
}
