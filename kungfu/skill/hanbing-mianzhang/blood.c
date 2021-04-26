// Code of ShenZhou
// blood.c ��Ѫ
// zhangchi 8/00

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;

        if( !target ) target = offensive_target(me);

        if( !target || !living(target))
                return notify_fail("��Ҫ��˭��Ѫ��\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�˼�ֻ�ܿ������á�\n");

        if( environment(target)->query("no_fight") )
                return notify_fail("�������㲻��͵Ϯ��\n");

        if( me->query_dex() < 30 )
                return notify_fail("�����������ʩչ�˼���\n");

        if( me->query_skill_mapped("force") != "shenghuo-xuanming" )
                return notify_fail("�����õĲ���ʥ����ڤ�����޷�ʩչ�˼���\n");

        if( me->query_skill_mapped("dodge") != "qingfu-shenfa" )
                return notify_fail("�㲢δ�߱������������ʩչ�˼���\n");

        if( me->query_skill("force") < 135 )
                return notify_fail("����ڹ����δ�����޷�ʩչ�˼���\n");

        if( me->query_skill("qingfu-shenfa") < 100 )
                return notify_fail("����������Ϊ���㣬������ʹ�ô˼���\n");

        if( me->query("neili") < 1000)
                return notify_fail("�������������\n");

        message_vision(HIB "$N��ɫ���ɷ�ף�ͻȻ�۵�$n��ߣ�����ͳ�$n����ҧȥ����\n\n" NOR, me, target);

	target->kill_ob(me);	

	if ( me->query_dex() > random(target->query_dex()*2)
	&&   me->query("neili") > random(target->query("neili")*2)
	&&   me->query("jingli") > random(target->query("jingli")*2) )
	{	// 50% * 50% * 50% = 12.5% chance between 2 identical players.
		message_vision(HIR"���һ����ҧ��$n�ľ��࣬����������һ����Ѫ��ʱ��$N��������������ɭ�ɲ���\n\n"NOR,me,target);
		
		if ( me->query("combat_exp") > random(target->query("combat_exp")*10) )		// low chance
		{
message_vision(HIR"ֻ��$N�ĸ���΢΢����Ȼ��ſ�$n���ٿ�ʱ��$n�Ѿ�Ѫ�����ɣ�����������\n"NOR,me,target);
			me->receive_curing("qi",target->query("max_qi")+100);
			me->add("qi",target->query("max_qi")+100);
			target->set("qi", -1);
			target->receive_wound("qi", target->query("max_qi")+100, "Ѫ�����ɶ���" );
		}
		else
		{
			message_vision(HIW"$nƴ����������������$N�Ŀ��ƣ������˼��أ���Ѫ�Ӿ�������������\n"NOR,me,target);
			me->receive_curing("qi",target->query("max_qi")/3);
			me->add("qi",target->query("max_qi")/3);
			target->set("qi", 1000);
			target->receive_wound("qi", target->query("max_qi")/3, "Ѫ�����ɶ���" );
		}
		me->set_temp("blood_sucked",1);
		if (me->query("id") == "wei yixiao")
			me->apply_condition("wei_pk",100);
	}
	else	
	{
		message_vision(HIW"$n��֮�£���æ����㿪��$Nһ�����У����ں������ģ���ʱ���˼������£��������ˡ�\n"NOR,me,target);
		me->add("qi", me->query("max_qi")/10);
		me->receive_wound("qi", me->query("max_qi")/10, "������������");
	}

	me->add("neili", -200);
	me->add("jingli", -100);

        me->start_busy(2+random(3));

        return 1;
}
