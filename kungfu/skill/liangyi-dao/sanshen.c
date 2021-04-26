// Code of ShenZhou
//jianzhang.c ��������� 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	int lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill_mapped("cuff") != "pishi-poyu" )
		return notify_fail("�����õĲ�����ʯ����ȭ�������뻪ɽ�����ǵ������ʩչ��������壡\n");

	if( me->query_skill_prepared("cuff") != "pishi-poyu" )
		return notify_fail("�������Ĳ�����ʯ����ȭ�������뻪ɽ�����ǵ������ʩչ��������壡\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
		return notify_fail("�����õĲ�����ϼ�����޷�ʩչ��������壡\n");

	if( me->query_skill("zixia-gong", 1) < 60 )
		return notify_fail("�����ϼ�����δ�����޷�ʩչ��������壡\n");

	if( (lvl1=me->query_skill("cuff")) < 100 )
		return notify_fail("�����������Ҫ��տ����ʯ����ȭ��ϣ�������Чʩչ��\n");

	if( (lvl2=me->query_skill("blade")) < 100 )
		return notify_fail("�㷴���ǵ�����Ϊ���㣬������ʹ�û�������壡\n");
	
	amount = (lvl1+lvl2) / 15;

        if ( amount < 55 ) amount = 55;
        if ( amount > 100 ) amount = 100;
	amount = amount * 5/4;

	if( me->query("neili") <= amount*4 )
		return notify_fail("�����������ʹ�û�������壡\n");
	if( me->query("jingli") <= amount*2 )
		return notify_fail("��ľ�������ʹ�û�������壡\n");

	if( me->query_skill_prepared("strike") == "hunyuan-zhang" ) {
		me->set_temp("restore", 1);
		me->prepare_skill("strike");
	}

	weapon = me->query_temp("weapon");

	me->add_temp("apply/dodge", amount*2);

	message_vision(HIR "\n$N����һ����Х����������ʹ������������塹����$n������ػ�����ȭһ����\n\n" NOR, me, target);

	// make the 1st attack without weapon add more hit chances and damage.
	me->add_temp("apply/attack", amount*2);
	me->add_temp("apply/damage", amount*2);
	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	// make the 2nd attack with weapon add more damage and reduce hit chance.
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", amount);
	weapon->wield();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	// make the 3rd attack without weapon add more hit chance and reduce damage.
	me->add_temp("apply/attack", amount*2);
        me->add_temp("apply/damage", -amount);
	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();

	me->start_busy(1+random(2));
	me->add("neili", -amount*3);
	me->add("jingli", -amount*2);
        me->add_temp("apply/damage", -amount*2);
	me->add_temp("apply/dodge", -amount*2);
	me->add_temp("apply/attack", -amount*3);

	if( me->query_temp("restore") ) me->prepare_skill("strike", "hunyuan-zhang");

	return 1;
}
