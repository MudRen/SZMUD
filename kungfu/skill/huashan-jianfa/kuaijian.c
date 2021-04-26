/*
���콣

�ⲻƽ����һ����Х��б�ж�ǰ����������ֱ����Ѹ���ޱȣ�δ�������У��������ѷ�������������
�ⲻƽ��һ��������ʱ�����߽���һ������һ����������װ㹥�ϡ�
�ⲻƽ����һ�죬һ��������ʹ�����缲������һ�㡣
�ⲻƽ���������������Σ���Щ���Լ��ұ����ն�䣬ʵ������֮��
*/
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

void force_finish(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);
void check_attack(object me, object target, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);
void remove_effect(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);

int perform(object me, object target)
{
        object weapon, weapon1 ;
        string msg;
        int level, mem_speed, mem_attack, mem_damage, attack, damage, speed;
        object tester = find_player("snowyu");

        if (!target) target = offensive_target(me);

        
		weapon = me->query_temp("weapon");

//         if(me->query("huashan_kuaijian")!=1 && !wizardp(me))
//                 return notify_fail(HIC "��Ϊ������ָ�㻹����ʹ�á����콣����\n"NOR);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC "�����콣��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

		if ( me->query("family/family_name") != "��ɽ��" && (!wizardp(me)) )
                return notify_fail(HIC "��ǻ�ɽ���ӣ����ʹ�û�ɽ���ھ�ѧ��\n"NOR);

        if( me->query_temp("kuaijian",1) )
                return notify_fail(HIC "������ʹ�á����콣����\n"NOR);
        if( me->query_temp("yijian",1) )
                return notify_fail(HIC "������ʹ�á�����һ������\n"NOR);
        if( me->query_temp("sanxianjian",1) )
                return notify_fail(HIC "������ʹ�á������������ɽ�����\n"NOR);
        if( me->query_skill_mapped("force") != "zixia-gong" && !wizardp(me))
                return notify_fail(HIC "�����õĲ�����ϼ�񹦣��޷�ʩչ�����콣����\n"NOR);
		
		if( me->query_skill("ziyin-yin",1) <101 )
                return notify_fail(HIC "���������Ϊ���㣬������ʹ�á����콣����\n"NOR);

		if( me->query_skill("zhengqi-jue",1) <101 )
                return notify_fail(HIC "�����������Ϊ���㣬������ʹ�á����콣����\n"NOR);

        if( me->query_skill("zixia-gong", 1 ) < 120 )
                return notify_fail(HIC "�����ϼ�񹦻��δ�����޷�ʩչ�����콣����\n"NOR);

	    if( me->query_skill_mapped("parry") != "huashan-jianfa" )
                return notify_fail(HIC "��û�н���ɽ�����������м��У��޷�ʩչ�����콣����\n"NOR);

        if( (level = (int)me->query_skill("huashan-jianfa", 1)) < 120 )
                return notify_fail(HIC "��Ļ�ɽ������Ϊ���㣬������ʹ�á����콣����\n"NOR);
		
		if( me->query("neili") <= 800)
                return notify_fail(HIC "�����������ʹ�á����콣����\n"NOR);
        
		if( me->query("jingli") <= 800 )
                return notify_fail(HIC "��ľ�������ʹ�á����콣����\n"NOR);
       
        if( me->query_str() < 35 ) 
			   return notify_fail(HIC "�����������������޷��˽��ɷ磡\n" NOR);

        if( me->query_con() < 35 ) 
			   return notify_fail(HIC "�������������޷��˽��ɷ磡\n" NOR);
        
		if( me->query_dex() < 35 ) 
			   return notify_fail(HIC "�����δ��֣��޷��˽��ɷ磡\n" NOR);

		
        
        message_vision(HIR"$N����һ����Х��б�ж�ǰ��"+ weapon->name() +HIR"����ֱ����Ѹ���ޱȣ��������ѷ�����������,���ǻ�ɽ���ھ�ѧ�����콣��!\n" NOR, me);

        level = (int)me->query_skill("huashan-jianfa", 1); 
        mem_attack = (int)me->query_temp("apply/attack",1);
        mem_damage = (int)me->query_temp("apply/damage",1);
        mem_speed = (int)me->query_temp("apply/speed",1);
        speed = level/2 + random(level/2); // ���콣ǿ���ٶ�
        attack = level/5 + random(level/2);
        damage = level/5 + random(level/2);
        me->add("neili", -500);
        me->add("jingli", -300);
        me->set_temp("kuaijian", 1);
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/speed", speed);
        //�����
        if (wizardp(me)) 
	    tell_object(me, sprintf(WHT"ԭ����������%d��ԭ�������ʣ�%d��ԭ���ٶȣ�%d�����ӹ�������%d�����������ʣ�%d�������ٶȣ�%d��\n"NOR, mem_damage, mem_attack, mem_speed, damage, attack, speed));

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("kuaijian", 2);
        me->start_call_out( (: call_other, __FILE__, "check_attack", me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 1);
        me->start_call_out( (: call_other, __FILE__, "force_finish", me, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 14);
        return 1;
}
void force_finish(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
        if (wizardp(me)) tell_object(me, "ǿ��ֹͣ\n");
        if (me->query_temp("kuaijian"))
        {
                
                me->delete_temp("kuaijian");
                me->add_temp("apply/speed", -speed);
                me->add_temp("apply/attack", -attack);
                me->add_temp("apply/damage", -damage);
                me->start_busy(1);
                
                if (wizardp(me)) tell_object(me, sprintf(WHT "���ں�ԭ����������%d��ԭ�������ʣ�%d��ԭ���ٶȣ�%d��Ŀǰ��������%d��Ŀǰ�����ʣ�%d��Ŀǰ�ٶȣ�%d��\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
                if((int)me->query_temp("apply/speed",1) != mem_speed)
                {
                        me->set_temp("apply/speed",mem_speed);
                }
                if((int)me->query_temp("apply/attack",1) != mem_attack)
                {
                        me->set_temp("apply/attack",mem_attack);
                }
                if((int)me->query_temp("apply/damage",1) != mem_damage)
                {
                        me->set_temp("apply/damage",mem_damage);
                }
                if (wizardp(me)) 
				tell_object(me, sprintf(WHT "�ٵ��ڣ�ԭ����������%d��ԭ�������ʣ�%d��ԭ���ٶȣ�%d��Ŀǰ��������%d��Ŀǰ�����ʣ�%d��Ŀǰ�ٶȣ�%d��\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
        }
}
void check_attack(object me, object target, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
        int used, max_use;
        max_use = 1 + (int)me->query_skill("huashan-jianfa", 1)/80;
        used = me->query_temp("kuaijian");

        if (!target || !me->is_fighting(target)) target = offensive_target(me);
        if (used > max_use || used > 5)
        {
                message_vision(HIC "\n$N����һ�����������������ջء�\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                me->start_busy(1);
               
                return;
        }
        if (!living(me) || me->is_ghost())
        {
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return ;
        }
        if( !me->is_fighting() )
        {
                message_vision(HIC "\n$N����һ�����������������ջء�\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
               

                return;
        }
        if (me->query_skill_mapped("force") != "zixia-gong")
        {
                message_vision(HIR "\n$N��;ת���ڹ��ķ���һ�����᲻������\n"NOR, me);
                message_vision(WHT "\n$N��ɫͻȻת�ף����ſ���"NOR MAG"��Ѫ"NOR WHT"��\n"NOR, me);
                me->receive_damage("qi", 800, "��Ѫ����");
                me->receive_damage("jingli", 1000, "��Ѫ����");
                me->add("eff_qi",-300);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return;
        }
        
        if (me->query_skill_mapped("dodge") != "huashan-shenfa" && "dugu-jiujian")
        {
                message_vision(WHT "\n$N�Ų�һ�����ȣ�ֻ����Ѫ��˳��ֻ���ջؽ��ơ�\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return;
        }
        if (me->query("neili") < 100)
        {
                message_vision(WHT "\n$N�о�����Ѫ��˳��һ�����᲻������ֻ���ջؽ��ơ�\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return;
        }
        if (!me->query_temp("kuaijian"))
        {
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                message_vision(HIC "\n$N����һ�����������������ջء�\n"NOR, me);
                return;
        }
        call_out("check_attack", 1, me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed);

        return;
}       
void remove_effect(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
        if (!me) return;
        me->delete_temp("kuaijian");
        me->add_temp("apply/speed", -speed);
        me->add_temp("apply/attack", -attack);
        me->add_temp("apply/damage", -damage);
        if (wizardp(me)) tell_object(me, sprintf(WHT "ԭ����������%d��ԭ�������ʣ�%d��ԭ���ٶȣ�%d��Ŀǰ��������%d��Ŀǰ�����ʣ�%d��Ŀǰ�ٶȣ�%d��\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
        if((int)me->query_temp("apply/speed",1) != mem_speed)
        {
                me->set_temp("apply/speed",mem_speed);
        }
        if((int)me->query_temp("apply/attack",1) != mem_attack)
        {
                me->set_temp("apply/attack",mem_attack);
        }
        if((int)me->query_temp("apply/damage",1) != mem_damage)
        {
                me->set_temp("apply/damage",mem_damage);
        }
        if (wizardp(me)) tell_object(me, sprintf(WHT "�ٵ��ڣ�ԭ����������%d��ԭ�������ʣ�%d��ԭ���ٶȣ�%d��Ŀǰ��������%d��Ŀǰ�����ʣ�%d��Ŀǰ�ٶȣ�%d��\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
        me->start_busy(1);
}
