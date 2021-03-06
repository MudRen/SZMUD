/* 他当即将紫霞神功都运到了剑上，呼的一剑，当头直劈。令狐冲斜身闪开。岳不群圈 
转长剑，拦腰横削。令狐冲纵身从剑上跃过。岳不群长剑反撩，疾刺他后心，这一剑变招 
快极，令狐冲背后不生眼睛，势在难以躲避。众人"啊"的一声，都叫了出来。令狐冲身 
在半空，既已无处借势再向前跃，回剑挡架也已不及，却见他长剑挺出，拍在身前数尺外 
的木柱之上，这一借力，身子便已跃到了木柱之后，噗的一声响，岳不群长剑刺入木柱。 
剑刃柔韧，但他内劲所注，长剑竟穿柱而过，剑尖和令狐冲身子相距不过数寸。 
    众人又都"啊"的一声。这一声叫唤，声音中充满了喜悦、欣慰和赞叹之情，竟是人 
人都不禁为令狐冲欢喜，既佩服他这一下躲避巧妙之极，又庆幸岳不群终于没刺中他。岳 
不群施展平生绝技，连环三击，仍然奈何不了令狐冲，又听得众人的叫唤，竟是都在同情 
对方，心下大是懊怒。这"夺命连环三仙剑"是华山派剑宗的绝技，他气宗弟子原本不知 
。当年两宗自残，剑宗弟子曾以此剑法杀了好几名气宗好手。当气宗弟子将剑宗的弟子屠 
戮殆尽、夺得华山派掌门之后，气宗好手仔细参详这三式高招"夺命连环三仙剑"。诸人 
想起当日拚斗时这三式连环的威力，心下犹有余悸，参研之时，各人均说这三招剑法入了 
魔道，但求剑法精妙，却忘了本派"以气驭剑"的不易至理，大家嘴里说得漂亮，心中却 
无不佩服。*/
//Cracked by Kafei
//duoming.c 夺命连环三仙剑 
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void chkpfm(object me, object target, int amount);
void remove_effect(object me, object target, int amount);
void check(object me, object target, object weapon, int amount);
int perform(object me, object target)
{
	object weapon, weapon1;
	int lvl1, lvl2, amount, amount2;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("夺命连环三仙剑只能对战斗中的对手使用。\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得夺命连环三仙剑？\n");

	if (!living(target))
		return notify_fail("他已经晕倒了，你可以轻易地杀了他！\n");

	if (time() - target->query_temp("sxj-t") < 10)
		return notify_fail("他已经适应了你的剑招，对他来说已经无效了！\n");
                if( me->query_temp("kuaijian",1) ) 
                      return notify_fail("你正在使用「狂风快剑」!"); 

              if( me->query_temp("yijian",1) ) 
                      return notify_fail("你正在使用「宁氏一剑」!"); 

	if( me->query_skill_mapped("force") != "zixia-gong" )
		return notify_fail("你所用的并非紫霞功，无法施展夺命连环三仙剑！\n");

	if( (lvl1=me->query_skill("zixia-gong", 1)) < 100 )
		return notify_fail("你的紫霞功火候未到，无法施展夺命连环三仙剑！\n");

	if( (lvl2=me->query_skill("sword")) < 200 )
		return notify_fail("你华山剑法修为不足，还不会使用夺命连环三仙剑！\n");

	if( (lvl2 - lvl1) < lvl2 / 4 && lvl1 < 200)
		return notify_fail("夺命连环三仙剑需要更精湛的剑术！\n");

	amount = (lvl1+lvl2) / (2 + random(2));

	if ( amount < 100 ) amount = 100;
	if ( amount > 500 ) amount = 500;

	if( me->query("neili") <= amount * 5 )
		return notify_fail("你的内力不够使用夺命连环三仙剑！\n");
	if( me->query("jingli") <= amount * 3 )
		return notify_fail("你的精力不够使用夺命连环三仙剑！\n");

	if(!me->query_temp("sanxianjian")){
                message_vision(MAG "\n突然间$N吸一口气，脸上紫气大盛，紫霞神功施展出来，"+weapon->name()+MAG"末端隐隐发出光芒，将华山剑法发挥得淋漓尽致。\n\n", me, target);
		me->add_temp("apply/damage", amount*3);
		me->add_temp("apply/attack", amount*2);
		me->add_temp("apply/dodge", amount);
		me->add_temp("apply/speed", amount);
		call_out("check", 1, me, target, weapon, amount);
		me->set_temp("sanxianjian",1);
	        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, amount:), amount/15);
	}
	me->set_temp("sxj-c" , 1);
        message_vision(HIR "\n$N"+HIR+"鼓荡内劲，凝气聚于"+weapon->name()+HIR+"上，忽出杀着，一剑朝$n"+HIR+"当头直劈！！\n" NOR, me, target);
	chkpfm(me, target, amount);
	me->set_temp("sxj-c" , 2);
        message_vision(HIW "\n$N"+HIW+"一剑不中，次招随至，电光石火间圈转"NOR+weapon->name()+HIW"，朝$n"+HIW+"拦腰横削！！\n" NOR, me, target);
	chkpfm(me, target, amount);
	me->set_temp("sxj-c" , 3);
        message_vision(HIY "\n$N"+HIY+"剑势连环，"+weapon->name()+HIY"反撩，疾刺$n"+HIY+"后心，这一剑变招极快，$n背后不生眼睛，势在难以躲避！！\n" NOR, me, target);
	chkpfm(me, target, amount);
	if((int)target->query("eff_qi") * 100 /(int)target->query("max_qi") <= 20
	 &&(int)target->query("qi") * 100 /(int)target->query("max_qi") <= 5
	 && me->query_temp("sxj-c") == 3)
	{
                message_vision(HIR "\n$N"+HIR+"这招内劲所注，力道强横之极，"+weapon->name()+HIR+"竟穿体而过，剑尖刺出$n"+HIR+"前胸数寸！！\n" NOR, me, target);
		if (wizardp(me))
			tell_object(me,HIR"super attack!!\n"NOR);
		target->die();
	}
	if (amount > 250) amount2 = 250;
	me->add("jingli",-amount2);
	me->add("neili",-amount2 * 3 / 2);
	me->start_busy( 1+random(3) );
	return 1;
}
void chkpfm(object me, object target, int amount)
{
	object weapon2 = target->query_temp("weapon");
        string attack_skill, dodge_skill, parry_skill, result, msg = "";
        int ap, dp, pp, damage, level;

        if( !me->is_fighting(target) || !living(target) ) 
                return;

	level = me->query_skill("sword");
	damage = amount + random(level);
	ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( target->is_busy() ) dp /= 3;
	if( dp < 1 ) dp = 1;
	if( random(ap + dp) < dp )
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg();
	}
	else
	{
		pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
		if( target->is_busy() ) pp /= 2;
		if( pp < 1 ) pp = 1;

		if( random(ap + pp) < pp )
		{
			parry_skill = target->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
				parry_skill = "parry";
			msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
		}
		else 
		{
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/3, me);
			if (me->query_temp("sxj-c") == 3)
				result = COMBAT_D->damage_msg(damage, "刺伤");
			else result = COMBAT_D->damage_msg(damage, "劈伤");
			msg += result;
			result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
				(int)target->query("max_qi"));
			msg += "( $n"+result+" )\n";
		}
	}
	if (me->query_temp("sxj-c") == 1)
		msg = replace_string( msg, "$l", "头顶" );
	if (me->query_temp("sxj-c") == 2)
		msg = replace_string( msg, "$l", "腰间" );
	if (me->query_temp("sxj-c") == 3)
		msg = replace_string( msg, "$l", "后心" );
	msg = replace_string( msg, "$w", (me->query_temp("weapon"))->name());
	message_vision(msg, me, target);
	return;
}
void remove_effect(object me, object target, int amount)
{
        if (!me || !me->query_temp("sanxianjian")) return;
	me->delete_temp("sanxianjian");
	if( me->is_fighting() && living(target))
	{
		message_vision(HIY "\n$n慢慢的适应了$P夺命连环三仙剑的剑风。\n" NOR, me, target);
		target->set_temp("sxj-t",time());
	}
	else message_vision(HIY "\n只见$N收回内劲,剑招也恢复了平常。\n" NOR, me);
	me->add_temp("apply/damage", -amount*3);
	me->add_temp("apply/attack", -amount*2);
	me->add_temp("apply/dodge", -amount);
	me->add_temp("apply/speed", -amount);
}
void check(object me, object target, object weapon, int amount)
{
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
	{
		if(!me) return;
		if( me->query_temp("sanxianjian") )
                        message_vision(CYN "\n$N手中无剑，剑风顿时消失！\n"NOR, me);
		remove_effect(me, target, amount);
		return;
	}
	call_out("check", 1, me, target, weapon, amount);
}
