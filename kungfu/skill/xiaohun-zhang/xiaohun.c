// xiaohun.c ��Ȼ����
// By liu 15/07/01

/*
��    �����֪������Ȼ���ң��ǵ��Ȳ��˹��壬���Լ���������ҲҪ����̨
�ϣ���Ȼ��С��Ů����һ�ۣ��е��������������ˣ����ˣ����Լ����ء�����
�ڴ�ʱ���������������������š�������������ң�û����ɵĻ�������
�ĳ�һ�ƣ�ֻ�����۵�һ������һ�����û��ڷ�����ͷ��
    ������̨���ܲ�ͨ�����е�������һ�С������ˮ�����������һ������
���Ѿ���ԭ���Լ���֪Ҫ����ʧ�����ǣ�����һ�У�ǡ��ʹ���ˡ���Ȼ�����ơ�
�еġ������ˮ���������Ʒ���ʹ�ۡ���ʹ�ƣ�ȫ���������ס��������򻨹�
�У��ܲ�ֻͨ���޴����飬��Ȼ�����������������򲻵����е���������
��С��Ů�ط꣬��·�Ʒ�����ʧȴ��Ч��ֱ���˿�������ͷ�������뵽��Ҫ��
С��Ů��������ʹ����֮�ʣ��⡰��Ȼ�����ơ��Ĵ��������ֲ�֪����������
������
    ���������Ȳ�ʤȯ��ͻȻ���ͷ���ƣ�����һ�Σ���ŭ����������������
�ϡ�����˲��ܿ������š��겻���ᡱ����������ʩ������������ʧ��������
���У�������һ�С���ʬ���⡱���߳�һ�š���һ�ŷ���ʱ�л��㱣�����Լ
Լ���������ޣ���������ܵù��ˣ����һ�죬�����ؿڡ��������һ����һ
����Ѫ��������¸�̨��

���е������Ƚϼ��ԣ�����liu�������ɣ���
*/

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int damage;
        object weapon,ob;
        int skill, jiali, my_rate, your_rate;

        skill = me->query_skill("xiaohun-zhang",1);
        jiali=(int)me->query("jiali");
        weapon = me->query_temp("weapon");
	

		if( !me->query("tempcut/xiaohun") )
				return notify_fail("Ŀǰ������������ţ���\n");

        if(me->is_busy())
                return notify_fail("������û�գ���\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����Ȼ���꡹ֻ����ս����ʹ�á�\n");

        if(me->query("spouse/id"))
                return notify_fail("���н���������ң��������򲻵�����Ȼ���꡹���е����\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ȼ���꡹ֻ�ܿ���ʹ�á�\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
                return notify_fail("�����Ů�ľ���Ϊ����������ʹ�á���Ȼ���꡹��\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" )
                return notify_fail("�����õĲ�����Ů�ľ���ʹ��������Ȼ���꡹��\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("�������������\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("xiaohun-zhang",1) < 150 )
                return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʹ�á���Ȼ���꡹��\n");

        if( jiali < 50 )
         return notify_fail("����Ȼ���꡹������ȫϵ�ڸ��������������ϲ�����������ʹ����\n");

        if(me->query("married_times"))
        msg = CYN "\n$N����˼���Լ������ӣ���ʹ����֮�ʲ�����Ȼ���¡�\n" NOR;
        if(!me->query("married_times"))
        msg = CYN "\n$N����˼���Լ��İ��ˣ���������ֹˮ��\n" NOR;

        msg += WHT "$N���һ��������Ȼ�����ơ������еı����밧Թ���ƾ���к��������ʱ��ؼ�һƬ��ɬ��\n"NOR;

        damage = random( me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
        if( me->query("eff_qi",1) < me->query("max_qi",1)/2 )
        damage = damage * 2;
        if( me->query("eff_qi",1) < me->query("max_qi",1)*2/3 )
        damage = damage * 2 / 3;

        if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
        {
/*
                damage = random( me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
                if( me->query("eff_qi",1) < me->query("max_qi",1)/2 )
                damage = damage * 2;
                if( me->query("eff_qi",1) < me->query("max_qi",1)*2/3 )
                damage = damage * 2 / 3;
*/

                if(damage > 4000) damage = 4000;
                me->add("neili", -jiali*2 - 500 );
                me->add("jingli", -me->query("jiajin")/2);

                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", random(damage), me);

                msg += HIR"\n$n���ڷ�Ӧ֮������������Ȼһ�����죬�����ؿڡ�\n"NOR;

                msg += NOR;
                me->start_busy(2+random(2));
        }
        else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
                                &&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )

        {

                damage = damage / 2;

                if(damage > 2500) damage = 2500;

                me->add("neili", -jiali*2  - 500);
                me->add("jingli", -me->query("jiajin")/2);

                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", random(damage), me);

                msg += HIR"\n$n��æ�����ֿ�����֪�����̲����޾��ı�Թ�����项һ��$n��������ɡ�\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
                me->start_busy(2+random(2));
        }
        else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) 
                && random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
        {
                damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
                damage = damage / 3;

                if(damage < 1000) damage = 1000;

                me->add("neili", -jiali*2  - 500);
                me->add("jingli", -me->query("jiajin")/2);

                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", random(damage), me);

                msg += HIR"\n$p֪�����Ʋ����мܣ����и�ת��ֻ���ú���һ��\n"NOR;

                msg += NOR;
                target->add( "neili", -damage/4 );
                me->start_busy(2+random(2));
  }
  else {
         msg += HIG"\n$n֪�����Ʋ����мܣ�����һת���ӳ���$N�Ĺ�����Χ��\n\n"NOR;
         me->add("neili", -jiali*2 );
         me->add("jingli", -me->query("jiajin") );
         me->start_busy(2 + random(2));
         message_vision(msg+"\n", me, target);
         return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
