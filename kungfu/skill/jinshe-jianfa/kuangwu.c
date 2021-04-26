// Fixed by Scatter
// V.1.2
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i, level;

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                weapon = me->query_temp("secondary_weapon");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����߿��衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽����������á����߿��衹����\n");

        if( me->query_temp("kuangwu") )
                return notify_fail("���������á��𽣡��ķ���\n");

        if( me->query_skill("jinshe-jianfa", 1) < 100 )
                return notify_fail("����߽���������Ϊ����������δ���򡸽��߿��衹��\n");

        if( me->query_skill("force", 1) < 120 )
                return notify_fail("����ڹ���Ϊ���δ����������ʩչ�����߿��衹��\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ�����߿��衹��\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������������������ʩչ�����߿��衹��\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ������ޣ�������ʩչ�����߿��衹��\n");

        level = me->query_skill("sword") / 75;

        me->add_temp("apply/damage", level*10);
        me->add_temp("apply/attack", level*10);
        me->add_temp("apply/speed", level*5);

        if( wizardp(me) )
                tell_object( me, sprintf("damage: %d, attack: %d, speed: %d",
                        me->query_temp("apply/damage"),
                        me->query_temp("apply/attack"),
                        me->query_temp("apply/speed")) );

        for( i=0; i < level; i++ )
        {
                me->add_temp("perform_kuangwu", 1);
                COMBAT_D->do_attack(me, target, weapon);
        }
        message_vision(HIY"\nͻȻ��$N����һת,˫��һ�����н�,����������"+ chinese_number(level) +"�¿��У���ʱ"+ target->query("name")+"��ǰ�������������������,����������,��"+ target->query("name")+"�޷����֣���\n"NOR, me);

        me->add_temp("apply/damage", -level*10);
        me->add_temp("apply/attack", -level*10);
        me->add_temp("apply/speed", -level*5);

        me->add("neili", -level*50);
        me->add("jingli", -level*30);
        me->delete_temp("perform_kuangwu");
        me->start_busy(2+random(2));
        return 1;
}
