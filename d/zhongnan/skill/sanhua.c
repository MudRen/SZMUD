// Code of ShenZhou
//  /k  ungfu/skill/sanhua-juding/sanhua.c �����۶�
// sdong 07/98
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,skill,wap,wdp;
	string *limb, type, result, str,msg;

	type = "����";

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����۶�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("sanhua") )
		return notify_fail("������ʹ�������۶��ˣ�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("���ֲ���ʩչ�����۶���\n");

	if( me->query_skill_mapped("strike") != "sanhua-juding" )
		return notify_fail("�����õĲ��������۶��ƣ�����ʩչ�����۶���\n");

	if( me->query_skill_prepared("strike") != "sanhua-juding" )
                return notify_fail("�������Ĳ��������۶��ƣ�����ʩչ�����۶���\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("�����õĲ������칦��ʩչ���������۶���\n");

	if( me->query_skill("force") < 135 )
		return notify_fail("������칦���δ�����޷�ʩչ�����۶���\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("�����۶���Ҫ��տ�������۶��Ʒ�����Чʩչ��\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ�������۶���\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ�������۶���\n");	
	if( me->query("jing") <= 200 )
		return notify_fail("��ľ�����ʹ�������۶���\n");	


	msg = HIM"$N�����������칦�������鲼ȫ��ͷ��ð��˿˿��������Ȼ����������������������һ�ƣ�һ���������˳�һ����$nϮ����\n\n"NOR;
	message_vision(msg, me, target);

	me->set_temp("sanhua", 1);

	skill =  ( me->query_skill("sanhua-juding")
		+ me->query_skill("force") ) / 2; 

	me->add_temp("apply/attack", skill/6);
	me->add_temp("apply/damage", skill/4);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->add_temp("apply/defense",  skill/2);


		weapon = target->query_temp("weapon");

        if( objectp(weapon) ) 
		{

                wap =   me->query("force")/5
						+ (int)me->query("sanhua-juding")/5
                        + (int)me->query_str()
                        + (int)me->query("jiali");

                wdp = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)target->query_str()
                        + (int)target->query("jiali")
                        + (int)target->query_skill("parry")/3;

                wap = wap/2 + random(wap/2);

                if( wap > 3 * wdp ) {
						message_vision(HIY"ֻ��$N���ϵ�$n"+HIY+"�ѱ�һ����ϡ�\n"NOR, target, weapon);
                        weapon->unequip();
                        weapon->move(environment(target));
                        weapon->set("name", "�ϵ���" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        target->reset_action();
						me->add("neili", -150); // to break weapon takes more neili
                } else if( wap > 2 * wdp ) {
                        message_vision(HIW"$Nֻ��������" + weapon->name() + "��һ����ðѳֲ��������ַɳ���\n" NOR,
                                target);
                        weapon->unequip();
                        weapon->move(environment(target));
                        target->reset_action();
						me->add("neili", -120); // to break weapon takes more neili
                } else if( wap > wdp ) {
                        message_vision("$Nֻ��������" + weapon->name() + "һ����Щ���֣�\n",
                                target);
						me->add("neili", -100); // to break weapon takes more neili
                } 

		}
		else{
			me->add_temp("apply/attack", skill/2);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->add_temp("apply/attack", -skill/2);
		}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->start_busy(1+random(3));
	me->add("neili", -100);
	me->add("jingli", -100);
	me->add("jing", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/15);

	return 1;
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount/3);
	me->add_temp("apply/damage", -amount/2);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->add_temp("apply/defense", -amount);
	me->delete_temp("sanhua");
	message_vision(
	HIY "\n$N����һ�������������ջص��\n\n" NOR, me);

	return 0;
}
