// Code of ShenZhou
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object *inv;
        int i, mmn, tmn, mexp,texp,m1,m2;
	int a;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + 
"Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
                
        if( (int)me->query_skill("liumai-shenjian", 1) < 120 )
                return notify_fail("�����������Ϊ������\n");
        if( me->query("neili") <= 1000 )
                return notify_fail("�������������\n");
		mmn =  me->query("max_neili");
		tmn =  target->query("max_neili");
		mexp = (int)me->query("combat_exp")/1000;
		texp = (int)me->query("combat_exp")/1000;
		m1 = me->query_skill("liumai-shenjian");
		m2 = me->query("max_qi");
		a = (int)(m1*5+m2)/2;
         message_vision(HIR
"$N˫��ķָ��ǰ�͵�һ�����������ν���ֱϮ$n����Ӱ��\n\n" NOR, me,target);

if(random(mmn+mexp)  > random(tmn+texp) ) {
if (mexp > texp) 
{

target->add("qi",(-a));

target->receive_wound("qi", (m1*2));
me->add("max_neili", (-3));
tell_object(target, BLU "��ֻ�������������棬�����ؿ�һ���ʹ��\n"NOR);
tell_object(me, BLU "��ʹ��ȫ������$n�����ָ����ʱ�е�һ�����ѡ�\n"NOR);
        me ->start_busy(1+random(3));
  }
else
{
target->add
("qi",-(a*2/3));      
target->receive_wound("qi", (m1*2));
me->add("max_neili", (-3));
tell_object(target, BLU "��ֻ�������������棬�����ؿ�һ���ʹ��\n"NOR);
tell_object(me, BLU "��ʹ��ȫ���������ָ����ʱ�е�һ�����ѡ�\n"NOR);
                 
        me ->start_busy(1+random(3));
  }      
}
       else 
        {
message_vision(HIR
"$n�Ͻ�����Ծ�����ɣ��㿪$N�Ĺ�����\n\n" NOR, me, target);

        }

        me->start_busy(1+random(3));
        me->add("max_neili", -1);
        return 1;
}

