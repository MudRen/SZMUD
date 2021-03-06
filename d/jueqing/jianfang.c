// Filename:   /d/jueqinggu/jianfang.c 剑房
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <condition.h>
inherit ROOM;

void create()
{
        set("short","剑房");
        set("long",@LONG
剑房壁上、桌上、架上、柜中尽皆列满兵刃，式样繁多，或长逾
七尺，或短仅数寸，有的铁锈斑驳，有的寒光逼人，直看得你眼花撩
乱，西壁上挂着一幅画 （hua），看上去有点不成格局。桌上一只花
瓶中插着的一丛花（flower），只是插得乱七八糟，你不禁顺手想去
整理（order）一下。房门（door）紧关着。
LONG);
    /*    set("exits",([ 
                "north" : __DIR__"shishi1",
                ]));
*/
		set("item_desc", ([
			"hua" :    "一巨幅山水工笔绢画。\n",
			"door" :   "一扇紧闭着的房门。\n",
			"flower" : HIM"一丛娇艳欲滴，美丽异常的情花。\n"NOR,
			]));
        
		set("cost",1);
        setup();
}

void init()
{
	add_action("do_order","order");
	add_action("do_pull","pull");
//	add_action("do_burn","burn");
}

int do_order(string arg)
{
	object me = this_player();
	
	if ( !arg || arg != "flower" && arg != "hua")
		return 0;

	if (arg=="flower"||arg=="hua") 
	{	
		message_vision("$N猛一伸手抓起花枝，手指却被花刺刺中数下。\n", me);	
		me->apply_condition("qh_poison",100);
		message_vision("$N中了情花毒啦。\n", me);
		return 1;
	}
	else
		return notify_fail("插花不是这样的？\n");
}

int do_pull(string arg)
{
        object me = this_player();
        if(!arg)
                return 0;
        if(arg = "door") 
        {
                message_vision("$N伸手轻轻一拉房门。\n",me);
                message_vision("门「吱呀」的一声开了。\n\n",me);
                set("exits/out",__DIR__"shishi1");
                remove_call_out("close_door");
                call_out("close_door",10,me);
        }
        return 1;
}
void close_door()
{
        tell_room(this_object(),"门「吱呀」的一声又关上了。\n");
        delete("exits/out");

}
/*
int do_burn(string arg)
{
	object ob , me = this_player();
	if(!arg || arg != "hua")
		return notify_fail("你要干什么？\n");
	if( !present("fire",me)) return 0;
	if( present("fire",me) && (arg == "hua"))
	{	write("你点燃了火折，伸手过去点燃了画的一角。\n");
	    write("顷刻间，画被烧毁了大半截，西墙也被烧出一大片焦痕。\n");
	    write("半截画幅之下露出一段刀鞘来。\n");
	   	write("铛锒一声，一把金刀从半截画后掉脱到地上。\n");

		ob = new("/d/jueqing/obj/jindao");
		ob->move("/d/jueqing/jianfang");
		ob->set_temp("marks/金刀", 1);
		
	    add("jindao_count", -1);	
	}
		return 1;
}
*/