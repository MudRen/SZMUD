// Code of ShenZhou
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object *inv;
        int i, mmn, tmn, mexp,texp;

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

       
        me->add("neili", -300);
mmn =  me->query("max_neili");
tmn =  target->query("max_neili");
mexp = me->query("combat_exp")/1000;
texp = target->query("combat_exp")/1000;

 message_vision(HIR
"$N˫�ֵ����������������ݺ�\n\n"NOR, me,target);
 if( (mmn+mexp)  > (tmn+texp) ) {

inv = all_inventory(target);
        for(i=0; i<sizeof(inv); i++)
            if( inv[i]->query("weapon_prop/damage"))
                destruct(inv[i]);
       message_vision(HIR 
"$N˫�ֵ���������Ƶ�$n�ݸ߷��ͣ��������ܡ�ͻȻ���ĵ�һ���죬$n���б���\n" 
NOR, me,target);
 message_vision(HIR"Ϊ$N�������������ϣ���Ϊ����Ķ���ʮ�أ����ϰ�գ�б��ӳ�գ��������׹⡣\n\n"
NOR, me,target);

	 tell_object(target, BLU 
"��ֻ������һ�����б����Ѷϳ�����ʮ�أ�\n" NOR);
       
                target->start_busy(1+random(1));
        }
        else 
        {
        message_vision(HIY "$p�Ͻ�����Ծ�����ɣ��㿪$P�Ĺ�����\n" NOR, 
me, target);
        }
        me->start_busy(1+random(3));
        return 1;
}

