// Code of ShenZhou
// canshang.c ���������
//Sure 2001.5

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform( object me, object target)
{
	int lvl, str, dex, skill;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ָֻ�ܶ�ս���еĶ���ʹ�ã�\n");

	if( me->query_temp("canshang") )
                return notify_fail("���Ѿ���ʹ�ò���ָ���ˣ�\n");

	if( objectp(me->query_temp("weapon")) )
			return notify_fail("����ָ��Ҫ����ֲ���ʩչ��\n");

	if( me->query_skill_mapped("finger") != "canhe-zhi" )
		return notify_fail("����ʹ�õĲ��ǲκ�ָ������ʩչ����ָ����\n");

	if( me->query_skill_prepared("finger") != "canhe-zhi" )
		return notify_fail("�������Ĳ��ǲκ�ָ������ʩչ����ָ����\n");

	if( me->query_skill_mapped("force") != "douzhuan-xingyi" )
		return notify_fail("�����������ڹ����Ƕ�ת���ƣ�ʩչ��������ָ����\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("����ڹ���򲻵����޷�ʩչĽ�ݼҴ���ѧ��\n");

//	if( me->query_skill("literate") < 100 )
//		return notify_fail("��Ĳ�ѧ���������򵽾���Ĳκ�ָ����\n");

	if( me->query_int() < 22 )
		return notify_fail("�������̫�����ʩչ����Ľ�ݼҴ���ѧ��\n");

	if( (lvl=me->query_skill("finger"))< 100 )
		return notify_fail("����ָ����Ҫ�����ָ��������Ч��\n");

	if( me->query("neili") <= lvl*1.5 )
		return notify_fail("�������������ʹ��Ľ�ݾ�ѧ����ָ����\n");

	message_vision(HIM "$N����Ĭ���������̡���������ת������������ֻ���������ƿ�֮���������죡\n"
	+"��������һ�ɽ���ֱ��$n��ȥ��\n" NOR, me, target);
	str = me->query_str();
	dex = me->query_dex();
	me->add_temp("apply/strength",str*3);
	me->add_temp("apply/dexerity",dex*3);
	me->set_temp("canshang", 1);

skill=(me->query_skill("canhe-zhi",1)+me->query_skill("murong-shenfa" ,1)) / 2;

	me->start_call_out( (: call_other, __FILE__, "end_perform", me, str, dex :),skill/8);

	me->add("neili", -lvl);
	me->add("jingli", -lvl);
	return 1;
}

void end_perform( object me, int str, int dex)
{
	me->add_temp("apply/strength", -str*3);
	me->add_temp("apply/dexerity", -dex*3);
	me->delete_temp("canshang");

	tell_object(me, HIY "�㻺����ס���Σ�����һ�������������ջص��\n" NOR);
}
