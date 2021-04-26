// Code of ShenZhou
///kungfu/skill/dagou-bang/sansha.c ����ɱ��
// Lara 2001/11/11
/* ����˺�ֵ�����޺�����
�޸ļ��㹫ʽ��ԭ����ֻ�������������ڸ�Ϊ���������Բ���
��΢��߹��������ϴ�������������
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int tempatt;
        int skill;
        int mybili;
        int mywx;
        int busytime;
        string* msgpfm,msg;
        string weapon;
        int damage;
        string *limb, type, result, str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
        if( me->query_temp("sansha_busy") )
                return notify_fail("����Ϣ���ڣ���ת������ʹ��������ɱ�У�\n");

		if( me->query("family/family_name") != "ؤ��" )
			return notify_fail("�㲻��ؤ����Ӳ���ʹ������ɱ�У�\n");

        if( target->is_busy() ) 
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

		if( me->query("rank") < 9)
			return notify_fail("��ļ��𲻹���û���ʸ�ʹ������ɱ�У�\n");

		weapon = me->query_temp("weapon");
		if( weapon->query("skill_type") != "stick" )
                return notify_fail("�������ް������ʹ������ɱ�У�\n");

        if( me->query_skill_mapped("stick") != "dagou-bang" )
                return notify_fail("�����õĲ��Ǵ򹷰�������ʩչ����ɱ�У�\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                                         return notify_fail("�����õĲ��ǻ���������ʩչ��������ɱ�У�\n");

        if( me->query_skill("force") < 300 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ����ɱ�У�\n");

        if( me->query_skill("stick") < 300 )
                return notify_fail("����ɱ����Ҫ��տ�Ĵ򹷰�������Чʩչ��\n");

        if(me->query_int() < 32)
                return notify_fail("������Բ������޷�ʹ������ɱ�У�\n");

        if( me->query("neili") <= 200 )
                return notify_fail("�����������ʹ������ɱ�У�\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ�������ʹ������ɱ�У�\n");
		
		msgpfm = ({
			"$Nŭ��һ�������"+ weapon->name()+HIG"һ�����Ծ����δ�������ȵ��������»�����ʩ����ɱ�֣�",
			"$Nת��"+ weapon->name()+HIG"��ˢˢˢ��������������������ף����Ǵ򹷰����е�ɱ�У�",
			"$NͻȻ�ɳ�"+ weapon->name()+HIG"��ӭ������$n������������£�������ʱ֮��ֵ�$p�ؿ�������Ѩ��",
			"$N����ӳ�������Ϊ�������ӳ��򹷰����еĹ��֣�����������ɱ�У�",
			});
		
		msg = HIG"\n"+ msgpfm[random(sizeof(msgpfm))] +"\n" NOR;
		message_vision(msg, me, target);

        skill = me->query_skill("stick");
        mybili = me->query_str();
        mywx = me->query_int();
        busytime = (skill/60) + ((mybili+mywx)/40) ;
        
        if(skill>400)skill=400;
        me->add_temp("apply/attack", ((mybili+mywx) * skill / 60));
		tempatt = (mybili+mywx) * skill / 60 ;
        me->set_temp("sansha",1);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->set_temp("restore",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack",-tempatt);

        call_out("remove_effect", busytime, me);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
		{
			damage = ((mybili+mywx) * (5 + (int)me->query_skill("stick")/80) ) ;
            if(damage > 2500) damage = 2500;
            if(damage < 500) damage = 500;

			target->receive_damage("qi", damage,  me);
            target->receive_wound("qi", (int)me->query_skill("stick"), me);
            target->start_busy(1);

			limb = target->query("limbs");
            type = "����";

			msgpfm = ({
			"���ۡ���һ�£������һ�����䲻�������$N��"+limb[random(sizeof(limb))]+"��$P���ɵòҽ�һ��������Ǳ���",
			"ֻ����������һ���ҽУ���һ�����صĴ���$N"+limb[random(sizeof(limb))]+"��$P��ʱ�а����飬��������ȫ��Ѫɫ��",
			});
	
			msg = HIG"\n"+ msgpfm[random(sizeof(msgpfm))] +"\n" NOR;
			message_vision(msg, target, me);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100            /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        }
        else if(   random(( target->query_str() )+ ( target->query_int() ))>  (mybili+mywx) )
        {
                message_vision(HIY"$N��������磬�Ͻ���ס�Ż���$n��Ȼһʱ���Թ��룬���б�б仯���顣\n\n"NOR, target,me );
                me->start_busy(3+(skill/100)+random(mybili/10));
//                me->receive_damage("qi", 10+random(20), me);
//                str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
//                message_vision("($N"+str+")\n", me);
        }
        else
        {
                message_vision(HIY "\n$N�󾪣�����"+ weapon->name()+HIY"������磬���޿ɵ������޿�����ֻ�����ܿ������С�\n\n" NOR,  target,me);
                target->start_busy(1+random(2));
                me->start_busy(1+random(2));
        }

        me->delete_temp("sansha");
        me->add("neili", -150);
        me->add("jingli", -100);
        me->start_busy(1+random(2) );
        me->set_temp("sansha_busy", 1); 

        return 1;
}


void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sansha_busy");
        tell_object(me, HIY"\n���ϢƬ�̣�������ת�ѻָ�˳����\n"NOR); 
}
