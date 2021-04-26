// Code of ShenZhou
//feizhang.c  ��ɽ����

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object weapon);
private int remove_attack(object me, object weapon);

int perform(object me, object target)
{
        object weapon;
        int skill,skill2,damage;
        string *limbs, limb, result, str, type;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ɽ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("���������ȣ�����ܹ�ʩչ��ɽ���ȣ�\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("�����õĲ��ǻ����󷨣��޷�ʩչ��ɽ���ȣ�\n");

        if( me->query_skill("force") < 140 )
                return notify_fail("��Ļ����󷨻��δ�����޷�����ȷ�ʩչ��ħ���ȣ�\n");

        if( me->query_skill("tianshan-zhang", 1) < 140 )
                return notify_fail("����ɽ�ȷ���Ϊ���㣬������ʹ����ɽ���ȣ�\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʩչ��ɽ���ȣ�\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("��ľ�������ʩչ��ɽ���ȣ�\n");

        skill = me->query_skill("staff");
	skill2 = target->query_skill("parry");
        
        message_vision(HIW "\n$N�������˿�����һ������� �����е�"+weapon->name()+"��$n������\n\n" NOR, me, target);

        me->add("neili", -500);
        me->add("jingli", -300);
        weapon->unequip();
        if ( random(me->query("combat_exp")/1000*skill) > random(target->query("combat_exp")/1000*skill2) ) {

		limbs = target->query("limbs");
        	limb = limbs[random(sizeof(limbs))];
	        type = "����";

           	message_vision(HIR+weapon->name()+"����һ�����͵�ײ��$n"+limb+"�ϣ�\n" NOR, target, weapon);

		damage=(skill+me->query("huagong-dafa"))*3;
		target->add("qi",-damage);
	        target->receive_damage("qi", random(damage), me);

        	result = COMBAT_D->damage_msg(damage, type);
	        result = replace_string( result, "$l", limb);

        	str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		target->start_busy(random(3)+1);
	        message_vision(result, me, target);
        	message_vision("($N"+str+")\n", target);

	} else {
                message_vision(HIY "$N���÷�������æ���Ա�һԾ��������"+weapon->name()+"�Ĺ���\n" NOR, target);
        }
        me->start_busy(random(3)+1);
	message_vision(HIB+weapon->name()+"ײ��ɽʯ�ϣ��ϳ��������ء�\n"NOR);
        weapon->move("/u/wsky/xiaoyao");
        return 1;
}

