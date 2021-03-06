// qingci-ping.c 青瓷瓶，用来装玉蜂蜜
// by april 01.08.27

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"青瓷瓶"NOR, ({"qingci ping", "ping", "bottle" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个青瓷小瓶，古墓派用来装玉蜂蜜。\n");
		set("unit", "个");
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "mi",
		"name": "玉蜂蜜",
		"remaining": 0,
		"drunk_apply": 1,
	]));

}

void init()
{
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
}

/*
int do_drink(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (arg!="qingci ping" && arg!="ping" && arg!="bottle") return 0;

	if (me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");

	if ((int)me->query("water")
		>= (int)me->max_water_capacity() )
		return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");

	if( !ob->query("liquid/remaining") )
		return notify_fail("青瓷瓶里什么也没有了。\n");

	me->add("jing", 30);

	if( me->is_fighting() ) me->start_busy(2);

	ob->add("liquid/remaining", -1 );
	me->add("water",5);

	if (ob->query("liquid/remaining")) {
		message_vision("$N拿起小瓷瓶，呷了一小口玉蜂蜜，顿时不觉得那么累了。\n",me);
	}
	else {
		message_vision("$N拿起小瓷瓶，呷了最后一口玉蜂蜜，顿时不觉得那么累了。\n",me);
	}

	return 1;
}
*/

int do_drink(string arg)
{
	object pl = this_player();

	if( !id(arg) ) return 0;
	if( !living(pl) ) return 0;
	if( pl->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !query("liquid/remaining") )
		return notify_fail( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
	if( (int)pl->query("water") >= (int)pl->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	add("liquid/remaining", -1);
	message_vision("$N拿起" + name() + "呷了一小口" + query("liquid/name") + "。\n",pl);
	pl->add("water", 5);
	pl->add("jingli", 5);

	if( query("liquid/name") == "玉蜂蜜" ) {
		pl->add("jing",30);
		if ((int)pl->query_condition("yufeng_poison")) {
		    pl->apply_condition("yufeng_poison", (int)pl->query_condition("yufeng_poison") - 5);
			tell_object(pl, HIW "玉蜂毒的奇痒减轻了一些！\n" NOR );
		}
	}
	if( query("liquid/name") == "玉蜂蜜水" ) {
		pl->add("jingli",25);
		if ((int)pl->query_condition("yufeng_poison")) {
		    pl->apply_condition("yufeng_poison", (int)pl->query_condition("yufeng_poison") - 2);
			tell_object(pl, HIW "玉蜂毒的奇痒只减轻了一点点！\n" NOR );
		}
	}
	
//	if( pl->query("jingli") > pl->query("max_jingli")) 
//	this_player()->set("jingli", this_player()->query("max_jingli"));

	if( pl->is_fighting() ) pl->start_busy(2);
	if( !query("liquid/remaining") ) {
		write("你已经将" + name() + "里的" + query("liquid/name")
			+ "喝得一滴也不剩了。\n");
		if ( query("worthless") )  set("value", 0);
	}

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	switch(query("liquid/type")) {
		case "alcohol":
			this_player()->apply_condition("drunk",
				(int)this_player()->query_condition("drunk") 
				+ (int)query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	object pl = this_player();

	if( !id(arg) ) return 0;
	if( pl->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !environment(pl)->query("resource/water") )
		return notify_fail("这里没有地方可以装水。\n");

	if ( query("liquid/remaining")==query("max_liquid") 
		&& query("liquid/name")=="玉蜂蜜" ){
		
		message_vision("$N将水慢慢注入" + name() + "里，慢慢摇匀。\n", pl);
		set("liquid/type", "mi-water");
		set("liquid/name", "玉蜂蜜水");
		set("liquid/remaining", query("max_liquid"));
		set("liquid/drink_func", 0);
	}
	else {
		if( query("liquid/remaining") ) 
			message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", pl);
		message_vision("$N将" + name() + "装满清水。\n", pl);

		set("liquid/type", "water");
		set("liquid/name", "清水");
		set("liquid/remaining", query("max_liquid"));
		set("liquid/drink_func", 0);
	}

	if( pl->is_fighting() ) pl->start_busy(2);

	return 1;
}
