// Code of ShenZhou
// shentong.c ���칦 ������ͨ��
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill, value, i, upv;

	//me = this_object();

	if( target == me)target=offensive_target(me);

	if( !target )target = offensive_target(me);
	if( !target )target = me->select_opponent();

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��������ͨ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	if( (int)me->query("neili") < 1000  )
	{
		 return notify_fail("�������������\n");
	}

	if( (int)me->query_temp("shentong") )
					 return notify_fail("���Ѿ����˹�\���ˡ�\n");
/*
	if( !target	||	!me->is_fighting() )
		return notify_fail("������ͨ��ֻ����ս���в���ʹ�á�\n");
*/

	if( me->query("shentong") < 60 )
		return notify_fail("�㻹δ��������ɴ�����ͨ����\n");

	if( me->query_skill("force") < 300 )
		return notify_fail("����������칦���δ�����޷�ʩչ������ͨ����\n");

	if( me->query_skill("taoism") < 90 )
		return notify_fail("��ĵ�ѧ�ķ����δ�����޷�ʩչ������ͨ����\n");



	message_vision(	HIW "$N��������ͨ����Ƭ��֮�䣬��������ȫ����˫�۾������䣬���ַ���ý����������٣���ƽʱ�������ˡ�\n" NOR, me);
	message_vision(	HIG "\n�㲻�����죬�ѵ�������������������֣���������޵��ֵĲ���������������ͨ������˵������ȫ�����Ӻ��ܲ�ͨҲû���ɡ�\n" NOR, me);
	
	skill = me->query_skill("force");
	me->add("neili", -skill*3);
	
	me->set("jiali",0);
	value = skill * random(me->query("shentong")*5);

	if( value > 90000 ) value = 90000;
	if( value < 30000 ) value = 30000;
	if( me->query_skill("taoism") > 299 )
		i = (me->query_skill("taoism") - 300) / 10;
	if (i > 0) upv = value * (100 + i * 2) /100;
	else upv = value;
	//	disabled adding jingli since player exploiting this to add max jingli
	me->add( "jingli",value  );
	me->add_temp( "apply/attack",upv / 500  );
	me->set_temp("shentong", 1);
	
	
	if( me->is_fighting() ){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->start_busy(1+random(3));
	}
	
	me->add( "jingli", -value );
	me->add_temp( "apply/attack",-upv / 500  );
	me->delete_temp("shentong", 1);
	
	return 1;
}