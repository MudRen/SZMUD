// Code of ShenZhou
// chan.c ̫�������������־�
// Modified by xQin 6/2000

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, msg1, msg2, msg3, *chan_msg, *chaned_msg, *dodged_msg;
	object weapon, weapon2;
	int foo;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
	weapon2 = target->query_temp("weapon");

	if( !living(target) )
		return notify_fail("�����ڲ���ʹ�á������־���\n");

	if( !weapon || !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������ʹ�á������־���\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻����������ʹ�á������־���\n");

	if( me->query_temp("chan/"+target->name()) )
		return notify_fail("���Ѿ�ǣ��ס"+ target->name() +"�ˣ��ŵ������ɡ�\n");

	if( (int)me->query_skill("taiji-jian", 1) < 100 )
		return notify_fail("���̫��������������죬ʹ�����������־���\n");

	if( (int)me->query_skill("taiji-shengong", 1) < 80 )
		return notify_fail("���̫������Ϊ������ʹ�����������־���\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����ڵ������������˾���Ȧ��\n");

	if( me->query("jingli") <= 100 )
		return notify_fail("�����ڵ������������˾���Ȧ��\n");

	if( me->query_skill_mapped("parry") != "taiji-jian" )
		return notify_fail("�������޷�ʹ�á������־���\n");

	if( me->query_skill_mapped("force") != "taiji-shengong")
		return notify_fail("�����õ��ڹ���̫��������·��㣣�\n");

	me->add("neili", -50);
	me->add("jingli", -50);

	if( objectp(weapon2) )
	{
		msg1 = "��$w"CYN"֮��";
		msg2 = "$w"CYN;
		msg3 = "����$w"CYN"���Ʋ��ϵ�������������������߽��ʮ���ʮ���\n";
	}
	else
	{
		msg1 = "ס$n";
		msg2 = "$n";
		msg3 = "";
	}

	chan_msg = ({
		CYN"\n$N��һ��$W"CYN"�ڻ���һ����ԲȦ��ÿһ�о����Ի��δ̳����Ի����ջء�\n"NOR,
		CYN"\n$N���о��ް�����ң������˽���$W"CYN"ÿ��һ�У����Ʒų�һ��ϸ˿��Ҫȥ��"+msg1+"��\n"NOR,
		CYN"\n$N�ֽ���Բ����·̫������ֻ�Ǵ��СС������бֱ���ָ�����ԲȦ��Ҫ˵��������˵ֻ��һ�У�Ȼ����һ��ȴ����Ӧ�����\n"NOR,
	});

	chaned_msg = ({
		CYN"$W"CYN"������ϸ˿Խ��Խ�࣬���ǻ�����һ����˿�࣬��"+msg2+"����������\n"NOR,
		CYN"$n����������ɬ�ͣ�"+msg3+"ż��һ�з����������˵ò��㣬�㱻$W"CYN"������ת����Ȧ�ӡ�\n"NOR,
		CYN"$nԽ��Խ�Ǻ��£�$P����������һ�Ŵ��������������ս���\n"NOR,
	});

	dodged_msg = ({
		HIR"����$n��Ȼ������$P�����������¹�עһ����Ǭ��һ������\n"NOR,
		HIR"$n΢������ɬ�ͣ���æ���У��߾�ȫ��֮���й��������ӽ���Ȧ�й��˽�ȥ��\n"NOR,
	});

	msg = chan_msg[random(sizeof(chan_msg))];

	foo = me->query_temp("taiji") ? 250 : 200;
	if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / foo )
	{
		msg += chaned_msg[random(sizeof(chaned_msg))];
		target->start_busy(2);
		target->set_temp("guarding", 0);

		if( !me->query_temp("guarding") )
                	me->set_temp("guarding", 1);
		me->add_temp("chan/"+target->name(), 1);
		call_out("chan_checking", 1, me, target);

		msg = replace_string(msg, "$W", weapon->name());
		if( objectp(weapon2) )
			msg = replace_string(msg, "$w", weapon2->name());

		message_vision(msg, me, target);
		return 1;
	}
	else
	{
		msg = replace_string(msg, "$W", weapon->name());
		if( objectp(weapon2) )
			msg = replace_string(msg, "$w", weapon2->name());

		message_vision(msg+dodged_msg[random(sizeof(dodged_msg))], me, target);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"));

		message_vision(HIR"\n$P�������Ͷ񣬻ؽ�����ȴ��$p����һԾ�����ӳ�Ȧ�⡣\n"NOR, me, target);
		me->start_busy(random(3));
		return 1;
	}
}

void chan_checking(object me, object target)
{
        object weapon;
        if (me) weapon = me->query_temp("weapon");

//	if( !me->query_temp("chan/"+target->name()) ) return;

	if( !me ) return;

	if( !me->is_fighting() || !living(me) || me->is_ghost() )
	{
		me->delete_temp("chan");
		return;
	}
	else if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
	{
		me->delete_temp("chan");
		me->start_busy(1);
		message_vision(CYN "\n$N�����޽��������ʧ��\n"NOR, me);
		return;
	}
	else if( me->query_skill_mapped("sword") != "taiji-jian"
	|| me->query_skill_mapped("parry") != "taiji-jian" )
	{
		me->delete_temp("chan");
		me->start_busy(1);
		message_vision(CYN "\n$NȦת" + weapon->name()+ CYN
		"��ͻȻ���У�ʹ����̫�����ⲻͬ�Ľ�����\n"NOR, me);
		return;
	}
	else if( me->query("neili") <= 100 )
	{
		me->delete_temp("chan");
		me->start_busy(1);
		message_vision(CYN "\n$Nż��һ���̳���Ȼ�޷�Բת���⣬ԭ�������������ˣ�\n"NOR,me);
		return;
	}           

	call_out("chan_checking", 1, me, target);
}       
