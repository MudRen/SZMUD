// guizhao.c  �����צ
// by Xuanyuan

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill, exp_effect, dex_effect, skill_effect, damage;
	string str;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�������צ��ֻ����ս����ʹ�á�\n");

	if ((string)me->query("gender")!="Ů��")
		return notify_fail("����Ϊ���ӣ�������ᡸ�����צ�����еİ��\n");

	if(!me->query("lingjiu/guizhao"))
		return notify_fail("�㲻��ʹ�á������צ����\n");

    if( (int)me->query("shen", 1) > 0)
        return notify_fail("�����������ʿ���������á������צ�����������书��\n");

	if ((int)me->query_skill("youming-guizhao", 1) < 180 )
        return notify_fail("�����ڤ��צ�ȼ�����������ʹ�á������צ����\n");    

    if ((int)me->query_skill("claw", 1) < 180 )
        return notify_fail("��Ļ���צ����������죬����ʹ�á������צ����\n");    

    if( (int)me->query_skill("force", 1) < 180 )
        return notify_fail("��Ļ����ڹ���򲻹���ǿ��ʹ�á������צ���������Լ��ľ�����\n");

	if ((int)me->query_skill("xiaowuxiang", 1)<180
		&& (int)me->query_skill("bahuang-gong", 1)<180
		&& (int)me->query_skill("beiming-shengong", 1)<180)
		return notify_fail("�����ң���ڹ���򲻹���\n");

	if ( me->query_skill_mapped("force") != "xiaowuxiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	

    if ((int)me->query("neili") < 800 )
        return notify_fail("����������̫��������ʹ�á������צ����\n");

    if ((int)me->query("max_neili") < 1000 )
        return notify_fail("����������̫��������ʹ�á������צ����\n");

	if (me->query_temp("gz_pfmed")==1)
		return notify_fail("���ʹ����һ�У����ܾۼ��㹻��Ԫ����\n");

	if (!me->query("jiali"))
		return notify_fail("��צ�ϴ������㣬����ʹ�á������צ����\n");

	skill = (int)me->query_skill("youming-guizhao",1);

    message_vision(HIB"\nͻȻ$N��˫�Ʊ�צ������ǰ����糵�㼱ת��Ȧ������˫צ����һ������$n��ת��Ȧ�������ָ����$n����ֱ�²��䡣\n\n"NOR, me, target);

	me->add("neili", -skill);
	me->add("jingli", -skill/4);
	me->set_temp("gz_pfmed",1);
	me->add_temp("gz_pfm",1);
	call_out("recover",1800/skill,me);
	if(userp(target)) target->fight_ob(me);
	else if( !target->is_killing(me) ) target->kill_ob(me);

	exp_effect = me->query("combat_exp")/10*(9+random(21))-target->query("combat_exp")-random(me->query("combat_exp")/10);
	dex_effect = random(me->query_dex()-me->query_temp("gz_pfm"))-random(target->query_dex()*2/3);
	skill_effect = (int)me->query_skill("claw", 1)/4 + random((int)me->query_skill("youming-guizhao", 1))/4
					- (int)me->query_skill("dodge", 1)/4 - random((int)me->query_skill("parry", 1))/4;

	if (exp_effect <= 0 && dex_effect + skill_effect < 0) {
		message_vision(HIY"����$n������$N����ͼ������ͷ�����ɵض�����һ�ߡ�\n\n"NOR, me,target);
		tell_object(me, "�����һצ��ȴ�����մ�����ʱ¶�������Ǳ����м��š�\n\n");
		me->start_busy(3+random(3));
		return 1;
	}
	if (exp_effect <= 0 && dex_effect + skill_effect >= 0) {
		message_vision(HIY"$n��$N����ָ��ץ���Լ��Ŷ��������磬Σ��֮������ͷ���˿�ȥ��\n\n"NOR, me,target);
		return 1;
	}
	if (exp_effect > 0 && dex_effect + skill_effect < 0) {
		damage=me->query_str()*me->query("jiali")/target->query_con();
		if (wizardp(me)) tell_object(me,sprintf("exp_effect:%d, dex_effect + skill_effect:%d, damage:%d \n",exp_effect,dex_effect + skill_effect,damage));
		if (damage<=100) message_vision(CYN "$n��������������������ͷ������㡣���ǿ����ܹ������Ѿ�����һ���亹��\n\n" NOR, me,target);
		else {
				message_vision(HIR "$n��������������������ͷ������㡣��Ȼ�ܹ��˶���Ҫ����һ֫�۰�ȴ�ѱ�$Nץ������������Ѫ�ۣ�\n\n" NOR, me,target);
				target->receive_damage("qi",damage,me);
				str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
				message_vision("($N"+str+")\n", target);
				}
			target->start_busy(3+random(3));
			me->add("neili", -skill);
			me->add("jingli", -skill);
			return 1;
	}
	if (exp_effect > 0 && dex_effect + skill_effect  >= 0) {
		damage=(me->query_str()+me->query("jiali")/10)*skill/100*(5+random(15));
		me->add("neili", -skill*3);
		me->add("jingli", -skill);
		if (wizardp(me)) tell_object(me,sprintf("exp_effect:%d, dex_effect + skill_effect:%d, damage:%d \n",exp_effect,dex_effect + skill_effect,damage));
		if ((int)damage/target->query("eff_qi")*100>=100) {
			message_vision(HIR "$nֻ����ͷ��һ�������������������һ�ߣ�ԭ��$N����צ����$nͷ������������������ָ����\n\n" NOR, me,target);
			target->receive_damage("qi",target->query("max_qi") + 100,me);
			target->receive_wound("qi", target->query("max_qi") + 100, me);
			me->start_busy(2);
			return 1;
		}
		message_vision(CYN"$n��������������������ͷ������㡣\n"NOR, me,target);
		if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
			message_vision(HIR "ֻ�����͵�һ����$n�ļ�ͷƤ�������·��ѱ�����һ��飬����������������Ѫ�ۡ�\n\n" NOR, me,target);
		if ((int)damage/target->query("eff_qi")*100<50)
			message_vision(HIR "ֻ�����͵�һ����$N����צ�Ѳ���$n�ļ�ͷ����ʱѪ����ע��\n\n" NOR, me,target);
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi", damage, me);
			str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
			return 1;
	}

    return 1;
}

int recover(object me)
{
        me->delete_temp("gz_pfmed");
        return 1;
}