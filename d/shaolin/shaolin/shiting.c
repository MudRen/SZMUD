// /d/shaolin/shiting.c
// 昆仑派弹琴之处


#include <ansi.h>
inherit ROOM;

#include "/d/kunlun/obj/shijing.c"

void create() {
    set("short", "石亭");
	
	set("long", @LONG
这是路边一座小小的石亭，平日供游人香客歇脚所用。石亭
修建年月已久，石柱上的漆早已剥落，斑斑点点。亭边有一泉小
溪，溪水清澈，令人观之欲饮。
LONG
	);
	
	set("exits", ([
		"westdown" : __DIR__"shijie8",
	]));
   set("fjing",1);

	set("outdoors", "shaolin");
	set("cost", 2);
	set("resource/water", 1);
	setup();
}

void init() 
{
    add_action("do_play", "play");
    add_action("do_giveup", "giveup");
	add_action("do_fight", "fight");
}

int do_fight(string arg)
{
	object ob, me=this_player();
	if (!present("shaolin dizi", environment(me)))
		return 0;
	ob = me->query_temp("challenger");
	if ((arg == "dizi" || arg == "shaolin dizi") && ob && !me->is_fighting(ob))
	{
		message_vision(HIC"\n$N有意显示本领，右手琴声不断，却单用左手出招。\n"NOR, me);
		return 0;
	}
	return 0;
}

int do_play(string arg) 
{
    object ob, challenger, me = this_player(), *inv;
    int count, can_play, i;
	ob = this_object();

	if (me->is_busy())
        return notify_fail("你现在正忙着呢！。\n");

	if (!arg || (arg != "qin" && arg != "yao qin" ))
		return notify_fail("你要弹什么？\n");
	
	inv = all_inventory(me);
	can_play = 0;
	for(i=sizeof(inv)-1; i>=0; i--)
		if (inv[i]->query("id") == "yao qin")
			can_play = 1;
	if (!can_play)
		return notify_fail("身上不带琴难道弹手指吗？\n");
	
	if (ob->query_temp("kunlun_played"))
		return notify_fail("已经有人在弹奏曲子了，君子成人之美，岂可扰了他人雅兴。\n");

    
	if (present("shaolin dizi", environment(me)))
		return notify_fail("少林寺的和尚找麻烦来了，还弹？\n");

	if (me->query("jingli") < 500)
    	return notify_fail("你已经累得不行了，歇歇吧。\n");
	message_vision("\n$N取出身上遥琴，左手按节捻弦，右手弹了起来，琴声远远的送了出去，在山中回荡。\n", me);
	message_vision(songs[random(sizeof(songs))], me);
	me->start_busy(2);
	
	me->add("jingli", -random(30));
    me->start_busy(1);
    if ( (wizardp(me) || me->query("family/family_name") == "昆仑派" && me->query_skill("qinqi-shuhua",1) >= 120)
         && random(5) == 2 && !present("shaolin dizi", environment(me)))
		 
	{
        message_vision(HIR "亭子外面突然进来一位僧人，对$N合十为礼。\n" NOR, me);
        this_object()->set_temp("fighter", me);
		challenger = new(__DIR__"npc/kunlun_jobnpc");
        challenger->move(environment(me));
        me->set_temp("challenged", 1);
        me->set_temp("challenger", challenger);
		challenger->set_temp("opponent", me);
		
    }
	return 1;
}



int do_giveup() {
    object ob, me = this_player();

    if ( me->query_temp("challenged") 
		&& present(me->query_temp("challenger"), environment(me)) ) 
	{
			ob = me->query_temp("challenger");
            message_vision("\n$N拱手道：“若是琴音扰了大和尚们清修，在下这就离开。”\n", me);
            me->add("combat_exp", -random(20));
        
        me->delete_temp("challenger");
        me->delete_temp("challenged");
        message_vision("\n$N离开了。\n", ob);
        destruct (ob);
    }
    else
        return notify_fail("什么？\n");

    return 1;
}            
        
int valid_leave(object me, string dir)
{
    object ob;

    ob = me->query_temp("challenger");
	if ( me->query_temp("challenged") 
		&& objectp(ob) 
		&& me == ob->query_temp("opponent") )
	{
		message_vision("\n$N拦住$n，说道：“" + RANK_D->query_respect(me) + "在少林寺高声喧哗，没个交待，难道就这样走了？”\n", ob, me);
		return notify_fail("看来是走不掉了，想想办法吧。\n");;
	}

    else 
	{ 
        me->delete_temp("challenged");
        me->delete_temp("challenger");
 	}
    return ::valid_leave(me, dir);
}
