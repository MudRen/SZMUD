// Code of ShenZhou
// liangyi.c �����ǽ�����
// xQin 5/99

#include <ansi.h>
inherit F_SSERVER;

int remove_effect(object yin, object yang, int amount);

int perform(object me, object target)
{
	object yin, yang, victim, sword1, sword2;
	int skill1, skill2, amount;
	string ji;

	if( me->query("wudang/liangyi") == "yin" )
		yin = me;
	else if( me->query("wudang/liangyi") == "yang" )
		yang = me;
	else return notify_fail("����δѧ�ᡸ���ǽ�������\n");

	sword1 = me->query_temp("weapon");
	if( !objectp(sword1) || (string)sword1->query("skill_type") != "sword" )
		return notify_fail("�������޽������ܽ������Ǻ�赣�\n");

	if( me->query_skill_mapped("sword") != "wudang-jian" )
		return notify_fail("����ʹ�����䵱�������޷��������Ǻ�赣�\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("������ʩչ����ָ�ὣ�����޷�ͬʱʹ�������ǽ�������\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻��������ν������Ǻ�赣�\n");

	if( !target )
		return notify_fail("�������һ���������Ǻ�赡�\n");

	if( target == me )
		return notify_fail("���Լ����Ǻ�赣���ϧ�㲻�����һ�����\n");

	if( !target->query("wudang/liangyi") )
		return notify_fail(target->name() +"��δѧ�ᡸ���ǽ�������\n");

	ji = me->query("wudang/liangyi")=="yin"?"��":"��";
	if( objectp(yin) && target->query("wudang/liangyi") == "yang" )
		yang = target;
	else if( objectp(yang) && target->query("wudang/liangyi") == "yin" )
		yin = target;
	else return notify_fail(target->name() +"����ʩչ�����ǽ������е�"
		+ ji +"�����޷��������Ǻ�赡�\n");

	sword2 = target->query_temp("weapon");
	if( !objectp(sword2) || (string)sword2->query("skill_type") != "sword" )
		return notify_fail(target->name() +"�����޽����޷��������Ǻ�赣�\n");

	if( target->query_skill_mapped("sword") != "wudang-jian" )
		return notify_fail(target->name() +"��ʹ�����䵱�������޷��������Ǻ�赣�\n");

	if( target->query_temp("wudang/raozhi") )
		return notify_fail(target->name() +
		"����ʩչ����ָ�ὣ�����޷�ͬʱʹ�������ǽ�������\n");

	if( target->query_temp("yield") )
		return notify_fail(target->name() +"�����������Ǻ�赡�\n");

	if( me->is_fighting(target) )
		return notify_fail("������"+ target->name() +"�໥�д��У��޷��������Ǻ�赡�\n");

	skill1 = yin->query_skill("sword");
	skill2 = yang->query_skill("sword");
	amount = ( skill1 + skill2 ) / 8;

	if( skill1*4/5 > skill2 || skill2*4/5 > skill1 )
		return notify_fail("����"+ target->name() +"�Ľ������̫Զ���޷��������Ǻ�赡�\n");

	if( me->is_fighting() )
	{
		victim = offensive_target(me);
		if( !target->is_fighting(victim) )
			return notify_fail(target->name() +"��δ����һ����"
			+ victim->name() +"������\n");
	}
	else if( target->is_fighting() )
	{
		victim = offensive_target(target);
		if( target->is_killing(victim->query("id")) )
			me->kill_ob(victim);
		else
			me->fight_ob(victim);
	}
	else return notify_fail("�����ǽ�����ֻ����ս���н��к�赡�\n");

	if( (string)me->query_temp("wudang/ly_partner") == (string)target->query("name") &&
		(string)target->query_temp("wudang/ly_partner") == (string)me->query("name") &&
			me->query_temp("wudang/ly_count") == 1 && skill1 >= 250 &&
		 		target->query_temp("wudang/ly_count") == 1 && skill2 >= 250 )
	{
		message_vision(HIY"\n������$N��$n������Х��������䣬$N"
		+ yang->query_temp("weapon")->name() +HIY
		"�󿪴��أ��Ƶ��ۻ룬$n�������ˣ������ϻó���㺮�ǡ�\n"NOR, yang, yin);

		yin->delete_temp("wudang/ly_yin");
		yin->set_temp("wudang/ly_count", 2);
		yin->add_temp("apply/attack", amount);
		yin->add_temp("apply/defense", amount);

		yang->delete_temp("wudang/ly_yang");
		yang->set_temp("wudang/ly_count", 2);
		yang->add_temp("apply/defense", amount);
		yang->add_temp("apply/attack", amount);

		remove_call_out("checking");
		call_out("checking", 1, yin, yang, amount);
		return 1;
	}

	if( me->query_temp("wudang/ly_partner") )
		return notify_fail("��������"+ (string)me->query_temp("wudang/ly_partner") +
		"���Ǻ�赡�\n");

	if( target->query_temp("wudang/ly_partner") )
	{
		if( (string)target->query_temp("wudang/ly_partner") == (string)me->query("name") )
			return notify_fail(target->name() +"�����������Ǻ�赡�\n");
		else
			return notify_fail(target->name() +"������"
			+ (string)target->query_temp("wudang/ly_partner") +"���Ǻ�赡�\n");
	}

	message_vision(HIW"\n$N����һ��������һ��������������ʹ�������£���Ȼ�����ˣ�ɦͷ��˼����ʹ�˼��С�\n"
	BLK"$n"+ yin->query_temp("weapon")->name() +HIW+BLK+
	"���֣��㼴�����Ҵ̣����ּ��죬���緢��һ�㡣\n"NOR, yang, yin);

	yin->set_temp("wudang/ly_partner", yang->name());
	yang->set_temp("wudang/ly_partner", yin->name());

	yin->set_temp("wudang/ly_yin", 1);
	yang->set_temp("wudang/ly_yang", 1);

	yin->add_temp("apply/parry", amount/3);
	yin->add_temp("apply/dodge", amount/3);
	yin->add_temp("apply/speed", amount);
	yin->add_temp("apply/damage", -amount*3/4);
	yang->add_temp("apply/parry", amount/3);
	yang->add_temp("apply/dodge", amount/3);
	yang->add_temp("apply/damage", amount);
	yang->add_temp("apply/speed", -amount*3/4);

	yang->add_temp("wudang/yang_att", 1);
	COMBAT_D->do_attack(yang, victim, yang->query_temp("weapon"));
	yang->delete_temp("wudang/yang_att");

	call_out("checking", 1, yin, yang, amount);
	return 1;
}

int checking(object yin, object yang, int amount)
{
	int i, num = 0;
	object victim = offensive_target(yin);

	if( !yin->is_fighting() && !yang->is_fighting() ) 
	{
		remove_effect(yin, yang, amount);
		message_vision(HIG"\n$N��$nͬʱ����ݳ���������ͷ����һ�㣬���ȵķɳ�����֮�⡣\n"NOR, yang, yin);
		return 0;
	}
	if( yin->query_temp("wudang/ly_yin") &&
		(yin->query_temp("wudang/ly_yin") == 2 || random(5) == 1) )
	{
		num = 2+random(2);
		for( i=1; i <= num; i++ )
                	COMBAT_D->do_attack(yin, victim, yin->query_temp("weapon"));
		message_vision(HIW+BLK"\n$N������һ���Ҵ�������ɲ�Ǽ��������"+chinese_number(num)+"����\n"NOR, yin);
        }
	if( yin->query_temp("wudang/ly_yin") == 3 )
	{
		yin->set_temp("wudang/ly_count", 1);
		yang->set_temp("wudang/ly_count", 1);
		message_vision(YEL"\n$N��$n�Ľ���һ���ٻ���һ��Ѹ�ݣ����ǽ���������֮�٣�ʵ��������\n"
		"���˵���ʽ�����ѿ�֮���������й��ӻ�񣬽��ϵ������ƺ�ֻ���ӵ�һ���ɣ������ȴ�������Դ�����ز�¶��\n"NOR, yang, yin);
	}
	if( yin->query_temp("wudang/ly_yin") == 5 )
		message_vision(WHT"\n$N��$n���й���֮ʱ����һ�����ͣ�һ���񣬵��������м�֮�ʣ�����ȴ������ȣ������֮��\n"NOR, yang, yin);

	if( yin->query_temp("wudang/ly_yin") )
		yin->add_temp("wudang/ly_yin", 1);
	if( yang->query_temp("wudang/ly_yang") )
		yang->add_temp("wudang/ly_yang", 1);

	call_out("checking", 1, yin, yang, amount);
	return 1;
}

int remove_effect(object yin, object yang, int amount)
{
	if( yin->query_temp("wudang/ly_count") == 2 )
	{
		yin->add_temp("apply/attack", -amount);
		yin->add_temp("apply/defense", -amount);
	}
	if( yang->query_temp("wudang/ly_count") == 2 )
	{
		yang->add_temp("apply/defense", -amount);
		yang->add_temp("apply/attack", -amount);
	}

	if( yin->query_temp("wudang/ly_yin") )
		yin->delete_temp("wudang/ly_yin");
	if( yang->query_temp("wudang/ly_yang") )
		yang->delete_temp("wudang/ly_yang");

	yin->add_temp("apply/parry", -amount/3);
	yin->add_temp("apply/dodge", -amount/3);
	yin->add_temp("apply/speed", -amount);
	yin->add_temp("apply/damage", amount*3/4);
	yang->add_temp("apply/parry", -amount/3);
	yang->add_temp("apply/dodge", -amount/3);
	yang->add_temp("apply/damage", -amount);
	yang->add_temp("apply/speed", amount*3/4);

	yin->delete_temp("wudang/ly_count");
	yin->delete_temp("wudang/ly_partner");
	yang->delete_temp("wudang/ly_count");
	yang->delete_temp("wudang/ly_partner");
}