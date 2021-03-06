// Code of ShenZhou
// wineskin.c  酒袋

inherit ITEM;
//inherit F_LIQUID;

void create()
{
	set_name("花雕酒袋", ({"jiudai", "skin", "huadiao"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装高级花雕酒的大酒袋。\n");
		set("unit", "个");
		set("value", 120);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "花雕酒",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

void init()
{
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
}


int do_drink(string arg)
{
    object me = this_player();
	if( !living(this_player()) ) return 0;
	if ( arg == "play" )
	{
	    me->clear_condition();
	    me->set( "qi", me->query( "max_qi" ));
	    me->set( "eff_qi", me->query( "max_qi" ));
	    me->set( "jingli", me->query( "max_jingli" )*2);
	    me->set( "neili", me->query( "max_neili" )*2);
	}	
	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
	add("liquid/remaining", -1);
	message_vision("$N拿起" + name() + "咕噜噜地喝了几口" + query("liquid/name")
		+ "。\n", this_player());
	this_player()->add("water", 30);
	this_player()->add("jingli", 5);
	if( !query("liquid/remaining") ) 
	{
		write("你已经将" + name() + "里的" + query("liquid/name")
			+ "喝得一滴也不剩了。\n");
		set("value", 0);
	}
	return 1;
}

int do_fill(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !environment(this_player())->query("resource/water") )
		return notify_fail("这里没有地方可以装水。\n");

	if( query("liquid/remaining") )
		message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", this_player());
	message_vision("$N将" + name() + "装满清水。\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "清水");
	set("liquid/remaining", query("max_liquid"));
	return 1;
}


