// beehive.c 蜂箱
// by April	01.08.26
// update by April 01.08.04

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

#define TICK 5			//auto_check间隔基础时间
#define R_TICK 5		//auto_check间隔附加随机时间
#define T_COST 10		//每tick消耗精力
#define C_COST 20		//callback消耗精力
#define T_EXP 4			//每tick增加exp
#define R_EXP 4			//每tick附加随机exp
#define T_POT 1			//每tick增加pot
#define R_POT 3			//每tick附加随机pot
#define T_BEE 10		//每tick增加bee-traing skill
#define R_BEE 10		//每tick附加随机bee-traing skill
#define RDM	20			//训蜂时出现意外的概率

#include "ansi.h"

inherit ITEM;

void setup_skill(object me,object obj);
void do_leave(object ob);

string *phases = ({
	"玉蜂飞来飞去不停地在花丛中忙碌着。 \n",
	"你口中念念有词，驱赶着玉蜂不让它们飞远。 \n",
	"你警惕地监视着不远处蠢蠢欲动的麻雀。\n",
});

void create()
{
	set_name(HIW "玉蜂箱" NOR, ({ "feng xiang", "beehive", "box", "xiang" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",	HIW"这是一个木制的古墓派玉蜂箱。里面嗡嗡的，不知道有多少玉蜂。\n"NOR );
        set("value", 1000);
        set("material", "wood");
		set("no_sell", 1);
		set("no_give",0);
		set("no_get",1);
	}

	setup();
}

init()
{
	object me = this_player();
	if ( me->query("id",1)!="sun popo" && !wizardp(me)) {
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
	add_action("do_train", "train");

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

	if (ob->query("mi_lvl") >= 20){
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
	me->receive_damage("jingli", C_COST, "活活累死了！");

	remove_call_out("auto_check");

	return 1;
}

int do_check()
{
	object me = this_player();
	object ob = this_object();
	string descrp;

	if (living(ob->query("owner")))
		descrp = WHT"这蜂箱里装的是由"+ob->query("owner")->query("name")+"负责驯养的玉蜂群。\n"NOR;
	else
		descrp = WHT"这蜂箱里装的是古墓派的玉蜂群。不知道该由谁负责。\n"NOR;

	if (ob->query("mi_lvl") == 0)
		descrp += WHT"箱里的嗡嗡声连成一片，玉蜂显得烦躁不安，看来得尽快放它们出去采蜜。\n"NOR;
	else if (ob->query("mi_lvl") <= 6)
		descrp += WHT"箱里的嗡嗡声仍然很强，看来蜂箱里蜜不是很多。\n"NOR;
	else if (ob->query("mi_lvl") <= 12)
		descrp += WHT"箱里的嗡嗡声时断时续，看来蜂箱里有一些蜂蜜了。\n"NOR;
	else if (ob->query("mi_lvl") <= 19)
		descrp += WHT"箱里的嗡嗡声渐渐轻下来，看来蜂箱里已经有许多蜂蜜了。\n"NOR;
	else if (ob->query("mi_lvl") == 20)
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
		return notify_fail("你要放下什么？ \n");
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
//	ob->set("lastplace",environment(me));
	ob->set("mi_left",3+random(3));

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
	int bee_lvl = (int)me->query_skill("bee-trining",1);

	int i,_random;

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
	me->receive_damage("jingli", T_COST, "活活累死了！");

	if (ob->query("mi_left") && ob->query("mi_lvl")<20 ) {
		me->add("combat_exp",T_EXP+random(R_EXP));
		me->add("potential",T_POT+random(R_POT));
		if(me->query("potential")>me->query("max_potential"))
			me->set("potential",me->query("max_potential"));
		me->improve_skill("bee-training", T_BEE+random(R_BEE), 0);
		ob->set("mi_lvl",ob->query("mi_lvl")+1);
		ob->set("mi_left",ob->query("mi_left")-1);
	}

	_random = random(RDM);
	if (_random == 1 && bee_lvl<30 ){
		message_vision(HIR"一只玉蜂突然受惊，狠狠地在$N身上叮了一口。\n"NOR,me);
		me->apply_condition("yufeng_poison", random((30-bee_lvl)/2) 
			+ me->query_condition("yufeng_poison"));
	}
	else if (_random == 2) {
		maque = new("/d/gumu/npc/maque2");
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

	message_vision("$N给$n一个"+HIW"玉蜂箱。\n"NOR, me, who);

	if ( obj->query("owner") == me ) {
		message_vision(CYN"$n轻轻拍了拍$N的头。\n"NOR, me, who);
		message_vision(CYN"$n和蔼地对$N说道：辛苦$N啦，下去休息一下吧。\n"NOR, me, who);
		if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
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

	if(!arg || (arg != "out" && arg != "back" ) )return 0;
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");

	if (arg=="out"){
		if( query("owner") != me ) return notify_fail("这你的蜂箱吗？\n");
		if (!query("bee_count")) return notify_fail("可惜你的玉蜂都死了，无法帮你了。\n");
		if (!query("open")) return notify_fail("你至少该把玉蜂箱门打开吧。\n");
		if (query("bee_org")) return notify_fail("在外列阵的玉蜂群一阵骚动，显然不知所措。\n");
		if (query("escape")) return notify_fail("玉蜂战战兢兢在远处徘徊，就是不肯过来。\n");

		set("open",0);
		set("bee_org",1);
		remove_call_out("auto_check");
		bees = new("/d/gumu/npc/white_bee");
		set("bees",bees);

		bees->set("jing",lvl*20);
		bees->set("max_jing",lvl*20);
		bees->set("eff_jing",lvl*20);
		bees->set("qi",lvl*20);
		bees->set("max_qi",lvl*20);
		bees->set("eff_qi",lvl*20);
		bees->set("jingli",lvl*20);
		bees->set("max_jingli",lvl*20);
		bees->set("eff_jingli",lvl*20);

		lvl = lvl*3/2;
		bees->set_skill("dodge",lvl);
		bees->set_skill("parry",lvl);
		bees->set_skill("unarmed",lvl);
		bees->set("combat_exp",lvl*lvl*lvl/10);

		bees->move(environment(me));
		message_vision(WHT"忽然，$N口中嗡嗡嗡的低吟起来。这吟声初时极为轻微，到后来$N的吟声後一声与前一声相叠，重重叠叠，竟然越来越响。\n"NOR
			+WHT"但听得玉蜂嗡嗡之声，已与$N口中的吟声混成一片。不一会，玉蜂树林里冲了出来，聚集在你身旁俨然成阵。\n"NOR, me);

		return 1;
	}
	else{
		if( query("owner") != me ) return notify_fail("这你的蜂箱吗？\n");
		if (!query("bee_org")) return notify_fail("你糊涂了？\n");
		if( environment(query("bees")) != environment(me))
			return notify_fail("你的玉蜂群不在这儿啊？\n");
		
		message_vision(WHT"$N的玉蜂四散飞去，继续它们的工作。\n"NOR, me);

		set("bee_org",0);
		destruct(query("bees"));

		return 1;
	}
}

int do_train(string arg)
{
	object me = this_player();
	int bee_lvl = me->query_skill("bee-training",1);
	int _random;

	if(!query("open")) return 0;
	if(!arg || arg != "bee" )return 0;
	if(bee_lvl<30) return notify_fail("你还没能力训练玉蜂。\n");
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");
	
	message_vision(WHT"$N嘴里不断发出嗡嗡声，指导玉蜂更有效率的采蜜。\n"NOR, me);

	me->add("combat_exp",T_EXP+random(R_EXP));
	me->add("potential",T_POT+random(R_POT));
	if(me->query("potential")>me->query("max_potential"))
		me->set("potential",me->query("max_potential"));
	me->improve_skill("bee-training", T_BEE+random(R_BEE), 0);
	
	_random = random(RDM/2);
	if (_random == 1){
		message_vision(HIR"一个流氓跳了出来。\n"NOR,me);
		remove_call_out("killer_show");
		call_out( "killer_show",1,me );
	}
	else me->start_busy(1+random(3));

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
	message_vision("\n$N晃悠悠地走了过来!\n", ob);

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
		 call_out("action",1,me,ob);
		 return;
	}

	me->kill_ob(ob);
	if( owner = present(me->query("owner"),here) )  
	{
		message_vision(HIR"\n$N"+HIR"喝道：老毒物的弟子驱蛇伤人无数，今天"+RANK_D->query_self(ob)+"特来送你们上西天！\n"NOR, ob);
		ob->kill_ob(me);
		ob->kill_ob(owner);
	}
	else if( random(2)==0 )
	{
		message_vision(HIR"\n$N"+HIR"突然向$n"+HIR"发动进攻!\n"NOR, ob,me);
		ob->kill_ob(me);
	}
	else
	{
		message_vision(HIR"\n$N"+HIR"喝道：老毒物的怪蛇害人无数，今天"+RANK_D->query_self(ob)+"誓为民除害！\n"NOR, ob);
		ob->kill_ob(me);
	}

	call_out("action",random(10),me,ob);
}

void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N向后一跳，跳出战圈！\n",ob);
				if(present("guai she",environment(ob)))
				  message_vision("$N说道：没想到老毒物的宝贝玩意还真有两下子。"+RANK_D->query_self(ob)+"改日再来奉陪！\n",ob);
				else message_vision("$N说道：哈蛤，老毒物的宝贝玩意到底不是"+RANK_D->query_self(ob)+"的对手！\n",ob);
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
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(60) )  );
	}

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/4);
	}
	else
		level = level/2 + random(level/5);

	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  obj->set_skill(names[i], level);
	}

	call_out("do_leave",60+random(60),obj);

}

