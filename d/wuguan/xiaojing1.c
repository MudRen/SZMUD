/*-------------------------------------------------------------
** 文件名: xiaolu1.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 后山小径
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","后山小径");

        set("long",@LONG
这是一条通往后山的林间小路，周围有许多花草和树木。南方有一扇
小木门(door)，是通向武馆的。
LONG);

         set("exits",([ 
                "northeast" : __DIR__"houshan",
//		"west"   : __DIR__"xiaojing2",
                 ]));

        set("item_desc", ([
                "door" : "你可以打开(open)它。\n",
                         ]));   
        
//	create_door("south","木门","north",DOOR_CLOSED);	
         set("outdoors", "wuguan" );
         set("cost",1);
	 set("no_fight", 1);
         set("no_steal", 1);
         set("no_hit", 1);

     setup();
}

void init()
{
	  add_action("do_open", "open");
	  add_action("do_close", "close");
}


void close_door()
{
	 object room;

	 if(!( room = find_object(__DIR__"zhengting")) )
		  room = load_object(__DIR__"zhengting");
    if(objectp(room))
    {
        delete("exits/south");
        message("vision", "门吱吱呀呀地自己合上了。\n",this_object());
        room->delete("exits/north");
        message("vision", "门吱吱呀呀地自己合上了。\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_close(string arg)
{
	object room;
        if (!query("exits/south"))
                return notify_fail("木门已经是关着的了。\n");

        if (!arg || (arg != "door" && arg != "south" && arg != "men"))
                return notify_fail("你要关什么？\n");

        if(!( room = find_object(__DIR__"zhengting")) )
                room = load_object(__DIR__"zhengting");
	delete("exits/south");
	message_vision("$N轻轻地把小木门关上。\n", this_player());
        room->delete("exits/north");
        message("vision", "外面有人把木门关上了。\n", room);
        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("木门已经是开着了。\n");

        if (!arg || (arg != "door" && arg != "south" && arg != "men"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object(__DIR__"zhengting")) )
                room = load_object(__DIR__"zhengting");
        if(objectp(room))
        {
                set("exits/south", __DIR__"zhengting");
                message_vision("$N轻轻地把木门打开。\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "吱地一声，外面有人把木门打开了。\n", room);
                remove_call_out("close_door");
                call_out("close_door", 40);
        }

        return 1;
}
