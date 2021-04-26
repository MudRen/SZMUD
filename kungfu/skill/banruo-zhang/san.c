// Code of ShenZhou
// san.c һ����ɢ
/*
�����ʲ�������һ�ƣ�ʵ�Ǳ�������֮���ۣ�������һ����ɢ����
��ν����ɢ������ָ����ʯ�ϣ�ʯм�ġ�ɢ���������������
�ǡ�ɢ������·�Ʒ���ֻ��ôһ�У�ֻ������̫���ۻ룬�ٵ�ʱ
�ò���ʹ�ڶ��У����˱��ѱ���������һ���������ɽ�������
����Ϊ������Ҫ����л�ʽ���������֮���ܡ�
*/
// Modified by Felix 5/2002

inherit F_SSERVER;
#include <ansi.h>
#include <armor.h>
#include <combat.h>

int perform(object me, object target)
{
        int org_enfor, enfor, hit1, hit2;
        int ap,dp;
        int damage;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("һ����ɢֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") )
                return notify_fail("��ֻ���ڿ���ʱʹ��һ����ɢ��\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("�����õĲ��ǻ�Ԫһ�������޷�ʩչһ����ɢ��\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 180)
                return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչһ����ɢ��\n");

        if( me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("��İ����ƻ��δ�����޷�ʩչһ����ɢ��\n");

        if( me->query_skill("buddhism", 1) < 180 )
                return notify_fail("��ķ�ѧ��Ϊ�������޷�ʩչһ����ɢ��\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("���������Ϊ���㣬���������˷����޷�ʩչһ����ɢ��\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if( (int)me->query("jingli") < 500  )
                return notify_fail("��ľ���������\n");

         ap = me->query("combat_exp");
         dp = target->query("combat_exp");
         ap = (ap + random(ap*2))/ 2;
        
         org_enfor = me->query("jiali");

         if (!target->query_temp("sl/san"))
			damage = 1000 + me->query("max_qi") + me->query("max_qi")*org_enfor/700;
         else if (target->query_temp("sl/san") == 1)
			damage = 100 + me->query("max_qi") * org_enfor / 3000;
         else damage = 100;
message_vision(HIW"$N˫����������ת�˸�ԲȦ��������$n���˹�����$N����δ����$n�Ѹ��ؿں������������֮�䣬$N��������ŭ������ӿ������\n"NOR,me,target);
         if (ap > dp)
         {
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage/3+random(damage/2), me);
            target->add_temp("sl/san",1);
            COMBAT_D->report_status(target);
         }
         else
         {
message_vision(HIW"$n�е�$N��������쳣��֪������������Ӳ�ӣ�ֻ��ʮ���Ǳ��ıܿ���\n"NOR,me,target);
         }
         if (me->query("neili")>2500)
			me->add("neili",-(2000+org_enfor));
         else me->set("neili",10);
            me->start_busy(4+random(4));
         return 1;
}
