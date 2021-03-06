// beehive.c 蜂箱
// by April	01.08.26
// update by April 01.10.30

// temp means
// owner 蜂箱主人
// mi_lvl 已采得蜂蜜数量，每蜂箱最大20
// down 蜂箱是否放在地上
// open 蜂箱门是否开启
// escaped 玉蜂逃走了
// last_place 上次采蜜地点
// mi_left 当地可采蜂蜜数量
// bee_count 玉蜂群数目
// bee_org 玉蜂已经出来列阵
// bees 属于这个蜂箱的玉蜂群
// bee_training 玉蜂正在接受训练

#define MAX_MI 20			//一个蜂箱的满蜜数
#define TICK 10			//auto_check间隔基础时间
#define R_TICK 10		//auto_check间隔附加随机时间
#define T_COST 10		//每tick消耗精力
#define C_COST 20		//callback消耗精力
#define T_EXP 4			//每tick增加exp
#define R_EXP 4			//每tick附加随机exp
#define T_POT 2			//每tick增加pot
#define R_POT 2			//每tick附加随机pot
#define T_BEE 10		//每tick增加bee-traing skill
#define R_BEE 10		//每tick附加随机bee-traing skill
#define RDM	20			//训蜂时出现意外的概率

#include "ansi.h"

//inherit ITEM;
inherit COMBINED_ITEM;

void setup_skill(object me,object obj);
void do_leave(object ob);
void destroy_me(object me);

string *phases = ({
	"玉蜂飞来飞去不停地在花丛中忙碌着。 \n",
	"你口中念念有词，驱赶着玉蜂不让它们飞远。 \n",
	"你警惕地监视着不远处蠢蠢欲动的麻雀。\n",
});

void create()
{
	set_name(HIW "玉蜂箱" NOR, ({ "feng xiang", "beehive", "box", "xiang" }) );
//	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",	HIW"这是古墓派木制的玉蜂箱。里面嗡嗡的，不知道有多少玉蜂。\n"NOR );
		set("base_unit", "个");
        set("value", 1000);
        set("material", "wood");
		set("no_sell", 1);
		set("no_give",0);
		set("no_get",1);
		set("base_weight",5000);
	}

	set("no_refresh", 1);

	set_amount(1);
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("id",1)!="sun popo" ) {
		set("no_drop",  "这么有用的东西怎么能扔了呢。\n");
		set("no_steal", "这个东西你偷不到。\n");
	}

	add_action("do_open", "open");
	add_action("do_close", "close");
	add_action("do_check", "check");
	add_action("do_putdown", "putdown");
	add_action("do_putdown", "fang");
	add_action("do_carry", "tai");
	add_action("do_carry", "carry");
	add_action("do_give", "give");
	add_action("do_qufeng", "qufeng");
	add_action("do_direct", "direct");
	add_action("do_add", "add");
	add_action("do_cai", "cai");

}

int do_open(string arg){
	object me = this_player();
	object ob = this_object();
	string descrp;

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return 0;
	if (ob->query("open")) return notify_fail("你糊涂了？ \n");
	if( ob->query("owner") != me ) return notify_fail("这你的蜂箱吗？\n");
	if(me->is_busy()) return notify_fail("你正忙着呢！ \n");
	if (!ob->query("down"))	return notify_fail("你得先把玉蜂箱放下！ \n");
	if (ob->query("open")) return notify_fail("玉蜂箱门开着呢！ \n");
	if(query("bee_out")) return notify_fail("你的玉蜂群忙着呢！\n");

	if (ob->query("mi_lvl") >= MAX_MI*query_amount()){
		message_vision(HIG"$N轻轻地打开玉蜂箱的门，可是一个玉蜂也没出来。\n"NOR,me);
		return notify_fail("看来玉蜂已经采到足够的蜂蜜了。你只好又关上玉蜂箱的门。\n");
	}

	if (ob->query("escaped")){
		message_vision(HIG"$N轻轻地打开玉蜂箱的门。有几只玉蜂探了探头，又缩了回去。\n"NOR,me);
		return notify_fail("看来玉蜂受了惊吓，你无奈地关上了玉蜂箱的门。\n");
	}

	remove_call_out("auto_check");
	call_out("auto_check", TICK+random(R_TICK) );

	message_vision(HIG"$N轻轻地打开玉蜂箱的门，玉蜂陆陆续续地飞出来，采蜜去了。\n"NOR,me);

	ob->set("open",1);
	ob->set("lastplace",environment(me));
	
	return 1;
}

int do_close(string arg){
	object me = this_player();
	object ob = this_object();
	string descrp;

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return 0;
	if (!ob->query("open")) return notify_fail("你糊涂了？ \n");
	if( ob->query("owner") != me ) return notify_fail("这是你的蜂箱吗？\n");
	if(me->is_busy()) return notify_fail("你正忙着呢！ \n");
	if (!ob->query("down"))	return notify_fail("你得先把玉蜂箱放下！ \n");
	if (!ob->query("open"))	return notify_fail("玉蜂箱门关着呢！ \n");
	if (me->query("jingli")<C_COST+10) return notify_fail("你已经精疲力竭，无法召唤玉蜂回来了！ \n");

	message_vision(HIG"$N口中念念有词，一会儿玉蜂陆陆续续地都飞了回来，$N轻轻关上玉蜂箱门。\n"NOR,me);

	ob->set("open",0);
	ob->set("bee_training",0);
	me->receive_damage("jingli", C_COST, "活活累死了！");

	remove_call_out("auto_check");

	return 1;
}

int do_check()
{
	object me = this_player();
	object ob = this_object();
	int max = MAX_MI*query_amount();
	string descrp;

	if (ob->query("owner"))
		descrp = WHT"这蜂箱里装的是由"+ob->query("owner")->query("name")+"负责驯养的玉蜂群。\n"NOR;
	else {
		descrp = WHT"一个废弃的蜂箱。已经被野蜂占据了。\n"NOR;
		descrp += WHT"你顺手就把它清除了。\n"NOR;
		write(descrp);
		destroy_me(ob);
		return 1;
	}

	if (ob->query("mi_lvl") == 0)
		descrp += WHT"箱里的嗡嗡声连成一片，玉蜂显得烦躁不安，看来得尽快放它们出去采蜜。\n"NOR;
	else if (ob->query("mi_lvl") <= max*3/10)
		descrp += WHT"箱里的嗡嗡声仍然很强，看来蜂箱里蜜不是很多。\n"NOR;
	else if (ob->query("mi_lvl") <= max*6/10)
		descrp += WHT"箱里的嗡嗡声时断时续，看来蜂箱里有一些蜂蜜了。\n"NOR;
	else if (ob->query("mi_lvl") <= max*9/10)
		descrp += WHT"箱里的嗡嗡声渐渐轻下来，看来蜂箱里已经有许多蜂蜜了。\n"NOR;
	else if (ob->query("mi_lvl") == max)
		descrp += WHT"箱里全是沙沙声，玉蜂正辛勤劳作，看来它们已经采满蜜了。 \n"NOR;

	write(descrp);

	if (ob->query("open")) {
		if (ob->query("mi_left") == 0) write(WHT"大多数玉蜂不停地在四周打转，看来这里没什么价值了。\n"NOR);
		else if (ob->query("mi_left") == 1)	write(WHT"越来越多的玉蜂在四周打转，看来这里花蜜快采完了。\n"NOR);
		else write(WHT"玉蜂正辛勤的采花蜜。\n"NOR);
	}
	else write(WHT"玉蜂箱的门关着。\n"NOR);

	return 1;
}

int do_putdown(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return 0;
	if (ob->query("down")) return notify_fail("你糊涂了？ \n");
	if( !ob) return notify_fail("你并没有拿着蜂箱啊？\n");
	if(environment(me)->query("short") != "树林") return notify_fail("你找不到合适的地方放蜂箱！ \n");
	if( ob->query("owner") != me ) return notify_fail("这你的蜂箱吗？\n");
	if(present("feng xiang", environment(me))) return notify_fail("这里已经有别人在放养玉蜂了。\n");
	if( ob->query("lastplace") == environment(me)) return notify_fail("玉蜂刚在这里采过蜜！\n");

	ob = present("feng xiang", me);

	if(me->is_busy())
		return notify_fail("你正忙着呢! \n");

	message_vision(HIB"$N在树林中找了一块儿空地，轻轻地把蜂箱放在地上。\n"NOR,me);

	ob->set("down",1);
	ob->move(environment(me));
	ob->set("mi_left",5+random(5));

	return 1;
}

int do_carry(string arg)
{
	object me, ob;
	me = this_player();

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return notify_fail("你要拿什么？ \n");

	ob = present("feng xiang", environment(me));
	if(!ob)	return notify_fail("哪里有蜂箱啊？\n");
	if (!ob->query("down")) return notify_fail("你糊涂了？ \n");
	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if( ob->query("owner") != me ) return notify_fail("这你的蜂箱吗？\n");
	if( ob->query("open") || ob->query("bee_out"))
		return notify_fail("你还是先把玉蜂招回来吧！\n");
	
	message_vision(HIR"$N小心翼翼地抬起蜂箱，生怕惊动了里面的玉蜂。\n"NOR,me);

	ob->set("down",0);
	ob->move(me);

	return 1;
}

int auto_check()
{
	object me = this_player();
	object ob = this_object();
	object maque;
	int bee_lvl = (int)me->query_skill("bee-training",1);

	int i,r;
	int g_exp,g_pot,g_bee,g_mi;
	
	r = query_amount();
	g_exp = to_int((T_EXP+random(R_EXP + bee_lvl/30))*pow(r,0.5))*6/5;
	g_pot = to_int((T_POT+random(R_POT + bee_lvl/50))*pow(r,0.5))*6/5;
	g_bee = (T_BEE+random(R_BEE))*r*6/5;
	g_mi = to_int(pow(r,0.5));
	
	if ( query("bee_training") ) {
		g_exp += to_int((T_EXP+random(R_EXP + bee_lvl/20))*pow(r,0.5));
		g_pot += to_int((T_POT+random(R_POT + bee_lvl/40))*pow(r,0.5));
		g_bee += (T_BEE+random(R_BEE))*r;
	}

	if (me->query("jingli")<T_COST+10){
		ob->set("escaped",1);
		message_vision(HIR"$N已经精疲力竭，玉蜂逐渐脱离了$N的控制！\n"NOR,me);
		return 0;
	}

	if(maque = present("ma que", environment(ob))) {
		if (living(maque)){
			ob->set("escaped",1);
			message_vision(HIR"麻雀迅速叼了一只玉蜂，一转眼便飞走了！吓得玉蜂都躲回蜂箱里去了。\n"NOR,me);
			destruct(maque);
		return 0;
		}
	}

	if( environment(ob) != environment(me) ){
		ob->set("escaped",1);
		message_vision(HIR"工作时你怎么跑了？玉蜂都没人管啦！。\n"NOR,me);
		return 0;
	}

	write(phases[random(3)]);
	if (query("mi_left") == 0) write(WHT"大多数玉蜂不停地在四周打转，看来这里没什么价值了。\n"NOR);
	else if (query("mi_left") == 1)	write(WHT"越来越多的玉蜂在四周打转，看来这里花蜜快采完了。\n"NOR);

	me->receive_damage("jingli", random(T_COST), "活活累死了！");
	ob->set("bee_training",0);

	if (g_exp > 25) g_exp = 20;
	if (g_pot > 10) g_pot = 8;

	if (ob->query("mi_left") && ob->query("mi_lvl")<MAX_MI*query_amount() ) {
		me->add("gm/exp",g_exp);
		me->add("gm/pot",g_pot);
		me->add("gm/lvl",g_bee);
		me->add("combat_exp",g_exp);
		me->add("potential",g_pot);
		if(me->query("potential")>me->query("max_potential"))
			me->set("potential",me->query("max_potential"));
		me->improve_skill("bee-training", g_bee, 0);
		ob->set("mi_lvl",ob->query("mi_lvl")+g_mi);
		if( g_mi == 1) ob->set("mi_left",ob->query("mi_left")-1);
		else if (query("mi_left")>1) ob->set("mi_left",ob->query("mi_left")-2);
		else set("mi_left",0);
	}

	r = random(RDM);
	if (r == 1 && bee_lvl<30 ){
		message_vision(HIR"一只玉蜂突然受惊，狠狠地在$N身上叮了一口。\n"NOR,me);
		me->apply_condition("yufeng_poison", random((30-bee_lvl)/2) 
			+ me->query_condition("yufeng_poison"));
	}
	else if (r==2) {
		message_vision("$N看见一些玉蜂在一个地方奇怪地舞着，也许有什么药材可以采(cai yao)吧。\n",me);
		environment(me)->set("yaocai",1);
	}
	else if (r >= RDM - query_amount()) {
		maque = new("/kungfu/class/gumu/npc/maque2");
		maque->move(environment(ob));
		message_vision(HIR"突然一只麻雀向玉蜂冲了过去，$N连忙阻止。\n"NOR,me);
		maque->set("combat_exp",me->query("combat_exp"));
		if (me->query("combat_exp")>20000) maque->set("combat_exp",20000);
		maque->kill_ob(me);
	}
	else me->start_busy(1+random(3));

	call_out("auto_check", TICK+random(R_TICK) );
	return 1;
}

int do_give(string arg)
{
	string target, item;
    object obj, who, me=this_player();

    if(!arg) return notify_fail("你要给谁什么东西？\n");

    if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
    else return notify_fail("你要给谁什么东西？\n");

	if ( item != "beehive" && item !="box" && item != "xiang" ) return 0;
	if ( target != "sun" && target !="nanny" ) return 0;
	if ( !objectp(obj = present(item, me)) ) return notify_fail("你身上没有这样东西。\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
    if (!objectp(who = present(target, environment(me))) || !living(who))
        return notify_fail("这里没有这个人。\n");
	if ( userp(who) ) return notify_fail("对方不接受这样东西。\n");
	if ( who->query("race") != "人类" )
		return notify_fail("别找碴儿！怎么把玉蜂箱交给畜生？\n");
	if( who == me) return notify_fail("自己给自己？！\n");

	message_vision("$N给$n"+chinese_number(query_amount())
		+"个"+HIW"玉蜂箱。\n"NOR, me, who);

	if ( obj->query("owner") == me ) {
		if(query("escaped")) {
			message_vision(CYN"$N不好意思地搔了搔头。\n"NOR, me, who);
			message_vision(CYN"$N红着脸对孙婆婆说道，这次工作没干好。\n"NOR, me, who);
			message_vision(CYN"$n轻轻拍了拍$N的头。\n"NOR, me, who);
			message_vision(CYN"$n和蔼地对$N说道：没关系，下次注意就好。\n"NOR, me, who);
			me->add_temp("bee_count", -1 );
			me->add("bee_count", -1 );
			if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
		}
		else{
			message_vision(CYN"$n轻轻拍了拍$N的头。\n"NOR, me, who);
			message_vision(CYN"$n和蔼地对$N说道：辛苦$N啦，下去休息一下吧。\n"NOR, me, who);
			if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
		}
		if ( me->query("gm/job") == 1 ){
			if ((me->query("gm/exp")+me->query("gm/pot")+me->query("gm/lvl")) != 0)
				log_file("/job/gm-bee",sprintf("[%s] %s(%s) 从 %d 秒的放蜂工作中取得 %d 点经验 、 %d 点潜能 和 %d 点驱蜂术\n", ctime(time()),me->name(), me->query("id"),time()-me->query("gm/time"),me->query("gm/exp"),me->query("gm/pot"),me->query("gm/lvl")));
			me->delete("gm",0);
		}
	}
	else {
		message_vision(CYN"$n对$N微微笑了笑。\n"NOR, me, who);
		message_vision(CYN"$n说道：多谢啦！\n"NOR, me, who);
	}

	destruct(obj);
	
	return 1;
}

int do_qufeng(string arg)
{
	object bees;
	object me = this_player();
	int lvl = me->query_skill("bee-training",1);
	int bee_exp;
	int bee_life;

	if(!arg || (arg != "out" && arg != "back" ) )return 0;
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");

	if (arg=="out"){
		if( query("owner") != me ) return notify_fail("这你的蜂箱吗？\n");
		if (!query("bee_count")) return notify_fail("可惜你的玉蜂都死了，无法帮你了。\n");
		if (!query("open")) return notify_fail("你至少该把玉蜂箱门打开吧。\n");
		if (query("bee_org")) return notify_fail("在外列阵的玉蜂群一阵骚动，显然不知所措。\n");
		if (query("escape")) return notify_fail("玉蜂战战兢兢在远处徘徊，就是不肯过来。\n");

		set("bee_org",1);
		remove_call_out("auto_check");
		bees = new("/kungfu/class/gumu/npc/white_bee");
		set("bees",bees);
		
		bee_life = lvl*(20+20*(query_amount()-1)/4);
		bees->set("jing",bee_life);
		bees->set("max_jing",bee_life);
		bees->set("eff_jing",bee_life);
		bees->set("qi",bee_life);
		bees->set("max_qi",bee_life);
		bees->set("eff_qi",bee_life);
		bees->set("jingli",bee_life);
		bees->set("max_jingli",bee_life);
		bees->set("eff_jingli",bee_life);

		lvl = lvl*3/2 + lvl*(query_amount()-1)/5;
		bees->set_skill("dodge",lvl);
		bees->set_skill("parry",lvl);
		bees->set_skill("unarmed",lvl);
		bee_exp = lvl*lvl*lvl/10;
		bees->set("combat_exp",bee_exp);
	
		if( bee_exp < 4000){
			bees->set_temp("apply/attack", 35);
			bees->set_temp("apply/damage", 15);
			bees->set_temp("apply/armor", 100);
		}
		else if( bee_exp < 30000){
			bees->set_temp("apply/attack", 45);
			bees->set_temp("apply/damage", 26);
			bees->set_temp("apply/armor", 100);
		}
		else if( bee_exp < 60000){
			bees->set_temp("apply/attack", 45);
			bees->set_temp("apply/damage", 36);
			bees->set_temp("apply/armor", 120);
		}
		else if( bee_exp < 300000){
			bees->set_temp("apply/attack", 55);
			bees->set_temp("apply/damage", 46);
			bees->set_temp("apply/armor", 130);
		}
		else{
			bees->set_temp("apply/attack", 65);
			bees->set_temp("apply/damage", 55);
			bees->set_temp("apply/armor", 150);
		}
		
		bees->set("owner",me);
		bees->set_amount(query_amount());
		bees->move(environment(me));
		message_vision(WHT"忽然，$N口中嗡嗡嗡的低吟起来。这吟声初时极为轻微，到后来$N的吟声後一声与前一声相叠，重重叠叠，竟然越来越响。\n"NOR
			+WHT"但听得玉蜂嗡嗡之声，已与$N口中的吟声混成一片。不一会，玉蜂树林里冲了出来，聚集在你身旁俨然成阵。\n"NOR, me);

		return 1;
	}
	else{
		if( query("owner") != me ) return notify_fail("这你的玉蜂群吗？\n");
		if (!query("bee_org")) return notify_fail("你糊涂了？\n");
		if( environment(query("bees")) != environment(me))
			return notify_fail("你的玉蜂群不在这儿啊？\n");
		
		message_vision(WHT"$N的玉蜂四散飞去，继续它们的工作。\n"NOR, me);

		set("bee_org",0);
		destruct(query("bees"));
		remove_call_out("auto_check");
		call_out("auto_check", TICK+random(R_TICK) );

		return 1;
	}
}

int do_direct(string arg)
{
	object me = this_player();
	int bee_lvl = me->query_skill("bee-training",1);
	int r;
	int g_exp,g_pot,g_bee,g_mi;

	if(!arg || arg != "bee" ) return 0;
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");
	if(query("owner") != me ) return notify_fail("这些不是你的玉蜂！\n");
	if(bee_lvl<30) return notify_fail("你还没能力训练玉蜂。\n");
	if(!query("open")) return notify_fail("还是先把玉蜂放出来吧。\n");
	if(query("bee_training")) return notify_fail("你正在训练玉蜂。\n");
	if(query("bee_org")) return notify_fail("你正在调动玉蜂战斗呢。\n");
	if(me->query("jingli") <T_COST+10) return notify_fail("你太累了，休息会吧。\n");
	
	message_vision(WHT"$N嘴里不断发出嗡嗡声，指导玉蜂更有效率的采蜜。\n"NOR, me);
	set("bee_training",1);

/*	
	r = query_amount();
	g_exp = to_int((T_EXP+random(R_EXP + bee_lvl/20))*pow(r,0.5));
	g_pot = to_int((T_POT+random(R_POT + bee_lvl/40))*pow(r,0.5));
	g_bee = (T_BEE+random(R_BEE))*r;

	set("bee_training",1);
	if (query("mi_left") && query("mi_lvl")<MAX_MI*query_amount() ) {
		me->receive_damage("jingli", ramdom(T_COST*2), "活活累死了！");
		me->add("combat_exp",g_exp);
		me->add("potential",g_pot);
		if(me->query("potential")>me->query("max_potential"))
			me->set("potential",me->query("max_potential"));
		me->improve_skill("bee-training", g_bee, 0);
	}
*/
	
	r = random(RDM);
	if (r >= RDM - query_amount()){
		remove_call_out("killer_show");
		call_out( "killer_show",1,me );
	}
	else if (r==1) {
		message_vision("$N看见一些玉蜂在一个地方奇怪地舞着，也许有什么药材可以采(cai yao)吧。\n",me);
		environment(me)->set("yaocai_h",1);
	}
	else {
		me->receive_damage("jingli", random(T_COST*2), "活活累死了！");
		me->start_busy(1+random(2));
	}
	return 1;
}

void killer_show(object me)
{
	object ob,here;
	object *target_list;
	int i;

	if( !me ) return;
	here = environment(me);

	if(!here)return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;

	if( me->is_fighting() ) return;

	target_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(target_list) == 0 ) {
		  // try again in 5 secs.
//		call_out("killer_show", 5, me);
		return;
	}

	do
	{
		i = random(sizeof(target_list));
		if(present(base_name(target_list[i]) + ".c",environment(this_object())))continue;
		ob=new( base_name(target_list[i]) + ".c" );
	}
	while( !objectp(ob) );

	ob->move(here);
	setup_skill(me,ob);
	
	message_vision(HIR"\n$N晃悠悠地走了过来!\n"NOR, ob);
	if (ob->query("family/family_name") == "全真派") 
		message_vision(CYN"$N看着你不屑地说道，你也是我派弃徒杨过调教出来的下三滥吗？\n"NOR, ob);
	else if (ob->query("gender") == "男性")
		message_vision(CYN"$N嬉皮笑脸地说道：听说古墓派全是娇滴滴的小美人儿，"
			+ RANK_D->query_self(ob) + "今日特来一睹仙颜。\n"NOR, ob);
	else
		message_vision(CYN"$N嬉皮笑脸地说道：听说古墓派全是娇滴滴的小美人儿，"
			+ RANK_D->query_self(ob) + "今日特来请教勾引男人的秘技。\n"NOR, ob);
	message_vision(CYN"$N不禁勃然大怒！\n"NOR,me);

	call_out("action",1,me,ob);

//	if( random(3) == 1)
//	{
//		remove_call_out("killer_show");
//		call_out( "killer_show",30+random(15),me );
//	}
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
		"mu ren",
		"huang zhen",
		"juexin dashi",
		"fighter dummy",
		"du e",
		"du nan",
		"du jie",
		"xie yanke",
		"ren woxing",
		"yue buqun",
		"qiu chuji",
		"gao lao",
		"ai lao",
		"hong qigong",
		"zhang sanfeng",
		"zuo lengchan",
		"ouyang zhan",
		"seng bing",
		"huang yaoshi",
		"yideng dashi",
		"ma guangzuo",
		"black gargoyle",
		"white gargoyle",
		"tang nan",
		"lao chaofeng",
	});

	if(  !clonep(victim) || userp(victim)
		|| victim->query("race") != "人类"
		|| ( victim->query("shen") > 0 && victim->query("family/family_name") != "全真派" )
		|| victim->query("winner")
		|| strsrch(base_name(victim), "/kungfu/skill/") != -1
		|| strsrch(base_name(victim), "/kunfu/class/huashan") != -1
		|| strsrch(base_name(victim), "/clone/") != -1
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| strsrch(base_name(victim), "/d/city/") != -1
		|| strsrch(base_name(victim), "/d/bwdh/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 1/15
		|| victim->query("combat_exp") > killer->query("combat_exp")*7/3
		|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
	{
		return 0;
	}
	
	return 1;
}

void action(object me, object ob)
{
	object owner, here = environment(me);
	if( !me || !ob || !present(ob->query("id"),here) )
	{
		do_leave(ob);
		return;
	}

	if( me->is_busy() || ob->is_busy() || ob->is_fighting() 
		|| me->is_fighting() || !living(me) || !living(ob) )
	{
		 call_out("action",2,me,ob);
		 return;
	}

	message_vision(HIR"\n$N对$n喝道：大胆狂徒，竟敢到古墓来撒野！看招！\n"NOR, me,ob);
	me->kill_ob(ob);
	ob->kill_ob(me);

	call_out("do_leave",20,ob);
	return;
}

void do_leave(object ob)
{
	remove_call_out("do_leave");

	if( objectp(ob) ){
		if( ob->is_busy() || ob->is_fighting()){
			message_vision("$N向后一跳，跳出战圈！\n",ob);
			message_vision("$N说道：没想到古墓派手底下这么硬，"+RANK_D->query_self(ob)+"改日再来领教！\n",ob);
		}
		if(!living(ob))ob->revive(0);
		message_vision("$N急急忙忙离开了。\n",ob);
		destruct(ob);
	}
}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) )return;

	if( obj->query("combat_exp") < me->query("combat_exp") )
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(60) )  );

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 4000 )
		level = level/3 + random(level/3);
	else if( obj->query("combat_exp") < 30000)
		level = level/3 + random(level/4);
	else if( obj->query("combat_exp") < 60000)
		level = level/3 + random(level/4);
	else if( obj->query("combat_exp") < 300000)
		level = level/3 + random(level/5);
	else
		level = level/3 + random(level/6);

	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
		obj->set_skill(names[i], level);
	}

	call_out("do_leave",60+random(60),obj);
}

int do_add(string arg)
{
	object me = this_player();
	int i,max,mi_lvl;

	if( !wizardp(me) ) return 0;
	if(!arg) return 0;

	sscanf(arg, "%d", i);
	set("mi_lvl",query("mi_lvl") + i);
	mi_lvl = query("mi_lvl");
	max = MAX_MI*query_amount();
	tell_object(me, "满箱"+chinese_number(max)+"，现在"	+ chinese_number(mi_lvl)+"。\n");
	
	return 1;
}

void destroy_me(object me)
{
	if (query("owner"))	return;

	remove_call_out("destroy_me");
	remove_call_out("auto_check");
	remove_call_out("killer_show");

	destruct(me);
}

int do_cai(string arg)
{
	object me = this_player();
	object here = environment(me);
	int i;
	object yaocai;

	if ( !arg && arg != "yao" ) return 0;
	if ( !here->query("yaocai") && !here->query("yaocai_h") ) return 0;

	if (here->query("yaocai")){
		here->set("yaocai",0);
		switch (random(5)){
		case 0 : yaocai = new("/clone/herb/chantui");
			break;
		case 1 : yaocai = new("/kungfu/class/gumu/herb/muxiang");
			break;
		case 2 : yaocai = new("/kungfu/class/gumu/herb/shengma");
			break;
		case 3 : yaocai = new("/kungfu/class/gumu/herb/chaihu");
			break;
		case 4 : yaocai = new("/kungfu/class/gumu/herb/shanju");
			break;
		}
		yaocai->move(me);
		message_vision("$N拨开杂草发现了"+yaocai->query("name")+"。\n", me);
	}
	if (here->query("yaocai_h")){
		here->set("yaocai_h",0);
		switch (random(3)){
		case 0 : yaocai = new("/clone/herb/renshen");
			break;
		case 1 : yaocai = new("/clone/herb/heshouwu");
			break;
		case 2 : yaocai = new("/kungfu/class/gumu/herb/tufuling");
			break;
		}
		yaocai->move(me);
		message_vision("$N拨开杂草发现了"+yaocai->query("name")+"。\n", me);
	}
	return 1;
}