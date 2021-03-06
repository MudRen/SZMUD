// xiuxi.c 玉女心经过关exert
// by April 01/08/21

#include <ansi.h>

/*
$n一声清啸，凝运内力，将双手按在$N身上，帮助$N过关！
$N身体不停的颤抖热汗从脸上一点一点的冒了出来，脸色也变白了，看样子正在过内功修炼的难关！
$N汗如雨下，一会脸色变的红润，一会又变的萨白，全靠$n的真气才得以继续维持突破玉女心经的难关！
*/

string *phases_me = ({
	"你正在修炼玉女心经，真气运行至“少阴”经“太阴”走“少阳” \n",
	"你终于功至“阳明”，头上产生微微白气正是内功到了火候之象！\n",
	"你修炼玉女心经已经有了一段时候，周身白雾丝丝缕缕，渐渐集聚。\n",
	"你加紧运功，真气行遍全身，练功时发出的热量变成的白气渐渐将你笼罩了起来，好象腾云驾雾一般！\n",
	"你修习玉女心经时间越来越长，头顶凝聚白气也越来越多，如同置身于蒸笼之中！\n",
	"你的真气运行得越来越畅快，身体所发的热气也越来越多，已将身体包围了起来！\n",
	"你只觉得一股股暖流自内而外缓缓发散，心底更加沉寂，无欲无喜。\n",
});

int xiuxi(object me);
int halt_xiuxi(object me);

int exert(object me, object target)
{
	object 	where = environment(me);
	int xj_lvl_me = (int)me->query_skill("yunu-xinjing", 1);	//玉女心经等级me
	int force_lvl_me = (int)me->query_skill("force", 1);		//基本内功等级me
	int xj_lvl_target; 	//玉女心经等级target
	int force_lvl_target;		//基本内功等级target
	int v,i,j,k;		// 临时变量
	string *sname;	// skill名字
	object *inv;	// 身上带的东西
	mapping skl;	// 所有skill

	seteuid(getuid());

    if( !objectp(target) || target == me )
		return notify_fail("你想要谁助你过关啊？\n");

	//非婚男女只能在花房树屋练功
	if( target->query("gender") != me->query("gender")
		&& !me->is_spouse_of(target)
		&& where->query("short") != "花房树屋" )
		return notify_fail("你们俩在一起练功？羞不羞啊！\n");

	if ( (xj_lvl_me>=270) && ((object)target->query_temp("pending/guoguan") != me ) )
		return notify_fail("你的玉女心经已经大成，再也没有关可过了。 \n");

	if ( (xj_lvl_me+1)/30*30 != xj_lvl_me+1 
		&& (object)target->query_temp("pending/guoguan") != me )
		return notify_fail("你好像还没到过关的时候。\n");

	xj_lvl_target = (int)target->query_skill("yunu-xinjing", 1);	//玉女心经等级
	force_lvl_target = (int)target->query_skill("force", 1);		//基本内功等级

	if ( (object)target->query_temp("pending/guoguan") != me ){
		if ( xj_lvl_target < xj_lvl_me/2 ) return notify_fail("你们俩武功差距太大了！\n");
		else if ( xj_lvl_target < xj_lvl_me *2/3 && !me->is_spouse_of(target))
			return notify_fail("你们俩武功差距太大了！\n");
	}

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (where->query("sleep_room"))
		return notify_fail("在睡房里不能练玉女心经，这会影响他人。\n");

	if (where->query("no_fight"))
		return notify_fail("在这里练玉女心经，你始终心烦意乱，无法克制，只得作罢。\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
	if (target->is_busy() || target->query_temp("pending/exercising"))
		return notify_fail("你的伙伴现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中过关？你找死啊？\n");
	if( target->is_fighting() )
		return notify_fail("等你的伙伴打完架再说吧。\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");
	if( !stringp(target->query_skill_mapped("force")) )
		return notify_fail("你的伙伴好像不喜欢玉女心经。\n");

	if( me->query("rided") )
		return notify_fail("在坐骑上运功，会走火入魔的。\n");
	if( target->query("rided") )
		return notify_fail("还是先让你的伙伴从坐骑上下来吧。\n");

	// 四周必须无异性
	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "人类" 
			&& inv[i] != me && inv[i] != target
			&& !me->is_spouse_of(inv[i]) 
			&& inv[i]->query("gender") != me->query("gender") )
		return notify_fail("众目睽睽之下脱光衣裳练功，你不嫌害臊吗？！\n");


	// 基本内功小于玉女心经60%不能练
	if( force_lvl_me < xj_lvl_me*60/100)
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");
	if( force_lvl_target < xj_lvl_target*60/100)
		return notify_fail("你的伙伴基本功太差了。\n");

	// lvl小于30不能练
	if (xj_lvl_target<25)
		return notify_fail("你的伙伴功力还不够。\n");

	// 必须空手
	if ( me->query_temp("weapon") )
        return notify_fail("练习玉女心经必须空手，静坐诚心方可。\n");
	if ( target->query_temp("weapon") )
        return notify_fail("先让你的伙伴把兵器放下吧。\n");

	// 必须裸体
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("穿着衣服过关，热气不能及时发散，太凶险了。\n");
	inv = all_inventory(target);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("你的伙伴看来还不打算帮你。\n");

	// 内功要纯，否则大伤元气
	k=0;
	skl=me->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		return notify_fail("你感觉体内不同内力互相冲撞，只得作罢。\n");
	}
	k=0;
	skl=target->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		return notify_fail("你的伙伴内功不太纯啊!\n");
	}

	if( (int)me->query("neili") < (int)me->query("max_neili") )
		return notify_fail("你体内的真气不够修习玉女心经。\n");
	if( (int)target->query("neili") < (int)target->query("max_neili") )
		return notify_fail("你的伙伴真气不足。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi"))
		return notify_fail("你身受内伤，只怕一运真气便有生命危险！\n");
	if( (int)target->query("eff_qi") < (int)target->query("max_qi"))
		return notify_fail("你的伙伴身受内伤，先帮他疗伤吧！\n");

	if( (int)me->query("eff_jing") < (int)me->query("max_jing"))
		return notify_fail("你中的毒没完全好，只怕一运真气便有生命危险！\n");
	if( (int)target->query("eff_jing") < (int)target->query("max_jing"))
		return notify_fail("你的伙伴中的毒没完全好！\n");

	if( (int)me->query("jing") < (int)me->query("max_jing") )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
	if( (int)target->query("jing") < (int)target->query("max_jing") )
		return notify_fail("你的伙伴现在精不够，无法控制内息的流动！\n");

	if( (int)me->query("jingli") < (int)me->query("max_jingli") )
		return notify_fail("你现在精力不够，无法控制内息的流动！\n");
	if( (int)target->query("jingli") < (int)target->query("max_jingli") )
		return notify_fail("你的伙伴现在精力不够，无法控制内息的流动！\n");

	if( (int)me->query("qi") < (int)me->query("max_qi") )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
	if( (int)target->query("qi") < (int)target->query("max_qi") )
		return notify_fail("你的伙伴现在的气太少了，无法产生内息运行全身经脉。\n");


	if ( (object)target->query_temp("pending/guoguan") != me )
	{
		me->set_temp("pending/guoguan",target);
		message_vision("\n$N拱手对著$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，请问"
			+ RANK_D->query_respect(target) + "能帮我过关吗？\n\n", me, target);
		tell_object(target, YEL "如果你愿意帮对方过关，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 yun guoguan 指令。\n" NOR);
		return 1;
	}
	else
	{
		message_vision("\n$N解开衣衫，盘膝坐下，与$n四掌相对，开始助$n过关。\n" , me, target);
		me->set_temp("pending/target",target);
		me->set_temp("pending/xiuxi", 3);
		me->start_busy((: xiuxi :), (:halt_xiuxi:));
		target->set_temp("pending/xiuxi", 4);
		target->set_temp("pending/target",me);
		target->start_busy((: xiuxi :), (:halt_xiuxi:));
	}
	
	return 1;
}

int xiuxi(object me)
{
	string wiz_report;	//巫师报告
	object where = environment(me);	//地理环境
	object target = (object)me->query_temp("pending/target");	//伙伴
	int xj_lvl_target = (int)target->query_skill("yunu-xinjing",1);	//伙伴心经级别
	int xj_lvl = (int)me->query_skill("yunu-xinjing",1);	//心经级别
	int time;	//所需时间
	object *inv;
	int i;

//	if( wizardp(me) ) tell_object(me, "pending/exercise=me" +chinese_number(me->query_temp("pending/exercise"))+"\n");
//	if( wizardp(me) ) tell_object(me, "pending/exercise=target" +chinese_number(target->query_temp("pending/exercise"))+"\n");

	//伙伴停就停
	if( target->query_temp("pending/xiuxi") < 3 )
	{
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
//		write(HIR"\n突然，你发现已经没有同伴的帮助了！你的内力不受控制，如洪水般向各大经脉冲去！\n\n"NOR
//			+HIR"你走火入魔了！！\n"NOR);
//		me->apply_condition("zouhuo_damage",100);
		return 0;
	}

	if( me->query_skill_mapped("force") != "yunu-xinjing" ){
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
		return 0;
	}
	
/*
	if( target->is_fighting() ){
		write("突然，你发现你的伙伴正在和人打斗，连忙停了下来。\n");
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
		return 0;
	}
*/

	if( me->is_fighting() ){
		if( me->query_temp("pending/xiuxi")>3 ){
			write(HIR"\n突然，你遭到袭击！你的内力不受控制，如洪水般向各大经脉冲去！\n\n"NOR
				+HIR"你走火入魔了！！\n"NOR);
			me->apply_condition("zouhuo_damage",100);
		}
		else{
			write(HIR"\n突然，你遭到袭击！\n"NOR
				+HIR"你已无法再帮助同伴过关了！！\n"NOR);
		}
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target", me);
		return 0;
	}

	// 必须裸体
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2){
		write(HIR"突然，你体内热气逐渐积聚，无法发散！热气顿时在五脏六腑翻江倒海，难以克制。 \n"NOR
			+HIR"你走火入魔了！！\n"NOR);
		me->set_temp("pending/xiuxi", 0);
		me->set_temp("pending/target",me);
		me->apply_condition("zouhuo_damage",100);
		return 0;
	}

	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "人类" 
			&& inv[i] != me && inv[i] != target
			&& !me->is_spouse_of(inv[i]) 
			&& inv[i]->query("gender") != me->query("gender") ){
			if( me->query("gender") == "女性") {
				write("突然，你发现有人正盯着你看！\n");
				if( inv[i]->query("family/family_name")=="古墓派"){
					write("你不禁勃然大怒！\n");
					command("say 你竟敢偷看我练功，我告诉师傅去！");
				}
				else{
					write(HIR"\n你又羞又急。再也不能集中精力控制你的内力！\n\n"NOR
						+HIR"你走火入魔了！！\n"NOR);
					me->apply_condition("zouhuo_damage",100);
				}
			}
			else write("突然，你发现有人走了过来！\n你们慌忙中止练功。\n");

			me->set_temp("pending/xiuxi", 0);
			me->set_temp("pending/target",me);
			return 0;
		}

	time = to_int(sqrt(xj_lvl)*10);

	if (me->query_temp("pending/xiuxi") > 3 ){
		if (me->query_temp("pending/xiuxi") < time){
			me->set_temp("pending/xiuxi", me->query_temp("pending/xiuxi") +1);
//	  		if( wizardp(me) ) tell_object(me, "已完成百分之"+chinese_number(me->query_temp("pending/xiuxi")*100/time) +" \n");
//	  		tell_object(me, "已完成百分之"+chinese_number(me->query_temp("pending/xiuxi")*100/time) +" \n");
	  		tell_object(me, "已完成"+chinese_number(me->query_temp("pending/xiuxi")*10/time) +"成。 \n");

		}
		else{
			if ( me->query("has_xinjing") < (xj_lvl +1)/30 ) {
				me->set("max_neili",me->query("max_neili")+(xj_lvl+1)/2);
				me->set("has_xinjing",(xj_lvl+1)/30);
			}
//			target->set("max_neili",target->query("max_neili")+(xj_lvl_target+1)/4);
			target->add("max_neili",2);

			me->set_skill("yunu-xinjing",xj_lvl+1);
			i= xj_lvl_target;
			i= i*i/2;
			target->improve_skill("yunu-xinjing", i, 0);

			me->set("neili",0);
			me->set("qi",me->query("max_qi")/5);
			me->set("jingli",me->query("max_jingli")/5);
			me->set("jing",me->query("max_jing")/5);

			target->set("neili",target->query("max_neili")/4);
			target->set("qi",target->query("max_qi")/2);
			target->set("jingli",target->query("max_jingli")/2);
			target->set("jing",target->query("max_jing")/2);

			if (me->is_spouse_of(target)){
				me->set_skill("lovingness",me->query_skill("lovingness",1)+1);
				target->set_skill("lovingness",target->query_skill("lovingness",1)+1);
			}

			me->set_temp("pending/target",me);
			me->set_temp("pending/xiuxi",0);
			message_vision("$N和$n运功完毕，内息轻吐，过关的喜悦洋溢在$N的脸上。\n", me,target);
			return 0;
		}
	}

	return 1;

}

int halt_xiuxi(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
	me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/xiuxi", 0);
	me->set_temp("pendinf/target",me);
	return 1;
}

