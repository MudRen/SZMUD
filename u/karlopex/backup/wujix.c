// Code of Shenzhou
// creat by Karlopex@sz
/*************************************************************************************
perform wuji ���������޼�����--�и����ڳ���֮ͨǰһ����Ҫ������pfm�����ٹ���һ�У������޴󣬵���������ͬ���޴�
����������ȭ�ȼ�200�����칦�ȼ�200����ע��������Ч�ȼ���
���ܣ�����20% attack
���ƣ�ֻ����pfm sanhua ���� perform yanwu֮һ���ʹ�á�
      �����޴�busyʱ���Գ� 20 tick +����ս��������
      �������������������ȡ�����Խ����������Խ�ࡣskill*2
������$1�������칦֮�����ھ���̫��Ѩ�߸߹�������𲭣�����ȭ�о������������죬�Ӳ���˼�鷽λ��$1����һ�С�
***************************************************************************************/               
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string weapon;
	int max_times, st_lvl;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������޼���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������޼�������ֲ���ʩչ��\n");

	if( me->query_skill_mapped("cuff") != "chunyang-quan" )
		return notify_fail("�����õĲ��Ǵ���ȭ������ʩչ�������޼�����\n");

	if( me->query_temp("cyq-wuji",1) )
		return notify_fail("������ʹ�á������޼�������Ĺ��������ٴݶ��������޼�����\n");
		
	if( me->query_skill_prepared("cuff") != "chunyang-quan" )
		return notify_fail("�������Ĳ��Ǵ���ȭ������ʩչ�������޼�����\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("�����õĲ����������칦��ʩչ�����������޼�����\n");

	if( me->query_skill("xiantian-gong",1) < 199 )
		return notify_fail("����������칦���δ�����޷�ʩչ�������޼�����\n");

	if( me->query_skill("chunyang-quan", 1) < 199 )
		return notify_fail("�������޼�����Ҫ��տ�Ĵ���ȭ������Чʩչ��\n");

	if( me->query("neili") <= 200 )
		return notify_fail("�����������ʹ�á������޼�����\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ�á������޼�����\n");

	skill = me->query_skill("force")/2 + me->query_skill("cuff") / 2;
	st_lvl = me->query("shentong");
	if (st_lvl > 60) st_lvl -= 60;
	else st_lvl = 0;
	max_times = skill / 100 + st_lvl / 2;
	if (max_times > 10) max_times = 10;
	if( skill > 1000 ) skill = 1000;
	me->set_temp("cyq-wuji/old_attack",me->query_temp("apply/attack"));
	me->set_temp("cyq-wuji/old_damage",me->query_temp("apply/damage"));
	me->set_temp("cyq-wuji/old_speed",me->query_temp("apply/speed"));
	message_vision(HIR "\n\n$N�������칦֮�����ھ���̫��Ѩ�߸߹�������𲭣�����ȭ�о������������졣\n\n"NOR, me, target);
	me->add_temp("apply/attack" , skill / 10);
	me->add_temp("apply/damage" , skill / 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->set_temp("cyq-wuji/max_times",max_times);
	me->set_temp("perform/chunyangwuji", 1);	
	tell_object(me,HIG"������"+chinese_number(max_times)+"�С������޼�����\n"NOR);
	return 1;
}
