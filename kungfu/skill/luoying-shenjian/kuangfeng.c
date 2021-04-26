// Code of ShenZhou
//kuangfeng.c ������ 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int strike, extra, kick, power;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if ( me->query_temp("weapon") )
                return notify_fail("������������ַ���ʩչ��\n");
	
  	if( me->query_skill_mapped("strike") != "luoying-shenjian" )
                return notify_fail("�����õĲ�����Ӣ���ƣ�����������ɨҶ�����ʩչ������");

	if( me->query_skill_prepared("strike") != "luoying-shenjian" )
                return notify_fail("�������Ĳ�����Ӣ���ƣ�����������ɨҶ�����ʩչ������");

	if( me->query_skill_mapped("kick") != "xuanfeng-saoye" )
		return notify_fail("�����õĲ�������ɨҶ�ȣ���������Ӣ�������ʩչ��������\n");

	if( me->query_skill_prepared("kick") != "xuanfeng-saoye" )
                return notify_fail("�������Ĳ�������ɨҶ�ȣ���������Ӣ�������ʩչ��������\n");

        if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("�����õ��ڹ��롸���������ķ���㣣�\n");

	if( me->query_skill("bitao-xuangong", 1) < 80 )
		return notify_fail("��ı����������δ�����޷�ʩչ��������\n");

	if( me->query_skill("kick") < 135 )
		return notify_fail("��������Ҫ��տ������ɨҶ����ϣ�������Чʩչ��\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("����Ӣ������Ϊ���㣬������ʹ�ÿ�������\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ�ÿ�������\n");

		  if( me->query("jingli") <= 200 )
					 return notify_fail("��ľ�������ʹ�ÿ�������\n");

	message_vision(HIG "$Nһ����Х������������ʢ���۽�$n��ȥ��������Ӣ���ƺ��������������ɨҶ�ȣ�\n���ֿ�����ף���ͬ��纣�����$nϮ���������һ����Ŀ�������" NOR, me, target);

	strike = me->query_skill("strike")/6;
	kick = me->query_skill("kick")/6;
	power = strike + kick;
	if ( power > 150 ) power = 150;
	extra = (power*3 + random(power*3))/2;

   if(extra > 300 ) extra =300;

	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra/2);
	me->prepare_skill("kick");

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->prepare_skill("strike");

	me->prepare_skill("kick" , "xuanfeng-saoye");

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -100-random(power*3));
	me->add("jingli", -50-random(power*3));

	me->prepare_skill("strike", "luoying-shenjian");

	me->start_busy(1 + random(2));


	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra/2);
	return 1;
}
