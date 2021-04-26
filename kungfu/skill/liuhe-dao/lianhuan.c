// Code of ShenZhou
//lianhuan.c  ���ϵ�֮������

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ϵ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("lianhuan") )
                return notify_fail("������ʹ�����ϵ��������ˣ�\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "blade" )
                return notify_fail("�������޵�������ܹ�ʩչ��������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷���ϵ���ʩչ��������\n");

        if( me->query_skill("force") < 100 )
                return notify_fail("��Ļ����������δ�����޷���ϵ���ʩչ��������\n");

	if( me->query_skill("blade") < 100 )
		return notify_fail("�����ϵ�����Ϊ���㣬������ʹ����������\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʩչ��������\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʩչ��������\n");

 	skill = me->query_skill("blade");
	
	message_vision(HIR "\n$N���һ�������е���������������������������\n\n" NOR, me, target);
        skill = skill*2/3;
	if ( skill > 400 ) skill = 400;

	me->set_temp("lianhuan", 1);
	me->add_temp( "apply/attack", skill/2 );
	me->add_temp( "apply/parry", skill/2 );
	me->add_temp( "apply/damage", skill/2 );
	me->add_temp( "apply/dodge", skill/2 );
	me->add_temp( "apply/speed", skill/2 );
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/20 );
	me->add("neili", -300);
	me->add("jingli", -100);

	return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("lianhuan");
	me->add_temp( "apply/attack", -amount );
	me->add_temp( "apply/parry", -amount );
	me->add_temp( "apply/damage", -amount );
	me->add_temp( "apply/speed", -amount );
	me->add_temp( "apply/dodge", -amount );

	if ( me->is_fighting() ) {
        	message_vision(HIR "\n$N�Ļ�������������ϣ��������ջص����������Ҳ������������\n\n" NOR, me);
	}
	else {
		tell_object(me, HIR "\n��Ļ�������������ϣ������������ջص��\n\n" NOR);
	}
}
