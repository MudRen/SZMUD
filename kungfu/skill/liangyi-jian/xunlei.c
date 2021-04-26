// Code of ShenZhou
//Revised by earl
//Sep 6 9
//xunlei.c Ѹ�׽�

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
          int speed, attack, lv, damage;

           lv = (int)me->query_skill("liangyi-jian", 1); 
           damage = lv + random(lv/2) + (int)me->query_skill("sword",1);
                      attack = lv + random(lv/2);
                         speed = me->query_skill("sword")/80;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
	     return notify_fail("��Ѹ�׽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("xunlei_yushi"))
	     return notify_fail("�㽣��δ����������ʩչ��Ѹ�׽�����\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
	     return notify_fail("��ʹ�õ��������ԡ�\n");

          if( (int)me->query("neili") < 300 )
	     return notify_fail("�������������\n");

        if( me->query_skill("liangyi-jian", 1) < 100 )
	     return notify_fail("��ġ����ǽ�����δ�����磬�޷�ʹ�á�Ѹ�׽�����\n");
        if( me->query_skill("xuantian-wuji", 1) < 100 )
             return notify_fail("��������޼���Ϊ�������޷�ʹ�á�Ѹ�׽�����\n");

        msg = HIR "\n$N����"+weapon->query("name")+HIR"����ָ���Լ��ؿڣ�����бб���⣬����֮�������ƻؽ�����һ�㣡\n\n" NOR;
        message_vision(msg, me,target);
        me->start_busy(1);
        ob = me->select_opponent();
        me->delete_temp("xunlei");
        me->set_temp("xunlei",4);
          me->add("neili", -5);
        me->set_temp("xunlei_yushi");
        call_out("checking", 1, me, target);
        return 1;
}


  void checking(object me, object target, int speed, int damage, int attack)
{

        object weapon;
	if ( !objectp( me ) ) return;
        weapon = me->query_temp("weapon");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
		tell_object(me, "\n�������޽�������ֹͣ��Ѹ�׽��ļ��ơ�\n" NOR);
		me->delete_temp("xunlei");
		return;
	}
	else if ( weapon->query("weapon_prop") == 0 ) {
		tell_object(me, "\n���"+weapon->name()+"�ѻ٣��޷�����Ѹ�׽��Ĺ��ƣ�\n\n" NOR);
                    call_out("xunlei_end", 6, me);
		me->delete_temp("xunlei");
		return;
	}
          else if ( (int)me->query("neili") < 300  ) {
                  message_vision(HIR"$N���ھ�������������ò�ֹͣѸ�׽��Ĺ��ƣ�\n" NOR, me,target);
                    call_out("xunlei_end", 6, me);
		me->delete_temp("xunlei");
		return;
	}
	else if ( me->query_skill_mapped("sword") != "liangyi-jian" ) {
		tell_object(me, HIR "\n��ת��ʩչ�����������޷�����Ѹ�׽����У�\n\n" NOR);
                    call_out("xunlei_end", 6, me);
		me->delete_temp("xunlei");
		return;
	}
	else if ( me->is_busy() ) {
		tell_object(me, HIR "\n�����ڶ������ƣ��޷�����ά��Ѹ�׽����ƣ�\n\n" NOR);
                    call_out("xunlei_end", 6, me);
		me->delete_temp("xunlei");
		return;
	}
        else if (!me->is_fighting() || !objectp(target)) {
		tell_object(me,  "\n������û�к��˹��У������ջ���Ѹ�׽��Ĺ��ơ�\n" NOR);
                    call_out("xunlei_end", 6, me);
		me->delete_temp("xunlei");
		return;
	}
	if( environment(target) != environment(me) ) {
		tell_object(me, "����Է��Ѿ������������ֹͣ��Ѹ�׽��Ĺ��ơ�\n");
                    call_out("xunlei_end", 6, me);
		me->delete_temp("xunlei");
		return;
	}
         if ( me->query_temp("xunlei") ==4)message_vision(HIY"\n$N�����ǰ��"+weapon->name()+HIY"��Ȼ���䵯��������ֱ��$n������֮������Ϊ�κν�����������\n" NOR, me,target);
	{
		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		 me->add("neili", -5);
		 me->start_busy(1);
		target->start_busy(random(3));
		}
	
        if ( me->query_temp("xunlei") !=3 )message_vision(HIW"\n$N��ָ��"+weapon->name()+HIW"��һ�����������ˣ�����������"+weapon->name()+HIW"�������������������޷���\n" NOR, me,target);
        {        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        	 me->add("neili", -5);
        	 me->start_busy(1);
		target->start_busy(random(3));
		}
	        
	if ( me->query_temp("xunlei") ==4 )message_vision(HIG"\n$N��Ȼ����һ����"+weapon->name()+HIG"�Ϻ����������ȵ�����"+target->name()+HIG"����С���ˣ���\n" NOR, me,target);
	    message_vision(HIR"\n����$N���ֻӽ���"+weapon->name()+HIR"������ǰ�����ң�˲Ϣ֮���ѹ���������һʮ���У�\n" NOR, me,target);
            damage = (int)me->query_skill("liangyi-jian", 1)+ (int)me->query_skill("sword", 1);
           damage = random(damage)*2 + random(damage);
        {       me->start_busy(1+random(2));
                me->delete_temp("xunlei");
                call_out("xunlei_end", 12, me);
                me->start_busy(2);        	  
		target->start_busy(random(3));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));		
		target->receive_damage("qi", damage*2);
		target->receive_wound("qi", damage*3/2);
		target->add("neili", -damage/10);
		me->add("neili", -100);
        if ( damage < 300 ) message_vision(HIG"\n���$n���������ƣ������������˺ü�����\n"NOR,me,target);
        else if(damage < 400 ) message_vision(RED"\n�����$n�ѱ������Ѵ����ͷ���������\n"NOR,me,target);
	else if( damage < 500 ) message_vision(HIR"\n���$n�ѱ�����������������Ѫ���������\n"NOR,me,target);        
        else message_vision(HIR"\n$nֻ������һ���������Ѵ��ض�����\n"NOR,me,target);
        }			    
 }
void xunlei_end(object me)
{
        object weapon;
	if ( !objectp( me ) )
		return;
        weapon = me->query_temp("weapon");

        tell_object(me, HIR "\n�㰵�Ե�Ϣ������ƽ����ӿ��������\n\n" NOR);

        me->delete_temp("xunlei");
        me->delete_temp("xunlei_yushi");

}
