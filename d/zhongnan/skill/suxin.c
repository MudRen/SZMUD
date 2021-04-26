// Code of ShenZhou
//suxing.c ��Ů����
//by sdong

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	int bili,original,dodge,skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("�����õĲ�����Ů�ľ����޷�ʩչ��Ů���ģ�\n");

	if( me->query_skill("yunu-xinjing", 1) < 60 )
		return notify_fail("�����Ů�ľ����δ�����޷�ʩչ��Ů���ģ�\n");


	if( me->query_skill("sword") < 135 )
		return notify_fail("�����Ů������Ϊ���㣬������ʹ����Ů���ģ�\n");

	if( me->query("neili") <= 400 )
		return notify_fail("�����������ʹ����Ů���ģ�\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ����Ů���ģ�\n");

	if( (int)me->query_temp("suxin") ) 
		return notify_fail("���Ѿ���������Ů���ģ�\n");


	message_vision(HIR "$N��Хһ����������Ů�����ھ���������ԴԴ���ϵ�ע��"+(me->query_temp("weapon"))->query("name")+ HIR "����ҲͻȻ�ӿ죡\n\n" NOR, me);

	skill = me->query_skill("yunu-jianfa", 1);
	original = me->query_skill("force")/2;
	bili = me->query_str();
	dodge = me->query_dex();

	me->add_temp("apply/strength", bili/2);
	me->add_temp("apply/dexerity", dodge/2);
    me->add_temp("apply/damage", 150);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    me->add_temp("apply/damage", -150);
	me->add_temp("apply/armor", original);
    me->add_temp("apply/damage", original);
	me->start_busy(1+random(2));
	me->add("neili", -150);
	me->add("jingli", -100);
	me->set_temp("suxin", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, bili,original,dodge :), 5);
//	me->start_busy(3);


	return 1;
}


void remove_effect(object me, int bili, int amount,int dodge)
{
	me->add_temp("apply/strength", - bili/2);
	me->add_temp("apply/dexerity",-dodge/2);
	me->add_temp("apply/armor",-amount);
    me->add_temp("apply/damage", -amount);

	me->delete_temp("suxin");

	tell_object(me, "�㻺������һ�������ջ���Ů���ģ������ֻص����\n");
}
