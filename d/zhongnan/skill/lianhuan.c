// Code of ShenZhou
///kungfu/skill/chunyang-quan/lianhuan.c ��������
// sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int str, dex, skill;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	if( objectp(me->query_temp("weapon")) )
		return notify_fail("������������ֲ���ʩչ��\n");

	if( me->query_skill_mapped("cuff") != "chunyang-quan" )
		return notify_fail("�����õĲ��Ǵ���ȭ������ʩչ�������У�\n");

	if( me->query_skill_prepared("cuff") != "chunyang-quan" )
                return notify_fail("�������Ĳ��Ǵ���ȭ������ʩչ�������У�\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("�����õĲ����������칦��ʩչ�����������У�\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("����������칦���δ�����޷�ʩչ�������У�\n");

	if( me->query_skill("cuff") < 135 )
		return notify_fail("����������Ҫ��տ�Ĵ���ȭ������Чʩչ��\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ���������У�\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ���������У�\n");


	message_vision(HIR "$Nŭ��һ�����վ�ȫ����ͻȻ����㹥���������У�\n\n" NOR, me, target);

	str = me->query_str();
	//me->add_temp("apply/strength", str/2);
	me->add_temp("apply/attack",100);
	me->set_temp("lianhuan",1);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	//me->add_temp("apply/strength", -str/2);
	//me->add_temp("apply/dexerity", -dex/2);
	me->add_temp("apply/attack",-100);
	me->delete_temp("lianhuan");

	me->add("neili", -150);
	me->add("jingli", -100);
	me->start_busy( 1+random(2) );

	return 1;
}


