// Code of ShenZhou
//�����޳�ն
// by xiaojian Jan 15,2001
#include <ansi.h>
#define BASE_WEIGHT 1000		
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");
	int lvl, amount, str,weight,weight1;
	
	if( !target ) target = offensive_target(me);
	else me->set_temp("offensive_target", target);

	if (! wizardp(me)) 
		return notify_fail("Ŀǰ�⹦�ܻ������ţ�\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����޳�նֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("sl_xiuluo") )
		return notify_fail("���Ѿ�ʩչ�������޳�ն�ˣ�\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("����������ʹ�Ž�շ�ħ���ڼ���ͨ���޷�ͬʱʩչ�����޳�ն��\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 200 )
		return notify_fail("��Ļ�Ԫһ�������δ��������ʩչ�����޳�ն��\n");

	if( me->query_skill("buddhism", 1) < 200 )
		return notify_fail("��������ķ��������޷���������޳�ն��\n");

	if( me->query_skill("blade", 1) < 200 )
		return notify_fail("��0�Ļ���������δ���죬�޷�ʩչ�����޳�ն��\n");

	if( me->query_skill("xiuluo-dao", 1) < 200 )
		return notify_fail("������޵�����Ϊ���㣬�޷�ʩչ�������޳�ն��\n");

	if( me->query_skill_mapped("force") != "hunyuan-yiqi")
		return notify_fail("������ʹ���ڹ����ǻ�Ԫһ�������޷�ʩչ�����޳�ն��\n");
    if( me->query_str() < 45 )
        return notify_fail("��ı���������ʹ�������޳�ն��\n");


	if( me->query("neili") <= 500 )
		return notify_fail("�������������ʩչ�����޳�ն��\n");

	if( me->query("jingli") <= 250 )
		return notify_fail("��ľ���������ʩչ�����޳�ն��\n");

	if( (me->query_temp("weapon"))->query("skill_type") != "blade" )
		return notify_fail("�������޵�����ôʩչ�����޳�ն��\n");
	weight = weapon->query_weight();
	weight1 = weight/BASE_WEIGHT;
	if (weight1 <= 1)
	weight1 = 1;
	lvl = (int)me->query_skill("blade", 1); 
	str = me->query_str();
	amount = lvl*2/3;
	message_vision(HIR "\n$N���һ��,����һ����������Ծ���������ó�һƬ��Ӱ�Ӱ����ֱ��������\n" NOR,me);
	message_vision(YEL"ֻ��������������������������ߣ��������ǳ�ɳ����ܲ���Ҷ�����缤�����Ŷ��裬�˵�����������!\n" NOR,me);
	message_vision(HIG"ɲ�Ǽ�$n�ѱ�����һ��̹ǵĵ���֮�У����ɵõ�����һ��������\n" NOR,me,target);

	me->set_temp("sl_xiuluo", 1);
	me->add_temp("apply/attack", (amount + weight1));
	me->add_temp("apply/damage", amount);
	if (wizardp(me))  
       tell_object(me, sprintf("lvl=%d, weight=%d, str=%d, attack=%d,damage = %d\n", lvl, weight1, str, (amount+weight1),(amount+str)));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	//add more damage to 2nd hit
	me->add_temp("apply/damage",str);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add("neili", -350);
	me->add("jingli", -150);
	me->add_temp("apply/attack", -(amount + weight1));
	me->add_temp("apply/damage", -(amount + str));
	me->delete_temp("sl_xiuluo");
	me->start_busy(2+random(1));
		return 1;
}

