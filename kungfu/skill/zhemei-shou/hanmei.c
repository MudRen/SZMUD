// hanmei.c ��÷ů��    
// by xuanyuan 11/28/2001
/*
����δ˵�꣬ͻȻ��������һ�����У�ȴ��ͯ�����������ͻʩ��Ϯ������͵��һ
�ơ���һ��������Ϣ����������֮������������ֽ�������ˮ���÷����������мܣ�
ͯ�ѵ�������Ϯ����ǰ����æƮ���˺󣬵���������һ����ֻ����Ϣ������������
Ȼ���ˡ�
����ˮ����������ʦ梣�
��һ���������³ԵĿ�ͷ̫�࣬���װ������ƭ���ϵ���������һ�ӣ�������ͯ��
�ؿ����˹�ȥ�������������죬ͯ�ѵ�ʬ����˼����߹ǡ�
    ����ˮ�������У������ѽ���ɽ�������������죬��Ȼһһ�񿪣�����֮�У�
���������м�ʵ���ķ���֮��������ˮ���������ף��㱳����˭�������񼸺�ȫ
���ٵо��飬һ��֮�£���ͷȥ����ֻ���ؿ�һʹ���Ѹ�����ˮ������Ѩ��������
˫��˫�ȵ�Ѩ��Ҳ���������У���ʱȫ����������ͯ�����ԣ���ŭ�������е���
�����ǳ�����ȴʹթƭ�ˡ���
ͻȻ֮�䣬�ĵ�һ���죬����ˮ�����Һ���
���ġ�����Ѩ��������һ�����֣�����ͯ��������ͯ�Ѹ�����ȭ�ͻ�������������
��ˮ�ؿڡ����С�ҪѨ����һ��һȭ������ʩΪ������ˮ��˵���ֵֵ���б�����ܣ�
��������������ѨҲ�ǲ��������Ӹ�һȭ��ɣ�ˤ��ʯ��֮�ϣ����л���Ҳ���ַ�
����ͯ�������Ѿã���һȭ�Ƶ��쳣���������۴ӵ�������Ѵ����ڶ��㣬ֱ����
��һ�㣬���ŵ��䡣
��������ˮʮ�ֻ���������������Ȼ�����������������ؿ�ӡ��һ�ơ�ͯ��
һ�����������ݣ�ֻ����Ӳ����������������
    ����ˮǰ�ĺ󱳣��������ˣ�����ͻȻ��ʧȴ���ƣ������ˮ���ģ���ʱҪ��
�̶�������ң���书�������µ�һ�ȵĹ��򣬵�������ʧ�ƣ�������ٺ����߳�ͻ��
ȴ����й��������ɢ��ʱ��ʹ��ʵ�������������ݡ����֮�䣬ֻ��ȫ�����Ѩ��
��ͬʱ����������֮�࣬��֪���˾������Σ��е��������ɣ������кã������Ұ�
��Ѩ�������Ļ�һ�ƣ�����ʱ�����Ȼ������΢������������ֻ������ˮȫ�������
һ���֣�ץȥ���������ŵİ�ɴ����ָ��ץ�Լ���գ���ʱѪ�۰߰ߣ��е�������
�ɣ��㡭�����һȭ�������ҡ���
*/
#include <ansi.h>
#include <armor.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"�ٻ�Ѩ",
	"��Ѩ",
	"ǿ��Ѩ",
	"�Ի�Ѩ",
	"�縮Ѩ"
});

string* xuedao2 = ({
	"��׶Ѩ",
	"�յ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"��̨Ѩ",
	"������"
});

string* xuedao3 = ({
	"�и�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��ȱѨ",
	"̫ԨѨ",
	"����Ѩ"
});

string* xuedao4 = ({
	"����Ѩ",
	"�Ϲ�Ѩ",
	"������",
	"����Ѩ",
	"ӭ��Ѩ"
});

string* xuedao5 = ({
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"����Ѩ"
});
void tie_hit(object me, object target);
void nuan_hit(object me, object target);
void han_hit(object me, object target);

int perform(object me, object target)
{
	object armor,weapon;
	int damage, time;
	string *limb, type, result, str;

	type = "����";

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("����÷ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻���У����ʹ������÷ů������\n");

	if( (int)me->query_skill("zhemei-shou", 1) < 150 )
		return notify_fail("�����ɽ��÷�ֲ�����죬�޷�ʹ�á���÷ů������\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 150 )
		return notify_fail("�����ɽ�����Ʋ�����죬�޷�ʹ�á���÷ů������\n");

	if( (int)me->query_skill("force") < 150 )
		return notify_fail("����ڹ���Ϊ���δ�㣬�޷�ʹ�á���÷ů������\n");

	if ( me->query_skill_mapped("force") != "xiaowuxiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
		return notify_fail("�����õ��ڹ��롸��÷ů�����ķ���㣣�\n");

	if( me->query("max_neili") <= 2000 )
		return notify_fail("���������������޷�ʹ�á���÷ů������\n");

	if ( (int)me->query("neili") < 500)
		return notify_fail("��������������޷�ʹ�á���÷ů������\n");

	if ( (int)me->query("jingli") < 300)
		return notify_fail("��ľ����������޷�ʹ�á���÷ů������\n");

	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("hand"))/10;
	if (time > 10) time = 10;

	if( me->query("neili") <= time )
		return notify_fail("����������������Ͼ���ʩչ��������÷ů������\n");

	me->add_temp("ly_nuan",1);
	remove_call_out("nuan_hit");
	nuan_hit(me, target);
	return 1;
}

void nuan_hit(object me, object target)
{
	object armor;
	int damage, time, ap, dp, pp, fap, lyz, force;
	string msg, *limb, type, result, str;
	object weapon;

	if( !target || !me->is_fighting(target) ) return;

	if( !living(me) || me->is_ghost() ) return;

	if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	type = "����";

	lyz = (int)me->query_skill("liuyang-zhang", 1);
	force = (int)me->query_skill("force", 1);

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;
	ap = ap*(1+time);

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	
	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	if( pp < 1 ) pp = 1;

	msg = HIM "\nͻȻ$N������ǰһ�ƣ�������������������������ͬ��������ӿ��һƬů����$nϮ����\n" NOR;
	message_vision(msg , me,target);
	
	me->add("neili", -lyz);
	me->add("jingli", -lyz/2);

	fap = random(ap + dp);

	if( living(target) && fap < dp ) {

		if (target->query_skill("liuyang-zhang") > me->query_skill("liuyang-zhang")*2/3)
		{
		message_vision(HIY "\n$n�ѽ���ɽ�������������죬��Ȼһһ�񿪣�����֮�У����������м�ʵ���ķ���֮����\n\n" NOR, me, target);
		}
		else {
		message_vision(HIY "\n$n���һ������Ȼ�˲�������־����п�����������У�ȴ�����ų���һ���亹��\n\n" NOR, me, target);
		if(me->query_skill("hand") >= me->query_skill("strike")*2/3){
			call_out("han_hit",1+random(2),me,target);
			}
		}
		target->start_busy(2+random(2));
		me->start_busy(1);
	}

	else if( random(ap + pp)< pp && random(5) == 0 && target->query("race") == "����" )
	{
		weapon = target->query_temp("weapon");
		if(weapon)
		{

			if(target->query("neili") > me->query("neili")){
					message_vision(HIR"\n$N�;���һ������ѹ������Цһ��������"NOR + weapon->name() + HIR"��סȫ����һֻ�ֵ���������ֻ����Ȼһ�����죬������ԣ���Χ�����Ĵ���ɢ��\n"NOR, target );
				}
			else if(target->query("neili") < me->query("neili")){

					weapon->unequip();
					weapon->move(environment(target));
					target->reset_action();
					message_vision(HIR"\n$N�;���һ������ѹ������֪�������"NOR + weapon->name() + HIR"���ַɳ����Ͻ��������ܡ�ֻ����Ȼһ�����죬������ԣ���Χ�����Ĵ���ɢ��\n"NOR, target );
				}
		}
		else message_vision(HIR"\n$N�;�һ������ѹ������֪����Ͻ��������ܡ�ֻ����Ȼһ�����죬������ԣ���Χ�����Ĵ���ɢ��\n\n"NOR, target );

		message_vision(HIW BLK"$N����һ�𣬲��$n�������๥�����������ع�����\n\n"NOR, target, me);

		target->add("neili", -lyz);
		target->add("jingli", -lyz);
		target->start_busy(3+random(2));
		me->start_busy(2+random(2));
		remove_call_out("tie_hit");
		call_out("tie_hit",3+random(2),me,target);
	}

	else {
		if( target->query_temp("armor/cloth") )
			armor = target->query_temp("armor/cloth");

		if( (!living(target) || (!armor || (armor && armor->query("armor_prop/armor") < 150) )) && ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("strike") + me->query_skill("force"))*2/3) && target->query("race") == "����")
		{
			message_vision(HIR"\n��һ�ƴ�������֮������������ֽ���$N���÷����������мܣ�������Ϯ����ǰ��ֻ����Ϣ������������Ȼ�ܵ��ش�����ǰһ�ڣ���ʲô���������ˡ�\n\n"NOR, target,target );
			target->receive_wound("qi", (int)target->query("eff_qi"), me);
			target->receive_damage("qi", (int)target->query("qi")+1,  me);
			me->add("neili", -(me->query("jiali")+lyz/2));
			me->add("jingli", -me->query("jiajin"));
		}
		else
		{
			damage = (me->query("jiali") + me->query("jiajin")) * (int)me->query_skill("force")/60 + (random(lyz)+force)*time +me->query_temp("apply/damage");

			if(damage > me->query_skill("strike")*10 ) damage = me->query_skill("strike")*10;
			if(damage < me->query_skill("strike")*2 ) damage = me->query_skill("strike")*2;

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2)+damage/4, me);
			target->start_busy(1+random(3));

			limb = target->query("limbs");

			if(random(2) ) type = "����";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );

			if( damage < 600 ) 
			message_vision(HIR"\n$N��æ������һ�ܣ�����ӭ�������ܵ�������������ʱ��һ������ѹ�ļ���͸����������\n"NOR, target,me );
			else if( damage < 1200 ) 
			message_vision(HIR"\nֻ�������������죬$N������������ǰ�أ����˼����߹ǣ�\n"NOR, target,me );
			else if( damage < 2000 ) 
			message_vision(HIR"\n$N��æ��������ܣ������ĵ�һ���죬$N�����Һ������ġ�����Ѩ��������$nһ�����֣�\n"NOR, target,me );
			else 			
			message_vision(HIR"\n����������ʩΪ��$N��˵���ֵֵ���б�����ܣ���������������ѨҲ�ǲ��������Ӹ�һ����ɣ�ˤ������֮�⣡\n"NOR, target,me );

			message_vision(result, me, target);

			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("( $N"+str+" )\n", target);
			if(wizardp(me)) tell_object(me, "hanmei damage: "+damage+"\n");

//			if(me->query_skill("hand") >= me->query_skill("strike")-10 && !target->is_busy()){
//			call_out("han_hit",1+random(2),me,target);
//			}
		}
	}
	me->start_busy(3+random(2));
}
void han_hit(object me, object target)
{
	int ap, dp, pp, time;

	if( !target || !me->is_fighting(target) ) return;

	if( !living(me) || me->is_ghost() ) return;

	if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	
	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	if( pp < 1 ) pp = 1;

	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("hand"))/10;
	if (time > 12) time = 12;
	if (time < 4) time = 4;
	message_vision(HIC "\nͬʱ$N����˳��һ������÷�ֺ�����¶��ȴ����÷��ѩ����������һ˿�������$n��" + xuedao3[random(6)] + "��\n\n" NOR, me, target);

	if( random(ap) < dp/2 && time > 0 )
	{
		message_vision(HIY "$nֻ��һ������Ϯ�����������˸���ս���Ų�һ�����˿�ȥ��\n" NOR, me, target);
		me->add("neili", -100);
		me->start_busy(time/5);
		call_out("delete_han", 1, me);
    }
	else if( random(ap) < pp/2 && time > 0 ){
		message_vision(HIW "$n������Σ����Ӧ�䣬һ����$N����ָ��Ҫ�����Լ���ͷ����������б��������$N�ֱ���ȥ��\n" NOR, me, target);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
		me->add("neili", -100);
		me->start_busy(time/5);
		call_out("delete_han", 1, me);
    }
	else{
		message_vision(WHT "$NСָ��һ��֮�У��������ϳ˵ġ�С���๦����$n�Ĺ�������������ʮ�꣬Ҳ�Ѷ����һ����\n" NOR, me, target);
		message_vision(HIR "$Nһ�����У�$n��ʱ�������á�\n" NOR, me, target);
		me->delete_temp("ly_nuan");
		remove_call_out("nuan_hit");
		me->add_temp("ly_han",1);
		me->add("neili", (-50)*time);
		target->start_busy(time);
    }
}

void delete_han(object me) 
{
	me->delete_temp("ly_han");
}

void tie_hit(object me, object target)
{
	int sum, n1, n2;
	string msg;

	if( !target || !me->is_fighting(target) ) return;

	if( !living(me) || me->is_ghost() ) return;

	if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	sum = me->query_skill("force") + me->query_skill("strike") + target->query_skill("force") + target->query_skill("parry");
	n1 = me->query("neili");
	n2 = target->query("neili");

	me->add("neili", -100 * sum / ( me->query_skill("force") + me->query_skill("strike") ) ); 
	if(me->query("neili")<0)me->set("neili",0);

	target->add("neili", -100 * sum / ( target->query_skill("force") + target->query_skill("strike") ) );
	if(target->query("neili")<0)target->set("neili",0);

	if( n1 > 3000 && n2 > 3000) {
		msg = WHT"��ʱ˫����������ǿ��������ʤ������ʹ�Է��ش����ɡ�\n"NOR;

		if( n1 > n2 )
		msg += HIW"�����ֽ���һ�ᣬ$nͷ��͸��һ���Ƶİ���������Խ��ԽŨ����������һ�㡣\n"NOR;
		else msg += HIW"�����ֽ���һ�ᣬ$Nͷ��͸��һ���Ƶİ���������Խ��ԽŨ����������һ�㡣\n"NOR;
	}

	else {

		if( n1 > n2 ) msg = WHT"$N�����߷�����������˥�Ǽ����Թ�Ƭ�̣�$n����ȫ������졣\n"NOR;
		else msg = WHT"$N������Լ���������Թ�Ƭ�̣�$N����ȫ������졣$n������ԴԴ��������Ȼ������ʱ�㼴�Ľߡ�\n"NOR;
		}

	message_vision(msg , me,target );

	if( me->query("neili") > 0 && target->query("neili") > 0 && me->is_busy() && target->is_busy() && living(me) && living(target) )
	{
		if (me->query_skill("beiming-shengong") > 120 && !target->query_skill("beiming-shengong") && me->query_skill_mapped("force") == "beiming-shengong" )
		{
			message_vision(HIR "\n$N�����Լ�������ԴԴ�ش���������$n������$n���ڵı�ڤ���������֣�\n\n" NOR, target, me);
			me->add("neili", me->query_skill("beiming-shengong") ); 
			target->add("neili", -1 * ( me->query_skill("beiming-shengong") ) ); 
		}
		target->start_busy(3+random(2));
		me->start_busy(3+random(2));
		remove_call_out("tie_hit");
		call_out("tie_hit",2+random(2), me,target);
		return;
	}

	if( target->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N������$N��������һ������һ������˿�ȥ����ͨһ�죬ˤ���������⡣\n\n" NOR, target);
		target->receive_wound("qi", (int)target->query("eff_qi"), me);
		target->receive_damage("qi", (int)target->query("eff_qi")+1,  me);
		return;
	}

	if( me->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N����ͻȻ��ʧȴ���ƣ������ˮ���ģ���ʱҪ���̶��������֮�䣬ֻ��ȫ�����Ѩ����ͬʱ����������֮�࣬��֪���˾������Σ���ǰһ�ڣ���ʲô���������ˡ�\n\n" NOR, me);
		me->receive_wound("qi", (int)me->query("eff_qi"), target);
		me->receive_damage("qi", (int)me->query("eff_qi")+1,  target);
	}
}