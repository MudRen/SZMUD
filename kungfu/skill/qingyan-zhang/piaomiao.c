// snowyu piaomiao 
// ע��˴����������ٷ������У����˸о��˹����ܸ���������������֣���
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int dam,int attack);
void checking(object me,int dam,int attack);
void checking2(object me,int dam,int attack,int old_dam,int old_att);

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");
	int lv, attack, dam,old_att,old_dam;

	old_att = (int)me->query_temp("apply/attack",1);
	old_dam = (int)me->query_temp("apply/damage",1);
	lv = (int)me->query_skill("qingyan-zhang", 1); 
	attack = lv/4+ random(lv/2);
	dam = lv/2 + random(lv/4);

	if( !target ) target = offensive_target(me);
	else me->set_temp("offensive_target", target);

	if (me->query("family/family_name")!="����μ�" && !wizardp(me))
                return notify_fail(HIW "��Ǵ�������޷�ʩչ������Ʈ�졹��\n" NOR);
    
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIW "����Ʈ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("piaomiao") )
		return notify_fail(HIW "������ʹ������Ʈ�죡\n");
        if ( me->query_temp("weapon") )
               return notify_fail(HIW "����Ʈ�������ַ���ʩչ��\n");

	if( me->query_skill("kurong-changong", 1) < 150 )
		return notify_fail(HIW "��Ŀ������������δ����\n");

	if( me->query_skill("qingyan-zhang", 1) < 150 )
		return notify_fail(HIW "��Ļ���������������δ���죬�޷�ʩչ����Ʈ�죡\n");

	if( me->query_skill("strike", 1) < 150 )
		return notify_fail(HIW "��Ļ����Ʒ���δ���죬�޷�ʩչ����Ʈ�죡\n");

	if( me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail(HIW "�����õ��ڹ��ķ����ԣ��޷��ۼ�������\n");
	
	if(target->query("dalibandit")) 
		return notify_fail(HIW "ץ�����㻹��ˣ��ѽ��\n" NOR);

	if (me->query("max_neili") <= 2000)
                return notify_fail(HIW "���������Ϊ���㣬�޷���������Ʈ�죡\n" NOR);
        
        if ((int)me->query("neili", 1) < 800)
                return notify_fail(HIW "��������������ھ�������ʩչ����Ʈ�죡\n" NOR);

        if (me->query("jingli") <= 800)
                return notify_fail(HIW "��û���㹻������ʩչ����Ʈ�죡\n" NOR);

        if(me->is_busy()) return notify_fail(HIW "����æ����,û�취ʩչ����Ʈ�죡\n" NOR);

	message_vision(HIB"$N��������ķ��������������������ƣ���ʱ$N���Ʒ��ף����з���һ��"NOR HIW"����"NOR HIB"��\n" NOR, me);

	me->add("neili", -250);
	me->add("jingli", -100);

	me->set_temp("piaomiao", 1);
	me->add_temp("apply/attack", attack);
	me->add_temp("apply/damage", dam);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set_temp("piaomiao", 2);
	me->start_call_out( (: call_other, __FILE__, "checking2", me,dam,attack,old_dam,old_att :), 12);
	if (wizardp(me))  
        tell_object(me, sprintf("original damage=%d, original attack= %d,damage = %d,attack = %d\n", old_dam,old_att,dam,attack));
    me->start_call_out( (: call_other, __FILE__, "checking", me,dam,attack :), 1);
	return 1;
}

void checking(object me, int dam, int attack)
{
	int pm, limit;
	object weapon, target;

	weapon = me->query_temp("weapon");
	target = me->query_temp("offensive_target");

	pm = me->query_temp("piaomiao");
	limit = 1 + (int)me->query_skill("qingyan-zhang", 1)/100;
	
	if( !target || !me->is_fighting(target) ) target = offensive_target(me);

	if( pm > limit || pm > 6 ) {
		message_vision(BLU "\n$N����һ���������ھ��ջص��\n"NOR, me);
		remove_effect(me, dam, attack);
		me->start_busy(1);
		return;
	}

	if( !living(me) || me->is_ghost()  )
	{
		remove_effect(me, dam, attack);
		return;
	}

	if( !me->is_fighting() )
        {
                message_vision(HIM "\n$N�������һԾ�������˾�����ھ���\n"NOR, me);
                remove_effect(me, dam, attack);
                tell_object(me, MAG "\n�㽫��Ϣ������ԭ����״̬��\n\n"NOR);

                return;
        }
		
	
	me->start_call_out( (: call_other, __FILE__, "checking", me,dam,attack :), 1);
	return;
}

void remove_effect(object me, int dam, int attack) 
{
	if (!me) return;
	me->add_temp("apply/attack", -attack);
	me->add_temp("apply/damage", -dam);
	me->delete_temp("piaomiao");
	me->start_busy(1);
}

void checking2(object me,int dam,int attack,int old_dam,int old_att)
{
	if (wizardp(me))  
        tell_object(me, sprintf("after fight original damage=%d, original attack= %d,damage = %d,attack = %d\n", old_dam,old_att,dam,attack));
	if (me->query_temp("piaomiao"))
	{
		message_vision(BLU "\n$N����һ���������ھ��ջص��\n"NOR, me);
		me->start_busy(1);
		tell_object(me, MAG "\n�㽫��Ϣ������ԭ����״̬��\n\n"NOR);
		me->add_temp("apply/attack", -attack);
		me->add_temp("apply/damage", -dam);
		me->delete_temp("piaomiao");
	}

	if((int)me->query_temp("apply/attack",1) != old_att)
	{
		me->set_temp("apply/attack",old_att);
	}
	if((int)me->query_temp("apply/damage",1) != old_dam)
	{
		me->set_temp("apply/damage",old_dam);
	}
		

}
