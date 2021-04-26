// August 1 31,2000
// Code by April
// /gumu/mishi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","密室");

        set("long",@LONG
室中也无特异之处，室顶密密麻麻的写满了字迹符号，最右处写著四
个大字：「九阴真经」。西南角绘著一幅图，似与武功无关，凝神细看，
倒像是幅地图，原来古墓东面另有出墓通道。
LONG);

	  set("cost",1);

		  setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push()
{
        object me;
        me = this_player();

        message_vision("$N往上轻推，一条通道就出现了。 
		\n\n",me);
        set("exits/out", __DIR__"mushi");
        remove_call_out("close_door");
        call_out("close_door",15,me);   
        return 1;
}

void close_door()
{
        tell_room(this_object(),"不一会儿，棺底石板轻轻和上了。\n");
        delete("exits/out");
}
