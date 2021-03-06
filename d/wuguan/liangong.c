//Created by Zyu on k1-8-4
//练功房

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
练功房是供新手们修练功夫或研读武籍的地方。房内的摆设十分的简 
单，以免定力不足的新手行功时分心，以至于走火入魔。北面墙上刻着四
个大字(word)以戒众练功者。南边是回休息室的走廊。 
LONG
        );

	set("no_steal", 1);

	set("item_desc", ([
		"word" :
			 "这「出心入定」四个字当真写得巨大无比！\n",
	]));

        set("exits", ([
                "south" : __DIR__"zoulang3",
        ]));

        set("cost", 0);
        setup();

}

void init()
{
//        add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "word" ) return notify_fail("在这儿你怎么能够领悟功夫呢！\n");

	write("\n你突然发现大字写的有些蹊跷，上前仔细一看，发现还有一行小字：「从我者得天机！逆天吧！」\n\n");

	message("vision",
	CYN+me->name()+"连连怪笑，道：「谁如不听我话，我喀喇一下，就扭断他的脖子。」\n\n"+NOR,
	environment(me), ({me}));
	write(CYN"你连连怪笑，道：「谁如不听我话，我喀喇一下，就扭断他的脖子。」\n"NOR);

	message("vision",
	"只听墙壁突然响了一下，"+me->name()+"飞快地推墙没入其中。墙壁很快就恢复了原状！\n",
	environment(me), ({me}));
	write("只听墙壁突然响了一下，你飞快地推墙没入其中。墙壁很快就恢复了原状！\n");

	me->set_temp("marks/eshen", 1);
	me->move(__DIR__"mishi");
	return 1;
}
