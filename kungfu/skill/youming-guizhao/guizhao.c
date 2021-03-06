// guizhao.c  亡魂鬼爪
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
                return notify_fail("「亡魂鬼爪」只能在战斗中使用。\n");

	if ((string)me->query("gender")!="女性")
		return notify_fail("你身为男子，难以领会「亡魂鬼爪」其中的奥妙。\n");

	if(!me->query("lingjiu/guizhao"))
		return notify_fail("你不能使用「亡魂鬼爪」。\n");

    if( (int)me->query("shen", 1) > 0)
        return notify_fail("你是侠义道人士，怎麽能用「亡魂鬼爪」这种阴毒武功。\n");

	if ((int)me->query_skill("youming-guizhao", 1) < 180 )
        return notify_fail("你的幽冥鬼爪等级不够，不能使用「亡魂鬼爪」。\n");    

    if ((int)me->query_skill("claw", 1) < 180 )
        return notify_fail("你的基本爪法极不够娴熟，不能使用「亡魂鬼爪」。\n");    

    if( (int)me->query_skill("force", 1) < 180 )
        return notify_fail("你的基本内功火候不够，强行使用「亡魂鬼爪」会震伤自己的经脉。\n");

	if ((int)me->query_skill("xiaowuxiang", 1)<180
		&& (int)me->query_skill("bahuang-gong", 1)<180
		&& (int)me->query_skill("beiming-shengong", 1)<180)
		return notify_fail("你的逍遥派内功火候不够。\n");

	if ( me->query_skill_mapped("force") != "xiaowuxiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	

    if ((int)me->query("neili") < 800 )
        return notify_fail("你现在真气太弱，不能使用「亡魂鬼爪」。\n");

    if ((int)me->query("max_neili") < 1000 )
        return notify_fail("你现在内力太弱，不能使用「亡魂鬼爪」。\n");

	if (me->query_temp("gz_pfmed")==1)
		return notify_fail("你刚使过这一招，不能聚集足够的元气。\n");

	if (!me->query("jiali"))
		return notify_fail("你爪上带力不足，不能使用「亡魂鬼爪」。\n");

	skill = (int)me->query_skill("youming-guizhao",1);

    message_vision(HIB"\n突然$N将双掌变爪合于胸前，象风车般急转数圈，而后双爪向外一翻绕着$n疾转数圈，五根手指向着$n顶门直下插落。\n\n"NOR, me, target);

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
		message_vision(HIY"可是$n看破了$N的企图，闪身护头，轻巧地躲在了一边。\n\n"NOR, me,target);
		tell_object(me, "你奋力一爪，却击到空处，登时露出空门狼狈的招架着。\n\n");
		me->start_busy(3+random(3));
		return 1;
	}
	if (exp_effect <= 0 && dex_effect + skill_effect >= 0) {
		message_vision(HIY"$n见$N的手指已抓到自己门顶不及数寸，危机之中闪身护头躲了开去。\n\n"NOR, me,target);
		return 1;
	}
	if (exp_effect > 0 && dex_effect + skill_effect < 0) {
		damage=me->query_str()*me->query("jiali")/target->query_con();
		if (wizardp(me)) tell_object(me,sprintf("exp_effect:%d, dex_effect + skill_effect:%d, damage:%d \n",exp_effect,dex_effect + skill_effect,damage));
		if (damage<=100) message_vision(CYN "$n见此招来势凌厉，闪身护头向后闪躲。虽是堪堪避过，早已惊出了一身冷汗。\n\n" NOR, me,target);
		else {
				message_vision(HIR "$n见此招来势凌厉，闪身护头向后闪躲。虽然避过了顶门要害，一肢臂膀却已被$N抓出五条长长的血痕！\n\n" NOR, me,target);
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
			message_vision(HIR "$n只觉得头顶一阵麻痒，就软软地歪在一边，原来$N的手爪已在$n头顶留下五个整整齐齐的指洞！\n\n" NOR, me,target);
			target->receive_damage("qi",target->query("max_qi") + 100,me);
			target->receive_wound("qi", target->query("max_qi") + 100, me);
			me->start_busy(2);
			return 1;
		}
		message_vision(CYN"$n见此招来势凌厉，闪身护头向后闪躲。\n"NOR, me,target);
		if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
			message_vision(HIR "只听噗嗤的一声，$n的肩头皮肉连带衣服已被扯下一大块，留下了五条长长的血痕。\n\n" NOR, me,target);
		if ((int)damage/target->query("eff_qi")*100<50)
			message_vision(HIR "只听噗嗤的一声，$N的手爪已插入$n的肩头，顿时血流如注。\n\n" NOR, me,target);
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