// Cracked by Jiuer
// huakai.c ����֮���������١�
// xQin 11/00
// by snowyu ������������

//�޸�����, ������, �ɹ���, ����ʧ�ܵĶ���, �Լ�˫���ƺ������

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{       
        string msg;
        int damage, tjsg, mz, nl, skill;        
        if( !target ) target = offensive_target(me);
        
        if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target)
    ||  !target->is_fighting(me))
        return notify_fail("��������ֻ�ܴ���ս���еĶ��֡�\n");
                
	if( me->query_temp("yield") )
                return notify_fail("�㲻���ƣ���ô�ܳ����������١���\n");

        if( me->query_temp("huakai"))
                return notify_fail("���Ѿ��ڳ����������١��ˡ�\n");
        
	if( !living(target) )
                return notify_fail("������������ô��������\n");                

        if( objectp(me->query_temp("weapon")) ) 
                return notify_fail("���ֲ���ʩչ�������٣�\n");
        
        if( me->query_skill_mapped("strike") != "mian-zhang" )
                return notify_fail("�����õĲ��ǻ������٣�����ʩչ�������٣�\n");

        if( me->query_skill_prepared("strike") != "mian-zhang" )
        return notify_fail("�������Ĳ��ǻ������٣�����ʩչ�������٣�\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )   // i add
                return notify_fail("�����õĲ���̫���񹦣�ʹ�����������٣�\n");

        if( me->query_skill("mian-zhang", 1) < 99)
                return notify_fail("������Ʋ������죬��δ�ܳ��˾��С�\n");
        
        if( me->query_skill("taiji-shengong", 1) < 79)
                return notify_fail("���̫������Ϊ���������ܳ����������١���\n");
        if (me->query("max_neili") < 500)
                return notify_fail("���������Ϊ����,�޷�ʹ�á��������١�\n");
        if (me->query("neili") < 300)
                return notify_fail("�����������,�޷�ʹ�á��������١�\n");
        if( (int)me->query("jiali") > 2 || (int)me->query("jiajin") > 2)
                return notify_fail("�㷢�ּ������޷����������������ޣ�����������Ҫ�����ӳ�����\n");
//        msg = HIM "\n$Nһ�С��������١����ֻ����ͻ�$n���Ҽգ����ֳ�ָ����$n�ġ�ȱ��Ѩ����\n"NOR;
//        msg += "��һ�ơ��������١��������ڹ���ʽ΢ת�����Ʒ��������������ĵ�����ɻ����衣\n\n";
		msg = HIW"\n$N˫��һ����ʹ��һ�С����֡���˫���ᵽ�˼������������飬��$n�����ç��������ȥ��\nͬʱ������ȴ�ѽ���δ�á����ֽ�������λ���ٽ�����λ�����ơ����Ƽ��ա��������ӳ���\n$nֻ��һ�ɾ���������������ò�Ծ���벽��ת�����ơ�\n\n"NOR;
		
		msg += HIY"�����ţ�$N���̼��ˡ���������˫��ͬʱ��Ԫ��һ��$n���㸴�����ƣ���󲻽⣬ȷ�Ѳ���ϸ�룬\n���һ����$N������$N���̲ɵ������ƣ�����ȴ�������ƣ����ȡ����ƶϷ塹���ӵ�ɨȥ��\n$nһ��������ӿ�����Ȼ��$N���롰�ϡ�λ��$n�����ã��ز��ã���ʱ�����ն�֮����\n\n"NOR;
		msg += HIC"$N����һ���������������ƣ�������$n�Ŀ�ֱֱ�ĳ����ڼ����������ƿ�֮�������ƶ�����\n"NOR;
		msg += HIW"���Թ����أ������յУ�������������֮�ɣ�����Ի�������˵У��Ʒ��а�������ɱ�У�\n��һ·��ʽ�������䵱��ѧ" + HIM + "���������١���\n\n"NOR;


        message_vision(msg, me, target); 
        
        if( !me->is_fighting(target) || !target->is_fighting(me) || !living(target) ) 
        {       
                remove_effect(me);
		if (wizardp(me))
			tell_object(me,HIR"attack!!\n"NOR);
                return;
        }
	else 
	{
		tjsg = (int)me->query_skill("taiji-shengong");
		mz = (int)me->query_skill("strike");
		nl = (int)me->query("neili");

		if( me->query("combat_exp") > target->query("combat_exp") * 2)
		{
			damage = mz * 3 + tjsg * 3 + random(400);

			message_vision(HIR"$nֻ�����޿��ˣ����޿ɱܣ�ͻ�������������һ�ߣ�������������\n"NOR, me, target);
			message_vision(HIR"$N��$n����������������Ƶ����ƶ�Ȼ�ĳ���������������$n��磬ͬʱ����Ҳ�Թ���������$n�ؿڡ�ֻ��һ�����죬$n���ֱ�ɳ�����֮Զ��\n"NOR, me, target);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/2, me);
			target->add("neili", -(damage/3));
			COMBAT_D->report_status(target);
			me->add("neili", -200 + random(40));
			target->start_busy(random(2));
			me->start_busy(1 + random(2));
		}

		else if( me->query_skill("force") * me->query("neili") / 100 > target->query_skill("force") * target->query("neili") / 250)
		{
			damage = mz*2 + tjsg*2 + random(300);

			message_vision(HIY"$nֻ�����޿��ˣ����޿ɱܣ�ֻ���˹�Ӳͦ���ɱ�С�$N��$n�����˲��ܣ����������١��ĵڶ���ɱ�о�Ҳ�޷�ʹ����\n"NOR, me, target);
			message_vision(HIR"$N��������$n�ؿڣ�ֻ��һ�����죬$nվ�����ȣ������������������վ����\n"NOR, me, target);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/2, me);
			target->add("neili", -(damage/3));
			COMBAT_D->report_status(target);
			me->add("neili", -damage/10);
			target->start_busy(1 + random(2));
			me->start_busy(1 + random(2));
		}

		else
		{
			switch(random(3))
			{
			case 0:
				message_vision(HIR"$nֻ�����޿��ˣ����޿ɱܣ�ֻ���˵�ȫ���ھ�������Ӳ�ӡ�\n"NOR, me, target);
				message_vision(HIR"һ������֮������ͬʱ���ɳ����������˵ò��ᡣ\n"NOR, me, target);
				
				target->receive_damage("qi", 200 + random(200), me);
				target->receive_wound("qi", 200 + random(200), me);
				target->add("neili", -200 + random(200));
				
				me->receive_damage("qi", 200 + random(200), me);
				me->receive_wound("qi", 200 + random(200), me);
				me->add("neili", -200 + random(200));

				COMBAT_D->report_status(target);
				COMBAT_D->report_status(me);
				me->add("neili", -damage/10);
				
				target->start_busy(2 + random(2));
				me->start_busy(2 + random(2));
				break;

			case 1:
				message_vision(HIR"$nֻ�����޿��ˣ����޿ɱܣ�ֻ���˵�ȫ���ھ�������Ӳ�ӡ�\n"NOR, me, target);
				message_vision(HIR"һ������֮������ͬʱ���ɳ����������˵ò��ᡣ\n"NOR, me, target);
				
				target->receive_damage("qi", 200 + random(200), me);
				target->receive_wound("qi", 200 + random(200), me);
				target->add("neili", -200 + random(200));
				
				me->receive_damage("qi", 200 + random(200), me);
				me->receive_wound("qi", 200 + random(200), me);
				me->add("neili", -200 + random(200));

				COMBAT_D->report_status(target);
				COMBAT_D->report_status(me);
				me->add("neili", -damage/10);

				target->start_busy(2 + random(2));
				me->start_busy(2 + random(2));
				break;
			case 2:
				message_vision(HIC"\nֻ�����޿��ˣ����޿ɱܣ�ֻ�ܾ͵��˵�����������������Ǳ�֮����$N����$n����������ʽ���������Ǻ��������Ǻ�Ц��ֻ�����ж��ˡ�\n"NOR, me, target );
				me->add("neili", -100);
				me->start_busy(2 + random(3));
				break;
			case 3:
				message_vision(HIC"\nֻ�����޿��ˣ����޿ɱܣ�ֻ�ܾ͵��˵�����������������Ǳ�֮����$N����$n����������ʽ���������Ǻ��������Ǻ�Ц��ֻ�����ж��ˡ�\n"NOR);
				me->add("neili", -100);
				me->start_busy(2 + random(3));
				break;
			}
		}
        me->add("neili", -50);
        me->add("jingli", -40);
        me->set_temp("huakai_target", target);
	skill = 400 - ((me->query_skill("mian-zhang",1)+me->query_skill("taiji-shengong",1)) / 4);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill / 30);
        me->set_temp("huakai", 1);
	if (wizardp(me))
                tell_object(me,HIR+"�����ʱʱ���� "+ skill/30 +"�롣\n"NOR);
	return 1;
	}
}

void remove_effect(object me)
{
	object target;

	if( me->query_temp("huakai") )
	{
		target = me->query_temp("huakai_target");
		me->delete_temp("huakai");
		if( me->is_fighting() )
		{
			if(!living(target))
				message_vision(HIY "\n$n�Ѿ������ֿ�$P�������ٵ��Ʒ硣\n" NOR, me, target);
			else message_vision(HIY "\n$n��������Ӧ��$P�������ٵ��Ʒ硣\n" NOR, me, target);
		}else message_vision(HIY "\n$P�������е������ջص��\n" NOR, me, target);
	}
}
