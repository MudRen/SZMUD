// Code of ShenZhou
// leidong.c �׶�����

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int lvl, str, dex, skill;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�׶�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("leidong") )
		return notify_fail("������ʹ���׶������ˣ�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�׶���������ֲ���ʩչ��\n");

	if( me->query_skill_mapped("cuff") != "pishi-poyu" )
		return notify_fail("�����õĲ�����ʯ����ȭ������ʩչ�׶����죡\n");

	if( me->query_skill_prepared("cuff") != "pishi-poyu" )
                return notify_fail("�������Ĳ�����ʯ����ȭ������ʩչ�׶����죡\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("�����õĲ�����ϼ����ʩչ�����׶����죡\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("�����ϼ�����δ�����޷�ʩչ�׶����죡\n");

	if( (lvl=me->query_skill("cuff")) < 135 )
		return notify_fail("�׶�������Ҫ��տ����ʯ����ȭ������Чʩչ��\n");

	if( me->query("neili") <= lvl*2 )
		return notify_fail("�����������ʹ���׶����죡\n");
/*
	if( me->query_skill_prepared("strike") == "hunyuan-zhang" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("strike");
        }
*/
	message_vision(MAG "\nֻ����$Nһ����ȣ�ȭ��ͻȻ����;�֮������ȴ����Ʈ���Ѳ⣡\n\n" NOR, me, target);

//	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	str = me->query_str();
	dex = me->query_dex();
	me->add_temp("apply/strength", str*2);
	me->add_temp("apply/dexerity", dex*2);
	me->set_temp("leidong", 1);
	skill=(me->query_skill("pishi-poyu",1)+me->query_skill("huashan-shenfa",1)) / 2;

	me->start_call_out( (: call_other, __FILE__, "end_perform", me, str, dex:), skill/8);

	me->add("neili", -lvl);
	me->add("jingli", -lvl);

//	if( me->query_temp("restore") ) me->prepare_skill("strike", "hunyuan-zhang");

	return 1;
}

void end_perform( object me, int str, int dex)
{
	me->add_temp("apply/strength", -str*2);
	me->add_temp("apply/dexerity", -dex*2);
	me->delete_temp("leidong");

	tell_object(me, "�㻺������һ���������ھ��ջص��\n");
}	
