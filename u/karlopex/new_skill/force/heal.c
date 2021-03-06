//Cracked by Roath
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **\
 * heal.c 内功治疗内伤功能						*
 *									*
 * 内功应该拥有几种共有的功能，像已有的打坐、吐呐、运气、运精、运精力， *
 * 以及开放中的比拼内力。其中运转内息治疗内伤也应该是所有内功都应该有的 *
 * 功能。								*
 * 侠客行现有的伤害系统，在内伤和外伤完全没有区别。内伤外伤是两码子事， *
 * 内功高，内伤自然容易好。外伤却未必，又不是神功一运，立即镇伤生肌，那 *
 * 变成生化人了。所以外伤在大部份情况下只能借助于外界药物的辅助来治疗。	*
 * 基本上普通内伤都可以通过运转内息来治疗，所差者不过於不同内功在於治疗 *
 * 方面效果的好坏，而且如果伤势越重，效果越小，不像以前侠客行一次多少内 *
 * 力、就固定恢复多少。通过内伤的康复，慢慢会加快治愈速度。而外伤的康愈 *
 * 速度，多半则取决于其伤势的程度，所用药物的药性，以及本身的肌肉构造， *
 * 也就是侠客行里面的constitution。					*
 * 至于如何体现出内外伤的不同，而将侠客行的伤害系统做得更合理性，这些是 *
 * 以后所要改变的，这里所要说明的只是以下功能只是以内伤作为前提考虑，所 *
 * 以或许对于现侠客行现有的伤害系统会有少许的不合理性。			*
 *									*
 * Maco && xQin 11/99							*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

#include <ansi.h>

int curing(object);
int halt_curing(object);
void remove_pending(object, object);

mapping eff_heal = ([
	"jiuyang-shengong"	: 9,	// 九阳神功在疗伤方面的效果无可置疑。
	"hunyuan-yiqi"		: 8,	// 鉴於易筋经以及九阳神功在疗伤方面的效果。
	"zixia-gong"		: 8,
// 紫霞神功及混元功在自疗方面没有什么提及，但是有鉴於其疗人的效果，以及岳不群曾经想让令狐冲
// 自习紫霞神功来治疗内伤，可见於自疗方面的效果，或许可以与易筋经相媲美。就算是有所不及，考
// 虑到当今紫霞神功没有什么特别的exert，也应当让紫霞神功在治疗方面的效果相对於其他内功更好。
	"taiji-shengong"	: 8,
	"xiantian-gong"		: 8,	// 书中有相当篇幅提到武当九阳功与全真玄门内功的疗伤。
	"kurong-changong"	: 6,	// 大理内功在疗人方面的效果很好，可是在自疗方面却没
					// 有什么特别之处。
	"linji-zhuang"		: 6,	// 峨嵋内功在疗伤方面没有什么特别描述，不过因其是九
					// 阳一系。
	"taixuan-gong"		: 5,
	"bitao-xuangong"	: 5,
	"yunu-xinjing"		: 5,
	"xiaowuxiang"		: 5,
	"huntian-qigong"	: 4,	// 混天功、蛤蟆功、龙象般若功走的都是刚猛一路的内功，
	"hamagong"		: 4,	// 因此在疗伤方面会相对弱些。
	"longxiang-banruo"	: 4,
	"beiming-shengong"	: 3,	// 北冥神功吸人内力，体内真气相冲会影响疗伤时的效果。
	"huagong-dafa"		: 2,	// 化功大法以毒练功，在疗伤方面效果应该最为不好。
	"dulong-dafa"		: 2,
	"hongming-xuangong"	: 1,
	"ding-force"		: 1,	// 以上三种内功书中未有提及，被列为不可考。
]);

int exert(object me, object target)
{
	string force_skill;
	mapping msg;
	int mode;

	if( !wizardp(me) || !wizardp(target)) return 0;
	if( !target ) target == me;
	if( target == me ) mode = 1;
	else mode = 2;
	
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( me->is_busy() || me->query_temp("exit_blocked") )
		return notify_fail("你现在正忙着呢。\n");

	if( me->query_temp("cursed") )
		return notify_fail("什么？\n");

	if( me->query("rided") )
		return notify_fail("在坐骑上运功疗伤，会走火入魔。\n");

	if( !(force_skill = me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( me->query_skill("force", 1) < 50 )
		return notify_fail("你对内功的认识还不够，不知如何搬运内息疗伤。\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力修为太低，尚无法搬运内息疗伤。\n");

	msg = SKILL_D(force_skill)->curing_msg(me, target);

	if ( mode == 1 ) {			
		if( (int)me->query("neili") < 50 )
			return notify_fail("你体内的真气不够。\n");
	
		if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
			return notify_fail("你并未受到内伤。\n");
	
		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	
		if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
			return notify_fail("你现在精不够，无法控制内息的流动！\n");
	
		if( !msg || undefinedp(msg["start_self"]) )
			tell_object(me, HIW"你全身放松，坐下来开始运功疗伤。\n"NOR);
		else	tell_object(me, msg["start_self"]);
	
		if( !msg || undefinedp(msg["start_other"]) )
			message("vision", me->name() +"盘膝坐下，开始运功疗伤。\n"NOR,
				environment(me), me);
		else	message("vision", msg["start_other"], environment(me), me);
	
		if( !msg || undefinedp(msg["apply_short"]) )
			me->set_temp("apply/short", ({ me->name() +"正坐在地下运功疗伤。"}));
		else	me->set_temp("apply/short", ({ msg["apply_short"] }));
	
		me->set_temp("pending/curing", 1);
		me->set_temp("pending/mode", 1);
		me->start_busy((: curing :), (: halt_curing :));
		me->set("jiali", 0);
		return 1;
	} else {
		if ( objectp(target->query_temp("pending/heal_other")) && target->query_temp("pending/heal_other") != me)
			return notify_fail((target->query_temp("pending/heal_other"))->name()+"正在为"+target->name()+"疗伤。\n");

		if ( (int)me->query_skill(force_skill , 1) < 50 )
			return notify_fail("你"+to_chinese(force_skill)+"的造诣太浅，不能为他人疗愈内伤！\n");

		if( (int)me->query("max_neili") < 300 )
			return notify_fail("你的内力修为不够。\n");

		if( (int)me->query("neili") < 150 )
			return notify_fail("你的内力不足以为"+target->name()+"疗伤。\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"已经受伤过重，经受不起你的真气震荡！\n");

		if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
			return notify_fail( target->name() +"没有受伤，不用你帮他疗伤！\n");

		if( !living(target) )
			return notify_fail("此人已昏死或死了，不能救治！\n");

		if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
			return notify_fail("你现在精不够，无法控制内息的流动！\n");
	
		if( !msg || undefinedp(msg["start_healother_self"]) ){
			tell_object(me, HIW"你全身放松，坐下来开始为"+ target->name() +"运功疗伤。\n"NOR);
			tell_object(target, HIW"你全身放松，坐下来让"+ me->name() +"为自己运功疗伤。\n"NOR);
		} else {
			tell_object(me, msg["start_healother_self"]["me"]);
			tell_object(target, msg["start_healother_self"]["target"]);
		}
			
		if( !msg || undefinedp(msg["start_healother_other"]) )
			message("vision", me->name() +"盘膝坐下，开始为"+ target->name() +"运功疗伤。\n"NOR,
				environment(me), ({ me, target}));
		else	message("vision", msg["start_healother_other"], environment(me), ({ me, target}));
	
		if( !msg || undefinedp(msg["apply_short_other"]) ){
			me->set_temp("apply/short", ({ me->name() + "正坐在地下为" + target->name() + "运功疗伤。"}));
			target->set_temp("apply/short", ({ target->name() + "正坐在地下，" + me->name() + "正在为他运功疗伤。"}));
		} else {
			me->set_temp("apply/short", ({ msg["apply_short_other"]["me"] }));
			target->set_temp("apply/short", ({ msg["apply_short_other"]["target"] }));
		}
		
		me->set_temp("pending/curing_other", 1);
		me->set_temp("pending/mode", 2);
		me->set_temp("pending/heal_other", target);
		target->set_temp("pending/mode", 3);
		target->set_temp("pending/heal_other", me);
		target->set_temp("pending/curing_other", 1);
		me->start_busy((: curing :), (: halt_curing :));
		target->start_busy((: curing :), (: halt_curing :));
		me->set("jiali", 0);
		return 1;
	}
}

int curing(object me)
{
	int effect, lvl, con, max, eff, mode = me->query_temp("pending/mode");
	string force_skill;
	mapping msg;
	object target = me->query_temp("pending/heal_other");

	if(mode == 1){
		if( !living(me) || me->is_ghost() || !(force_skill = me->query_skill_mapped("force")) )
		{
			remove_pending(me, target);
			return 0;
		}

		msg = SKILL_D(force_skill)->curing_msg(me);		

		if( me->query("jing") < 1 || me->query("jingli") < 1 )
		{
			remove_pending(me, target);
			me->unconcious();
			return 0;
		}
		else if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		{
			if( !msg || undefinedp(msg["finish_self"]) )
				tell_object(me, HIY"你运功良久，自觉经脉顺畅，内伤尽去，神元气足地站了起来。\n"NOR);
			else	tell_object(me, msg["finish_self"]);
		
			if( !msg || undefinedp(msg["finish_other"]) )
				message("vision", me->name() +"运功完毕，站起身来，看上去气色饱满，精神抖擞。\n"NOR,	environment(me), me);
			else	message("vision", msg["finish_other"], environment(me), me);
		
			remove_pending(me, target);
			return 0;
		}
		else if( (int)me->query("neili") < 50 )
		{
			if( !msg || undefinedp(msg["unfinish_self"]) )
				tell_object(me, "你正在运功疗伤，忽觉内息後继乏力，祗得暂缓疗伤，站起身来。\n"NOR);
			else	tell_object(me, msg["unfinish_self"]);
		
			if( !msg || undefinedp(msg["unfinish_other"]) )
				message("vision", me->name() +"运功完毕，缓缓站了起来，脸色看起来好了许多。\n"NOR,environment(me), me);
			else	message("vision", msg["unfinish_other"], environment(me), me);
		
			remove_pending(me, target);
			return 0;
		}
		
		lvl = me->query_skill("force");	// my enable force level.
		max = me->query("max_neili");	// my max neili.
		con = me->query("con");		// my original constitution.
		eff = eff_heal[force_skill];	// my force's effect on heal.
		if( !eff ) eff = 1;
		
		effect = lvl * max/10 * eff / (2*lvl + lvl*con*2/30) / 10;
		
		con = me->query_con();		// use apply constitution instead of original here.
		effect = (effect+random(effect))/2 + (con+random(con))/4;
		effect = effect * ((int)me->query("eff_qi")*100 / (int)me->query("max_qi")) / 100;
		
		if( wizardp(me) ) tell_object(me, "每次治愈"+chinese_number(effect)+"点内伤。\n");
		me->receive_curing("qi", effect);
		me->receive_heal("qi", effect/2);
		me->add("neili", -50);
		return 1;
	} else if(mode == 2){
		if( !living(me) || me->is_ghost() || !(force_skill = me->query_skill_mapped("force"))
		 || !living(target) || target->is_ghost())
		{
			remove_pending(me, target);
			return 0;
		}

		msg = SKILL_D(force_skill)->curing_msg(me, target);
		
		if( me->query("jing") < 1 || me->query("jingli") < 1 )
		{
			remove_pending(me, target);
			me->unconcious();
			return 0;
		}
		else if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
		{
			if( !msg || undefinedp(msg["finish_healother_self"]) ){
				tell_object(me, HIY"你运功良久，只觉"+target->name()+"的气息均匀，内伤已经痊愈，便收起内功站了起来。\n"NOR);
				tell_object(target, HIY"你只觉气息均匀，内伤已经痊愈，这时"+me->name()+"收起内功站起来，你也运了一下内功，站了起来。\n"NOR);
			} else {
				tell_object(me, msg["finish_healother_self"]["me"]);
				tell_object(target, msg["finish_healother_self"]["target"]);
			}
					
			if( !msg || undefinedp(msg["finish_healother_other"]) )
				message("vision", me->name() +"感觉"+target->name()+"的气息均匀，内伤已经痊愈，便收起内功站了起来。\n"NOR,	environment(me), me);
			else	message("vision", msg["finish_healother_other"], environment(me), ({ me, target}));
		
			remove_pending(me, target);
			return 0;
		}
		else if( (int)me->query("neili") < 50 )
		{
			if( !msg || undefinedp(msg["unfinish_healother_self"]) ){
				tell_object(me, "你正在运功为"+target->name()+"疗伤，忽觉内息後继乏力，祗得暂缓疗伤，站起身来。\n"NOR);
				tell_object(target, "你只觉得"+me->name()+"的内息时断时续，似是内力不足，祗得让"+me->name()+"暂缓为你疗伤。\n"NOR);
			} else {
				tell_object(me, msg["unfinish_healother_self"]["me"]);
				tell_object(target, msg["unfinish_healother_self"]["target"]);
			}
				
			if( !msg || undefinedp(msg["unfinish_healother_other"]) )
				message("vision", me->name() +"运功完毕，缓缓站了起来，"+target->name()+"的脸色看起来好了一些。\n"NOR,environment(me), me);
			else	message("vision", msg["unfinish_healother_other"], environment(me), ({ me, target}));
		
			remove_pending(me, target);
			return 0;
		}
		
		lvl = me->query_skill("force");	// my enable force level.
		max = me->query("max_neili");	// my max neili.
		con = me->query("con");		// my original constitution.
		eff = eff_heal[force_skill];	// my force's effect on heal.
		if( !eff ) eff = 1;
		
		effect = lvl * max/10 * eff / (2*lvl + lvl*con*2/30) / 15;
		
		con = target->query_con();		// use apply constitution instead of original here.
		effect = (effect+random(effect))/2 + (con+random(con))/4;
		effect = effect * ((int)target->query("eff_qi")*100 / (int)target->query("max_qi")) / 100;
		
		if( wizardp(me) ) tell_object(me, "每次治愈"+target->name()+chinese_number(effect)+"点内伤。\n");
		if( wizardp(me) ) tell_object(target, me->name()+"每次治愈你"+chinese_number(effect)+"点内伤。\n");
		target->receive_curing("qi", effect);
		target->receive_heal("qi", effect/2);
		me->add("neili", -(50 + random(con)));
		return 1;
	} else {
		if( !living(me) || me->is_ghost() || !living(target) || target->is_ghost() )
		{
			remove_pending(me, target);
			return 0;
		}
		return 1;		
	}
}

int halt_curing(object me)
{
	int mode = me->query_temp("pending/mode");
	string force_skill;
	mapping msg;
	object target = me->query_temp("pending/heal_other");
	
	force_skill = me->query_skill_mapped("force");
	if( force_skill ) msg = SKILL_D(force_skill)->curing_msg(me, target);

	me->receive_damage("qi", 50, "内功走火入魔死了");
	me->add("neili", -50);
	if( me->query("neili") < 0 ) me->set("neili", 0);

	if(mode == 1){
		if( !msg || undefinedp(msg["halt_self"]) )
			tell_object(me, "你吐气纳息，硬生生地将内息压了下去，缓缓站了起来。\n");
		else	tell_object(me, msg["halt_self"]);
	
		if( !msg || undefinedp(msg["halt_other"]) )
			message("vision", me->name() +"身子一震，吐出一口瘀血，缓缓站了起来。\n", environment(me), me);
		else	message("vision", msg["halt_other"], environment(me), me);
	
	       	remove_pending(me, target); 
		me->start_busy(1+random(3));
		return 1;
	} else if(mode == 2){
		if( !msg || undefinedp(msg["halt_healother_self"]) ){
			tell_object(me, "你吐气纳息，慢慢地将内息压了下去，缓缓站了起来。\n");
			tell_object(target, "你只觉"+me->name()+"慢慢地将内息收了回去，待得没有了内息，你缓缓站了起来。\n");
		}else{
			tell_object(me, msg["halt_healother_self"]["me"]);
			tell_object(target, msg["halt_healother_self"]["target"]);
		}
			
		if( !msg || undefinedp(msg["halt_healother_other"]) )
			message("vision", target->name() +"身子一震，吐出一口瘀血，"+me->name()+"收起内功缓缓站了起来。\n", environment(me), ({ me, target}));
		else	message("vision", msg["halt_healother_other"], environment(me), ({ me, target}));
	
	       	remove_pending(me, target); 
		me->start_busy(1+random(3));
		target->start_busy(1+random(3));
		return 1;
	} else {
		tell_object(me, "你在"+target->name()+"耳边轻声说道：不用为我疗伤了。\n你侍"+target->name()+"内功收回后缓缓站了起来。\n");
		tell_object(target, me->name()+"在你耳边轻声说道：不用为我疗伤了。\n你知道"+me->name()+"的内伤好了一些，便收起内功缓缓站了起来。\n");
		message("vision", me->name() +"在"+target->name()+"耳边轻声说了些什么，"+target->name()+"收起内功和"+me->name()+"一起缓缓站了起来。\n", environment(me), ({ me, target}));

	       	remove_pending(me, target); 
		me->start_busy(1+random(3));
		target->start_busy(1+random(3));
		return 1;
	}
}



void remove_pending(object me, object target)
{
	me->delete_temp("pending/curing");
	me->delete_temp("apply/short");
	me->delete_temp("pending/mode");
	me->delete_temp("pending/heal_other");
	if (objectp(target)){
		target->delete_temp("pending/curing");
		target->delete_temp("apply/short");
		target->delete_temp("pending/mode");
		target->delete_temp("pending/heal_other");
	}
}
