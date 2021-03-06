// Filename:   /d/jueqinggu/shiku.c 石窟
// Jiuer, Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","石窟");
	set("long",@LONG
这是个天然生成的石窟，深不见尽头，顶上有个圆径丈许的大孔
(hole)，只是那大孔离地一百余丈，纵在窟中大声呼叫，上面有人经过
也未必听见，谁要是不小心从孔中掉了进来，怕不能再出去。石窟中日
光所及处生了一棵大枣树，树皮(shupi)又粗又厚。
LONG);
	
	set("exits",([ 
		"east" : __DIR__"tongdao",])); 	
	
	set("objects", ([ 
		CLASS_D("jueqing") + "/qiu" : 1,  ]));
	
	set("item_desc", ([
		"hole" : HIW"日光从孔中透射进来。\n"NOR,
		"shupi" : "割下(chop)大栆树皮可以做(make)条绳子爬上去。\n"
		]));
	
	set("rope_count", 2);
	
	set("cost",2);
	setup();
}

void init()
{
	add_action("do_chop","chop");
	add_action("do_make","make");
	add_action("do_climb","climb");
}

int do_chop(string arg)
{
	object weapon, me = this_player();

	if( !arg || arg != "shupi")
		return notify_fail("你要干什么? \n");
	
	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("id") !="bishou")
		return notify_fail("剥树皮最好用把匕首。\n");
	
	if (query("rope_count") < 1)
		return notify_fail("这儿的树皮都被剥光了，等它们长出来时再砍吧。\n");
	
	me->receive_damage("jingli", 5);
	message_vision("$N操上手中的家伙，从树上剥下一些树皮。\n", me);
	
	if ( random(10) >= 7) {
		write("你剥下的树皮似乎足够做(make)一个长索(rope)了。\n");
		me->set_temp("marks/剥", 1);
	}
		me->start_busy(10);
		return 1;
}

int do_make(string arg)
{
	object ob, me = this_player();
	if( !arg || arg!="rope" )
		return notify_fail("你要做甚么？\n");

	if( !me->query_temp("marks/剥") )	
		return notify_fail("你要做甚么？\n");

	write("你割下枣树树皮，搓绞成索。\n");
	me->delete_temp("marks/片");
	me->set_temp("marks/ok",1);	
	add("rope_count", -1);
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();
	
	if ( !arg && arg != "up" && arg != "hole")
		return notify_fail("你要干什么？\n");
	
	if( !me->query_temp("marks/ok") )
		return notify_fail("你要干什么？\n");

	if ( arg == "up" || arg == "hole") {	
		message_vision("$N哼哧哼哧地向洞口爬了上去。\n", me);
		me->start_busy(10);
		me->move(__DIR__"liguifeng");
		me->delete_temp("marks/ok");
		message_vision("$N气喘嘘嘘地从石洞里爬了上来。\n", me);
		return 1;
	}
    return 0;
}
