// July 31,2000
// Code by April
// /gumu/liangongshi1.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

int do_study(string arg);

void create()
{
	set("short","练功室");

	set("long",@LONG
这石室形状甚是奇特，北窄南宽，成为梯形。东边半圆，西边却作三
角形状，室顶石壁（ceiling）上刻满了诸般花纹符号，均是以利器刻成，
或深或浅，殊无规则。西边是男练功房。
LONG);

	set("item_desc",(["ceiling" : "
这石室原是全真派始祖王重阳当年练武的地方。
\n"]));

	set("exits",([ 
		"east" : __DIR__"mudao19",
		"southeast" : __DIR__"jianshi1",
		"southwest" : __DIR__"biaoshi1",
		"west" : __DIR__"liangongshi3", 
		"north" : __DIR__"zhangshi1",
		]));

	set("objects", ([ 
		"/kungfu/class/gumu/npc/baiyi1": 1, 
		]) );
                  
	create_door("west", "木门", "east", DOOR_CLOSED);
          
	set("cost",1);
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "女性" && dir == "west" && !wizardp(me) )
		return notify_fail("看清楚点，那是男练功房！\n");

	if (dir =="west" && me->query("family/family_name")!="古墓派" 
		&& objectp(present("baiyi girl", environment(me))))
			return notify_fail("白衣少女伸手挡住了你的去路：此处本派禁地，请止步。\n");

	return ::valid_leave(me, dir);
}

int do_study(string arg)
{
	object me = this_player();
	int f1, f2;

	if ( !arg || ( arg != "ceiling" ) ) return 0;

	if (me->is_busy()) return notify_fail("你忙着呢！\n");

	if ( (int)me->query_skill("literate", 1) < 1){
		write("你不识字，先学点文化(literate)吧。\n");
		return 1;
	}

	f1 = me->query_skill("quanzhen-xinfa", 1);
	f2 = me->query_skill("yunu-xinjing", 1);

	if ((f1 >= 30) || (f2>=30)){
		write("你研究了半天一无所获。\n");
		write("看来要领会更高深的全真武学，只有去全真了。\n");
		return 1;
	}

	if (me->query("jing")<15) {
		write("你现在头晕眼花，看不清天花板上的字。\n");
		return 1;
	}

	me->receive_damage("jing", 10, "精力衰竭而死");

	message_vision("$N正专心研读天花板上的全真心法。\n", me);

	me->improve_skill("quanzhen-xinfa", me->query_int()/2);
	write("你对着天花板上的心诀，似乎对全真武学略有了解。\n");

	return 1;
}
