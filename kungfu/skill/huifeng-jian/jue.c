// Code of ShenZhou
// jue.c ��������
// xQin 10/99

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
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽����������á�����������\n");

        if( me->query_temp("huifeng/mie") )
                return notify_fail("���������á��𽣡��ķ���\n");

        if( me->query_skill("emei-jianfa", 1) < 100 )
                return notify_fail("����ҽ�����Ϊ����������δ���򡸾�������\n");

        if( me->query_skill("linji-zhuang", 1) < 60 )
                return notify_fail("����ڹ���Ϊ���δ����ʩչ��������ֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "linji-zhuang" )
                return notify_fail("�����õ��ڹ��롸�������ķ���㣣�\n");

        if( me->query("max_neili") <= 600 )
                return notify_fail("���������Ϊ���㣬����������ʩչ����������\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������������������ʩչ����������\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ������ޣ�������ʩչ����������\n");

	level = me->query_skill("sword") / 75;

	me->add_temp("apply/damage", level*10);
	me->add_temp("apply/attack", level*10);
	me->add_temp("apply/speed", level*5);

	if( wizardp(me) )
		tell_object( me, sprintf("damage: %d, attack: %d, speed: %d",
			me->query_temp("apply/damage"), me->query_temp("apply/attack"),
			me->query_temp("apply/speed")) );

	for( i=0; i < level; i++ )
	{
		me->add_temp("emei_perform/juejian", 1);
		COMBAT_D->do_attack(me, target, weapon);
	}
	message_vision(HIY"\n�⼸�½��֣��������������䣬Ѹ�����ף�һɲ�Ǽ�$N������"+
		chinese_number(level) +"�¿��У�������������������������\n"NOR, me);

	me->add_temp("apply/damage", -level*10);
	me->add_temp("apply/attack", -level*10);
	me->add_temp("apply/speed", -level*5);

	me->add("neili", -level*50);
	me->add("jingli", -level*30);

	me->delete_temp("emei_perform/juejian");
	me->start_busy(2+random(2));
	return 1;
}
