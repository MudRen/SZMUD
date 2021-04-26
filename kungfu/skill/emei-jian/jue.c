// jue.c ��������
// by snowyu update 2002/4

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, level, attack, damage;

	weapon = me->query_temp("weapon");
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		weapon = me->query_temp("secondary_weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( me->query_skill("emei-jian", 1) < 200 )
		return notify_fail("��Ķ��ҽ�����Ϊ����������δ���򡸾�������\n");

	if( me->query_skill("linji-zhuang", 1) < 200 )
		return notify_fail("����ڹ���Ϊ���δ����ʩչ��������ֻ���˼�����\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽����������á�����������\n");

	if( me->query_skill_mapped("force") != "linji-zhuang" )
		return notify_fail("�����õ��ڹ��롸�������ķ���㣣�\n");

	level = me->query_skill("sword") / 75;
	if( me->query("max_neili") <= level*500 )
		return notify_fail("���������Ϊ���㣬����������ʩչ����������\n");

        if( me->query("neili") <= level*80 )
                return notify_fail("�����������������������ʩչ����������\n");

        if( me->query("jingli") <= level*60 )
                return notify_fail("��ľ������ޣ�������ʩչ����������\n");

	if( me->query_temp("perform/miejian") )
		return notify_fail("���������á��𽣡��ķ���\n");

	damage = ( me->query_skill("force") + me->query("neili")/20 + me->query("max_neili")/5 )/20;
	attack = ( me->query_skill("dodge") + me->query("jingli")/20 + me->query("max_jingli")/5 )/20
		 + me->query_dex()/5 + weapon->query("apply/damage")/2;

           if (damage > 200) damage=200;
           if (attack > 200) attack=200;
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/attack", attack/2+random(80));
	me->add_temp("apply/speed", level*5);

	if( wizardp(me) ) tell_object( me,
		sprintf("damage: %d, attack: %d, speed: %d, neili cost: %d, jingli cost: %d",
		me->query_temp("apply/damage"), me->query_temp("apply/attack"),
		me->query_temp("apply/speed"), level*70, level*50) );

	for( i=0; i < level; i++ )
	{
		me->add_temp("perform/juejian", 1);
		COMBAT_D->do_attack(me, target, weapon);
	}
	message_vision(HIY"\n�⼸�½��֣��������������䣬Ѹ�����ף�һɲ�Ǽ�$N������"+
		chinese_number(level) +"�¿��У�������������������������\n"NOR, me);

        me->add_temp("apply/damage", -damage);
        me->set_temp("apply/attack", 0);
	me->add_temp("apply/speed", -level*5);

	me->add("neili", -level*70);
	me->add("jingli", -level*50);

	me->delete_temp("perform/juejian");
	me->start_busy(2+random(2));
	return 1;
}
