// August 1 31,2000
// Code by April
// /gumu/mushi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","墓室");

        set("long",@LONG
你一进来，不由得打了个寒噤。空空旷旷的一座大厅上并列放着五具
石棺(coffin)。两具石棺棺盖已密密盖著，里面长眠着古墓派的先人。另
外三具的棺盖却只推上一半，也不知其中有无尸体。
LONG);

	  set("item_desc",(["coffin" : "棺盖内侧有字，「玉女心经，技压全真。重阳一生，不弱於人。」这十六个
字以浓墨所书，笔力苍劲，字体甚大。
\n"]));

	  set("exits",(["east" : __DIR__"mudao22"
			 ])
			  );

	create_door("east","沉重的石门","west", DOOR_CLOSED);

	  set("cost",1);

		  setup();
}

void init()
{
        add_action("do_lift","lift");
}

int do_lift(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg == "" ) return 0;

        if( arg == "coffin") 
        {
        message_vision("$N当即跃入棺中，四下摸索，果然摸到个可容一手的凹处。於是紧紧握住了转而後提，只听喀喇一响，棺底石板应手而起...... 
		\n\n",me);
        set("exits/enter", __DIR__"mishi");
        remove_call_out("shut_door");
        call_out("shut_door",15,me);   
                return 1;
        }
        else
                return notify_fail("你要干什么？\n");
}

void shut_door()
{
        tell_room(this_object(),"不一会儿，棺底石板轻轻和上了。\n");
        delete("exits/enter");
}
