//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","乱石岗");
	set("long",@LONG
荒野之外，一堆乱石堆在那里。突然窜出一只老鼠。把过路人给惊出一身
冷汗。前面有块大石头(stone)挡住了去路。
LONG
	);
	set("exits",([
                "northwest" : __DIR__"xiaolu",
	]));
	set("objects",([
               
                 "d/city/npc/stone":2,
        ]));
	set("valid_startroom","1");

        set("outdoors", "changan");
	setup();
}
void init()
{
        add_action("do_move", "move");
}
void check_trigger()
{
        object room;
        if( (int)query("trigger")==8 && !query("exits/southeast") )
        {
message("vision", "你挪了挪巨石，刚好可以容你钻出去。\n", this_object() );
                set("exits/southeast", __DIR__"luanfd");
                if(!( room = find_object(__DIR__"luanfd")) )
                     room = load_object(__DIR__"luanfd");
                message("vision", "南面突然亮了起来。\n", room );
                room->set("exits/northwest", __FILE__);
                delete("trigger");
                call_out("close_passage", 5);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/southeast") ) return;
        message("vision",
"你用力过猛，石头有堵住路了。\n", this_object());

        if( room = find_object(__DIR__"luanfd") )
        {
message("vision", "你用力过猛，石头有堵住路了。\n", room );
                room->delete("exits/northwest");
        }
        delete("exits/southeast");
}

int do_move(string arg)
{
        string dir;

        if( !arg || arg=="" )
        {
                write("你要移什么？\n");

                return 1;
        }

        if( arg=="stone" || arg == "石头")
        {
                this_object()->add("trigger", 1);
                write("你试著用力移动这块巨石，似乎有一点松动....\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}



