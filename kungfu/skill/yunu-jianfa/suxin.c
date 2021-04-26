// Code of ShenZhou
// suxing.c ��Ů����
// by sdong
// modified by scatter for ShenZhou
// updated by april 2001.12.20
//modified by Slow 2002.3.20

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int skill);

int perform(object me, object target)
{
	string weapon;
	int lvli,original,shenfa,skill;
         int num1,num2;

//          if( me->query("gender") != "Ů��")
//              return notify_fail("��Ů����ֻ����Ů���ã�\n");
	if( !target ) target = offensive_target(me);

/*
     if( !target     || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("��Ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/

	if( (int)me->query_temp("gm_suxin") ) 
		return notify_fail("���Ѿ���������Ů���ģ�\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("�����õĲ�����Ů�ľ����޷�ʩչ��Ů���ģ�\n");

	if( me->query_skill("yunu-xinjing", 1) < 90 )
		return notify_fail("�����Ů�ľ����δ�����޷�ʩչ��Ů���ģ�\n");

	if( me->query_skill("suxin-jue", 1) < 60 )
		return notify_fail("�����Ů�ľ����δ�����޷�ʩչ��Ů���ģ�\n");

	if( me->query_skill("sword") < 135 )
		return notify_fail("�����Ů������Ϊ���㣬������ʹ����Ů���ģ�\n");

	if( me->query("neili") < 500 )
		return notify_fail("�����������ʹ����Ů���ģ�\n");
	if( me->query("jingli") < 300 )
		return notify_fail("��ľ�������ʹ����Ů���ģ�\n");
	message_vision(HIM "$NͻȻĿ��һ�����ޱ���ϲ����ʽȴ��������������鶯Ʈ�ݣ�\n\n" NOR,me);
	skill = (me->query_skill("sword") + me->query_skill("suxin-jue",1)) /2;

//        me->add_temp("apply/attack", skill/5);
//        me->add_temp("apply/damage", skill/50);
         me->add_temp("apply/dodge", skill);
        me->add_temp("apply/parry", skill/2);

/*
	if( target && target->is_character() && me->is_fighting(target) ){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
*/
        me->add("neili", -skill/5);
        me->add("jingli", -skill/10);
	me->set_temp("gm_suxin", 1);

        call_out("remove_effect", skill/5, me, skill);
	return 1;
}

void remove_effect(object me, int skill)
{
	if ( !me ) return;
        me->add_temp("apply/dodge", -skill);
        me->add_temp("apply/parry", -skill/2);

	me->delete_temp("gm_suxin");

	tell_object(me, HIM "�㻺������һ�������ջ���Ů���ģ�һ˫���ӻָ���ƽʱ�Ĺ�ʡ�\n" NOR);
}