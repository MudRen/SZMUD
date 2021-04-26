// Code of ShenZhou
// wuji.c ��Ԫ�޼�

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ԫ�޼�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("wuji") )
		return notify_fail("������ʹ�û�Ԫ�޼��ˣ�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("���ֲ���ʩչ��Ԫ�޼���\n");

	if( me->query_skill_mapped("strike") != "hunyuan-zhang" )
		return notify_fail("�����õĲ��ǻ�Ԫ�ƣ�����ʩչ��Ԫ�޼���\n");

	if( me->query_skill_prepared("strike") != "hunyuan-zhang" )
                return notify_fail("�������Ĳ��ǻ�Ԫ�ƣ�����ʩչ��Ԫ�޼���\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("�����õĲ�����ϼ����ʩչ������Ԫ����\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("�����ϼ�����δ�����޷�ʩչ��Ԫ����\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("��Ԫ�޼���Ҫ��տ�Ļ�Ԫ�Ʒ�����Чʩչ��\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ�û�Ԫ�޼���\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ�û�Ԫ�޼���\n");	

	if( me->query_skill_prepared("cuff") == "pishi-poyu" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("cuff");
        }

	message_vision(MAG "\n$N������ϼ����ȫ����˿˿�����������ŷ�������һ��������������Ϣ��ӿ��$n��\n\n" NOR, me, target);
	me->set_temp("wuji", 1);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -150);
	me->add("jingli", -100);

	if( me->query_temp("restore") ) me->prepare_skill("cuff", "pishi-poyu");

	return 1;
}
