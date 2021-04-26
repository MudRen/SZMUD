// Code of ShenZhou
//jianzhang.c ���������� 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	object weapon1;
	int    lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon1 = me->query_temp("weapon");
        if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("�������޽������ʹ�ý�����������\n");

	if( me->query_skill_mapped("strike") != "hunyuan-zhang" )
		return notify_fail("�����õĲ��ǻ�Ԫ�ƣ������뻪ɽ�������ʩչ������������\n");

	if( me->query_skill_prepared("strike") != "hunyuan-zhang" )
                return notify_fail("�������Ĳ��ǻ�Ԫ�ƣ������뻪ɽ�������ʩչ������������\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
		return notify_fail("�����õĲ�����ϼ�����޷�ʩչ������������\n");

	if( me->query_skill("zixia-gong", 1) < 60 )
		return notify_fail("�����ϼ�����δ�����޷�ʩչ������������\n");

	if( (lvl1=me->query_skill("strike")) < 100 )
		return notify_fail("������������Ҫ��տ�Ļ�Ԫ����ϣ�������Чʩչ��\n");

	if( (lvl2=me->query_skill("sword")) < 100 )
		return notify_fail("�㻪ɽ������Ϊ���㣬������ʹ�ý�����������\n");

	amount = (lvl1+lvl2) / 15;

        if ( amount < 50 ) amount = 50;
	if ( amount > 100 ) amount = 100;

	if( me->query("neili") <= amount*3 )
		return notify_fail("�����������ʹ�ý�����������\n");
	if( me->query("jingli") <= amount*2 )
		return notify_fail("��ľ�������ʹ�ý�����������\n");

	if( me->query_skill_prepared("cuff") == "pishi-poyu" ) {
		me->set_temp("restore", 1);
		me->prepare_skill("cuff");
	}

	weapon = me->query_temp("weapon");

	me->add_temp("apply/damage", amount*3/2);
	me->add_temp("apply/attack", amount*2);
	me->add_temp("apply/dodge", amount*2);

	message_vision(HIR "\nͻȻ��$N���ε�����˲��ƽ�$n�����ƽ�������$n���������������ƣ�\n\n" NOR, me, target);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->start_busy(1+random(2));
	me->add_temp("apply/damage", -amount*3/2);
	me->add_temp("apply/attack", -amount*2);
	me->add_temp("apply/dodge", -amount*2);
	me->add("neili", -amount*2);
	me->add("jingli", -amount*3/2);
	if( me->query_temp("restore") ) me->prepare_skill("cuff", "pishi-poyu");

	return 1;
}
