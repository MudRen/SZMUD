// Code of ShenZhou
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
	int my_neili, op_neili, my_exp, op_exp;

	        if( !me->is_fighting() ) 
                return notify_fail("�������ս���в���ʹ���г彣����\n");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target || !target->is_character() || target->query("race") 
!= "����" )
                return notify_fail("��Ҫ��˭���г彣����\n");

        if( environment(target)->query("no_fight") )
                return notify_fail("�㲻��͵Ϯ��\n");

        if( me->query("neili") <= 500 )
                return notify_fail("����������㣬�޷�ʹ���г彣����\n");

	if( (int)me->query_skill("liumai-shenjian", 1)< 130)
	return notify_fail("�����������ϵ���Ϊ�������޷�ʹ���г彣����\n");
	
	my_neili = me->query("neili", 1);
	op_neili = target->query("neili", 1);
	my_exp   = me->query("combat_exp", 1);
	op_exp   = target->query("combat_exp", 1);

message_vision(HIR "$N˫�����㣬��ʱ���ν������죡\n\n" NOR, me, target);

	me->add("neili", -300);
	if (my_exp>op_exp) {
		if (my_neili > op_neili) {
		me->add("neili", -(op_neili));
		if (my_neili<0){
		me->set("neili", 0);
		}
		message_vision(HIR 
"$n���޿ɱܣ�ֻ��˫��ȫ����������$N�����಩��\n\n" NOR, me, target);
		target->set("neili", 0);
tell_object(target, RED "���ʱ����ȫ��һ�����ѣ�������Ȼȫ�ޣ�\n"NOR);
		me->start_busy(3);
		target->start_busy(2);
		}
	else {
	message_vision(HIR
	"$n���޿ɱܣ�ֻ��˫��ȫ����������$N�����಩��\n\n" NOR, me, target);
	me->set("neili",0);
	target->set("neili", (op_neili/2));
	tell_object(me, RED "���ʱ����ȫ��һ�����ѣ�������Ȼȫ�ޣ�\n"NOR);
	tell_object(target,RED 
"��һ�ƻ�������$N��ָ��������ɢ��ֻ��$N��ɫһ��Ұף�\n"NOR);
	me->start_busy(2); 
        target->start_busy(2);
                }
	}
	else {
	message_vision(HIR "n��æ���ף��Ǳ������Ķ��˿�ȥ��\n\n" NOR, 
me, target);   
	me->start_busy(1);
	return 1;
}
}

        

	        




