// kunlun 灵位密室
// by earl
inherit ROOM;
int do_use(string arg);
void create()
{
        set("short", "灵位密室");
        set("long", @LONG
你在黑暗里什么也看不见。
LONG
);
set("invalid_startroom", 1);
        setup();
}
void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 5, this_object());
             write(
"你取出火折一晃，凑上前去点燃了其中的一只火把，也不知是什么机关。\n");
        set("long", @LONG
房子里供奉着张翠山的灵位,不过好像一切都是刚布置好的。
LONG
        );
        set("exits", ([
                "north" : __DIR__"didao"+random(11),
                "south" : __DIR__"didao"+random(11),
                "east" : __DIR__"didao"+random(11),
                "west" : __DIR__"didao"+random(11),
        ]));
           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("你想点燃什么？\n");
        }
}

void close(object room)
{
        message("vision","不一会儿，墙上的火把就熄灭了。\n", room);
        set("long", @LONG
你在黑暗里什么也看不见。
LONG
);
        room->delete("exits");
}
