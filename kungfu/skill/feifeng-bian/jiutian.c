// Code of ShenZhou
//jiutian.c  �������
//Mantian ���� 2000/10/02

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object target, int dodge, int speed, int damage, int parry);

int perform(object me, object target)
{
		object weapon, weapon1 ;
		string msg;
		int extra, dodge, speed, parry ,damage;

		if (!target) target = offensive_target(me);

		if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail(HIW"�����õ��ڹ��ķ����ԣ��޷�Ծ�����Ρ�\n" NOR);

		if (!target
		||      !target->is_character()
		||      !me->is_fighting(target))
			return notify_fail( HIW "��������졹ֻ����ս����ʹ�á�\n" NOR);

		if (me->query("gender") !="Ů��") 
			return notify_fail( HIW "��������졹ֻ��Ů�����裡\n" NOR);

		if (me->query_temp("jiutian"))
			return notify_fail( HIW "�������衸������졹��\n" NOR);

		if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("��ʹ�õ��������ԡ�\n");

		if ((int)me->query_skill("kurong-changong", 1) < 130)
			return notify_fail( HIW "��Ŀ���������Ϊδ�����޷�ʩչ��������졹��\n" NOR);

		if ((int)me->query_skill("feifeng-bian", 1) < 150) 
			return notify_fail( HIW "��ķɷ�޷���Ϊ����������δ���򵽡�������졹��\n" NOR); 

		if (me->query("max_neili") <= 1000)
			return notify_fail( HIW "���������Ϊ���㣬����������ʩչ��������졹��\n" NOR);
	   
		if ((int)me->query("neili", 1) < 500)
			return notify_fail( HIW "��������������������������ʩչ��������졹��\n" NOR);

		if (me->query("jingli") <= 300)
			return notify_fail( HIW "��ľ������㣬�޷�ʩչ��������졹��\n" NOR);

		if (me->query("combat_exp")*3 > target->query("combat_exp")*4) 
			return notify_fail( HIW "���á�������졹�۸���С?��̫�ðɣ�\n" NOR);

		message_vision(MAG"$N�������һԾ���������裬���е�"NOR+weapon->name()+NOR MAG"��������������������Ī�⣬�仯�޶ˣ�������һ��ɲ�Ǻÿ���\n" NOR, me);

		if (random(me->query("per"))+8 > 20)
        {
		message_vision(HIR"ͻȻ$nһ��ʧ�񣬱�$N�Ķ������������ٸ��Ŀ���������Գ������$N�������Ե����ߵ���\n"NOR, me, target);
       	target->start_busy(random(5)+5);
		

		if (target->query_temp("weapon")) {
			weapon1 = target->query_temp("weapon");

			if (me->query("combat_exp") < random(target->query("combat_exp")*8/5)) {
				message_vision(HIW"$n��ָһ�ɣ�"NOR+weapon1->name()+NOR HIW"��Щ���֣�\n" NOR, me, target);
                }
				else {
			message_vision(HIW"$n����һ�ɣ����������Ķ�����"NOR+weapon1->name()+NOR HIW"��\n" NOR, me, target);
			weapon1->unequip();
			weapon1->move(environment(target));
			target->reset_action();
			}
		}
        extra = (int)me->query_skill("feifeng-bian",1);
        speed = extra/2 + random(extra/2);
        dodge = extra*3/4 + random(extra/2);
        damage = extra/3 + random(extra/2);
        parry = extra*3/4 + random(extra/5);

        me->add_temp("apply/dodge", dodge);
        me->add_temp("apply/speed", speed);
        me->add_temp("apply/damage", damage);
		target->add_temp("apply/parry", -parry);

		me->set_temp("jiutian", 25+extra/6);
		call_out("checking", 1, me, target, weapon, dodge, speed, damage, parry);

//		call_out("remove_effect", extra/8, me, target, dodge, speed, parry,);

                me->start_busy(1);
                me->add("neili", -250);
                me->add("jing", -50);
        if (me->is_fighting())
		me->start_busy(1)+1;
        }
        else
        {
		message_vision(RED"�Ϳ�$n������������������ȫ���ע����δ��$N���������ԡ�\n"NOR, me, target);
		me->start_busy(random(5)+2);
        }
        return 1;
}
//void remove_effect(object me, object target, int dodge int speed int parry)
//{
//		if (!me) return;
//		me->add_temp("apply/dodge", -dodge);
//		me->add_temp("apply/speed", -speed);
//		target->add_temp("apply/parry", parry);
//		me->delete_temp("jiutian");
//		message_vision(HIM "$N�о�����Ѫ��˳���ٶȽ�������������\n"NOR,me);
//}
//
void checking(object me, object target, object weapon, int dodge, int speed, int damage, int parry)
{
		if (!living(me) || me->is_ghost())
		{
			remove_effect(me, target, dodge, speed, damage, parry);
			return ;
		}
        if (me->query_temp("jiutian")) {
			if( !me->is_fighting() )
			{
				message_vision(HIY"\n$N���һ���������˲�����\n"NOR, me);
				remove_effect(me, target, dodge, speed, damage, parry);
				tell_object(me, HIM"\n������һֹ���ٶ�����������\n\n"NOR);

				return;
			}
			else if (environment(weapon)!= me || weapon!=me->query_temp("weapon"))
			{
				message_vision(HIY"\n$N�Ų�һ�٣�ֹͣ���赸��\n"NOR, me);
				remove_effect(me, target, dodge, speed, damage, parry);
				tell_object(me, HIM"\n��о�����Ѫ��˳���ٶȽ�������������\n\n"NOR);

				return;
			}
			else if (weapon->query("weapon_prop") == 0)
			{
				message_vision(HIY"\n$N���е�"NOR+weapon->name()+NOR HIY"�ѻ٣����ò�ͣ�½Ų���\n"NOR, me);
				remove_effect(me, target, dodge, speed, damage, parry);
				return;
			}
			else if (me->query_skill_mapped("force") != "kurong-changong")
			{
				remove_effect(me, target, dodge, speed, damage, parry);
				tell_object(me, HIY"\n��е���Ϣ���������ò�ͣ�½Ų���\n\n" NOR);
				return;
			}
		me->add_temp("jiutian", -1);
		call_out("checking", 1, me, target, weapon, dodge, speed, damage, parry);
		}
		else {
		remove_effect(me, target, dodge, speed, damage, parry);
		tell_object(me, HIM"\n��о�����Ѫ��˳���ٶȽ�������������\n\n"NOR);
		}
}       

//private int remove_effect(object me, object target, int dodge, int speed, int damage, int parry)
void remove_effect(object me, object target, int dodge, int speed, int damage, int parry)
{
		if (!me) return;
		me->delete_temp("jiutian");
		me->add_temp("apply/dodge", -dodge);
		me->add_temp("apply/speed", -speed);
		me->add_temp("apply/damage", -damage);
		if (!target) return;
 		target->add_temp("apply/parry", parry);
}
