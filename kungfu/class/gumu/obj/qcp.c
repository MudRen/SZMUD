// qingci-ping.c 青瓷瓶，用来装玉蜂蜜
// by april 01.08.27
// update vy april 2001.11.09

#include <ansi.h>
//#include <dbase.h>
//#include <name.h>

inherit ITEM;
//inherit COMBINED_ITEM;
inherit F_LIQUID;

#define RAN 60	//浆有效果的概率

void create()
{
	set_name(CYN"青瓷瓶"NOR, ({"qingci ping", "ping", "bottle" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "古墓派用来装玉蜂蜜的青瓷小瓶。\n");
		set("unit", "个");
		set("base_unit", "个");
		set("max_liquid", 10);
                set("no_give",1);
                set("no_get",1);
	}

	set("liquid", ([
		"type": "mi",
		"name": "玉蜂蜜",
		"remaining": 10,
		"drunk_apply": 1,
	]));

//	set_amount(1);
}

void init()
{
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
	add_action("do_add", "add");
//	add_action("do_drop", "drop");
//	add_action("do_give", "give");
}

/*
string extra_long()
{
	int amount, max;
	string str;
	object me = this_player();

	amount = query("liquid/remaining");
	max = query("max_liquid")*query_amount();
	if( wizardp(me) ) tell_object(me, "满瓶"+chinese_number(max)+"，现在"
		+ chinese_number(amount)+"。\n");

	if( amount ) {
		if( amount >= max )
			str = "里面装满了" + query("liquid/name") + "。\n";
		else if( amount >= max/2 )
			str = "里面装了七、八分满的" + query("liquid/name") + "。\n";
		else if( amount >= max/3 )
			str = "里面装了三、四分满的" + query("liquid/name") + "。\n";
		else //if( amount > max/2 )
			str = "里面装了少许的" + query("liquid/name") + "。\n";
		return str;
	}
	else return 0;
}
*/

int do_drink(string arg)
{
	object pl = this_player();
	object ping = this_object();
	object *inv;
	string item;
	int num,i,j;

	if(!arg) return 0;
	if( !living(pl) ) return 0;
	if( pl->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( (int)pl->query("water") >= (int)pl->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	if (sscanf(arg, "%s %d", item, num)==2){
		if( !id(item) ) return 0;
		if(num){
			inv = all_inventory(pl);
			j = 0;
			for(i=0; i<sizeof(inv); i++){
				if( inv[i]->query("name") == CYN"青瓷瓶"NOR ){
					j += 1;
					if( j == num ) ping = inv[i];
				}
			}
		}
	}
	else if( !id(arg) ) return 0;
	
	if( !ping->query("liquid/remaining") )
		return notify_fail( name() + (ping->query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));

	ping->add("liquid/remaining", -1);
	message_vision("$N拿起" + name() + "呷了一小口" + ping->query("liquid/name") + "。\n",pl);
	pl->add("water", 5);
	pl->add("jingli", 5);

	if( ping->query("liquid/name") == "玉蜂蜜" ) {
		pl->add("jing",30);
		if ((int)pl->query_condition("yufeng_poison")) {
		    pl->apply_condition("yufeng_poison", (int)pl->query_condition("yufeng_poison") - 5);
			tell_object(pl, HIW "玉蜂毒的奇痒减轻了一些！\n" NOR );
		}
	}
	if( ping->query("liquid/name") == "玉蜂蜜水" ) {
		pl->add("jingli",25);
		if ((int)pl->query_condition("yufeng_poison")) {
		    pl->apply_condition("yufeng_poison", (int)pl->query_condition("yufeng_poison") - 2);
			tell_object(pl, HIW "玉蜂毒的奇痒只减轻了一点点！\n" NOR );
		}
	}
	if( ping->query("liquid/name") == "玉蜂王浆" ) {
		if (pl->query_skill("bee-training",1) > 60){
			tell_object(pl, HIW "你潜运功力，任王浆阴柔之气畅行于经脉。\n" NOR );
			if ( random(100) < RAN ){
				if (pl->query("max_jingli") 
					< pl->query_skill("force") * pl->query("con") /2 ){
					pl->add("max_jingli", 1);
					pl->add("eff_jingli", 1);
				}	
			}
			else if ( pl->query("jingli") < pl->query("max_jingli") )
				pl->set("jingli",pl->query("max_jingli"));
			if ((int)pl->query_condition("yufeng_poison")>=20) 
				pl->apply_condition("yufeng_poison", 20);
			else
				pl->apply_condition("yufeng_poison", 
					(int)pl->query_condition("yufeng_poison") + 2);
		}
		else pl->apply_condition("yufeng_poison", 
			(int)pl->query_condition("yufeng_poison") + 20);
	}
	if( ping->query("liquid/name") == "古墓玉浆" ) {
		if (pl->query_skill("bee-training",1) > 120
			&& pl->query_skill("yunu-xinjing",1) > 90 ){
			tell_object(pl, HIW "你潜运玉女心经，借玉浆阴柔之气冲击经脉，似乎有些作用。\n" NOR );
			if ( random(100) < RAN ){
				if (pl->query("max_neili") 
					< pl->query_skill("force") * pl->query("con") *2/3)
					pl->add("max_neili", 1);
			}
			else if ( pl->query("neili") < pl->query("max_neili") )
				pl->set("neili",pl->query("max_neili"));
			if ((int)pl->query_condition("yufeng_poison")>=30) 
				pl->apply_condition("yufeng_poison", 30);
			else
			    pl->apply_condition("yufeng_poison", 
					(int)pl->query_condition("yufeng_poison") + 3);
		}
		else pl->apply_condition("yufeng_poison", 
			(int)pl->query_condition("yufeng_poison") + 30);
	}
	if( ping->query("liquid/name") == "古墓圣浆" ) {
		if ( pl->query_skill("bee-training",1) > 150
			&& pl->query_skill("yunu-xinjing",1) > 120 ){
			tell_object(pl, HIW "你潜运玉女心经，借圣浆阴柔之气畅行经脉，通体舒泰！\n" NOR );
			if ( random(100) < RAN ){
				if (pl->query("max_neili") 
					< pl->query_skill("force") * pl->query("con") *2/3)
					pl->add("max_neili", 1);
			}
			else if (pl->query("max_jingli")
				< pl->query_skill("force") * pl->query("con") /2 ){
				pl->add("max_jingli", 1);
				pl->add("eff_jingli", 1);
			}
			if ((int)pl->query_condition("yufeng_poison")>=30) 
				pl->apply_condition("yufeng_poison", 30);
			else
			    pl->apply_condition("yufeng_poison", 
					(int)pl->query_condition("yufeng_poison") + 3);
		}
		else pl->apply_condition("yufeng_poison", 
			(int)pl->query_condition("yufeng_poison") + 30);
	}

//	if( pl->query("jingli") > pl->query("max_jingli")) 
//	this_player()->set("jingli", this_player()->query("max_jingli"));

	if( pl->is_fighting() ) pl->start_busy(2);
	if( !ping->query("liquid/remaining") ) {
		write("你已经将" + name() + "里的" + ping->query("liquid/name")
			+ "喝得一滴也不剩了。\n");
		if ( ping->query("worthless") )  set("value", 0);
	}

	// This allows customization of drinking effect.
	if( ping->query("liquid/drink_func") ) return 1;

	switch(ping->query("liquid/type")) {
		case "alcohol":
			pl->apply_condition("drunk",
				(int)pl->query_condition("drunk") 
				+ (int)ping->query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	object pl = this_player();
	object ping = this_object();
	object *inv;
	string item;
	int num,i,j;

	if(!arg) return 0;
	if( !living(pl) ) return 0;
	if( pl->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !environment(pl)->query("resource/water") )
		return notify_fail("这里没有地方可以装水。\n");

	if (sscanf(arg, "%s %d", item, num)==2){
		if( !id(item) ) return 0;
		if(num){
			inv = all_inventory(pl);
			j = 0;
			for(i=0; i<sizeof(inv); i++){
				if( inv[i]->query("name") == CYN"青瓷瓶"NOR ){
					j += 1;
					if( j == num ) ping = inv[i];
				}
			}
		}
	}
	else if( !id(arg) ) return 0;

	if ( ping->query("liquid/remaining")==ping->query("max_liquid") 
		&& ping->query("liquid/name")=="玉蜂蜜" ){
//	if ( query("liquid/name")=="玉蜂蜜" ){
		message_vision("$N将水缓缓注入" + ping->name() + "里，慢慢摇匀。\n", pl);
		ping->set("liquid/type", "mi-water");
		ping->set("liquid/name", "玉蜂蜜水");
		ping->set("liquid/remaining", query("max_liquid"));
		ping->set("liquid/drink_func", 0);
	}
	else {
		if( ping->query("liquid/remaining") ) 
			message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", pl);
		message_vision("$N将" + name() + "装满清水。\n", pl);

		ping->set("liquid/type", "water");
		ping->set("liquid/name", "清水");
		ping->set("liquid/remaining", query("max_liquid")); //*query_amount());
		ping->set("liquid/drink_func", 0);
	}

	if( pl->is_fighting() ) pl->start_busy(2);

	return 1;
}

int do_add(string arg)
{
	object me = this_player();
	int i,max,remaining;

	if( !wizardp(me) ) return 0;
	if(!arg) return 0;

	sscanf(arg, "%d", i);
	add("liquid/remaining", i);
	remaining = query("liquid/remaining");
	max = query("max_liquid");	//*query_amount();
	tell_object(me, "满瓶"+chinese_number(max)+"，现在"	+ chinese_number(remaining)+"。\n");
	
	return 1;
}

/*
int do_drop(string arg)
{
	int i, amount;
	string item;

	if(!arg) return 0;
	if (this_player()->is_busy()) return 0;

	if (sscanf(arg, "%d %s", amount, item)==2){
		if(item != "qingci ping" && item != "ping" && item != "bottle") return 0;
		if(!amount) return 0;

		if( amount > query_amount() ) return 0;
		else if( amount == query_amount() ) return 0;
		else {
			if( query("liquid/remaining") > (query_amount()-amount)*query("max_liquid") )
				set("liquid/remaining",(query_amount()-amount)*query("max_liquid"));
			return 0;
		}
	}
	
	return 0;
}
*/

/*
int do_give(string arg)
{
	string target, item;
	object who, *inv,new_ping;
	object obj=this_object();
	object me=this_player();
	int i, amount;
	string amt;

	if(!arg) return 0;

    if (me->is_busy()) return 0;
	if (me->is_fighting()) return 0;

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return 0;

	if(!objectp(who = present(target, environment(me)))) return 0;
	if(!living(who)) return 0;
	if( who == this_player()) return 0;
	if( who->query("env/no_accept") ) return 0;
	if( !interactive(who) && !who->accept_object(this_player(), obj) )	return 0;
	if( !userp(who) && obj->value() ) return 0;

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( amount > obj->query_amount() ) return 0;
		else if( amount == query_amount() ) return 0;
		else {
			new_ping = new(base_name(obj));
			new_ping->set_amount(amount);
			new_ping->set("liquid/remaining",query("liquid/remaining")/query_amount()*amount);
			set("liquid/remaining",query("liquid/remaining")
				- query("liquid/remaining")/query_amount()*amount);
			set_amount( query_amount() - amount );

			amt = chinese_number(new_ping->query_amount());
			if( obj->move(who) ) {
				printf("你给%s%s%s%s。\n", 
					who->name(),
					new_ping->query_amount()? amt : "一",
					new_ping->query_amount()? new_ping->query("base_unit") : new_ping->query("unit"), 
					new_ping->name());
				message("vision", sprintf("%s给你一%s%s。\n", this_player()->name(),
					new_ping->query("unit"), new_ping->name()), who );
				message("vision", sprintf("%s给%s一%s%s。\n", this_player()->name(), who->name(),
					new_ping->query("unit"), new_ping->name()), environment(this_player()), 
					({this_player(), who}) );
				this_player()->save();
				who->save();
				return 1;
			}
			else {
				set_amount((int)obj->query_amount() + amount);
				set("liquid/remaining",query("liquid/remaining")
					+ new_ping->query("liquid/remaining"));
				this_player()->save();
				return 0;
			}
		}
	}

	return 0;
}
*/
