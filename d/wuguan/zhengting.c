/*-------------------------------------------------------------
** 文件名: zhengting.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 武馆正厅
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","武馆正厅");

        set("long","这里是武馆的正厅，正上方挂着一块大匾上书四个大字"+HIY"尚武精神"NOR+"。正
中挂着一幅画(hua)和一副对联(duilian)，大厅里摆了几张桌椅。在画的
左侧有一扇小木门(door)，是通往后山的。
");
        set("no_steal", 1);
        set("valid_startroom",1);

         set("exits",([ 
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"zoulang2",
                "south" : __DIR__"yanwuting2", 
                 ]));
         
         set("item_desc", ([
                "hua" : "此画画的是武林中的一位旷世大侠，这位大侠正是此武馆的创建人。\n",
		"door" : "一扇小木门，你可以打开(open)它。\n",
                "duilian" : "
   	         ┏━━┓     ┏━━┓
		 ┃"+HIC" 鼙 "NOR+"┃     ┃"+HIC" 鹏 "NOR+"┃
		 ┃"+HIC" 鼓 "NOR+"┃     ┃"+HIC" 鸟 "NOR+"┃
		 ┃"+HIC" 动 "NOR+"┃     ┃"+HIC" 将 "NOR+"┃
		 ┃"+HIC" 天 "NOR+"┃     ┃"+HIC" 图 "NOR+"┃
		 ┃"+HIC" 地 "NOR+"┃     ┃"+HIC" 翼 "NOR+"┃
		 ┃"+HIC"    "NOR+"┃     ┃"+HIC"    "NOR+"┃
		 ┃"+HIC" 绝 "NOR+"┃     ┃"+HIC" 少 "NOR+"┃
                 ┃"+HIC" 域 "NOR+"┃     ┃"+HIC" 年 "NOR+"┃
		 ┃"+HIC" 逢 "NOR+"┃     ┃"+HIC" 须 "NOR+"┃
		 ┃"+HIC" 知 "NOR+"┃     ┃"+HIC" 努 "NOR+"┃
		 ┃"+HIC" 己 "NOR+"┃     ┃"+HIC" 力 "NOR+"┃	
		 ┗━━┛     ┗━━┛\n",
          ]));

	set("objects", ([
		__DIR__"npc/mawude" : 1,
	]));

//	create_door("north", "木门", "south", DOOR_CLOSED);
	"/clone/board/wuguan_b"->foo();

        set("cost",1);

     setup();
}

void init()
{
   object me = this_player();

   if ( interactive(me) && me->query("wuguan/job_pending") ) {
	me->set_temp("wuguan_job/zt", 1);
   }
   
	  add_action("do_open", "open");
	  add_action("do_close", "close");     
}

void close_door()
{
        object room;

        if(!( room = find_object(__DIR__"xiaojing1")) )
                room = load_object(__DIR__"xiaojing1");
        if(objectp(room))
        {
                delete("exits/north");
		message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
                room->delete("exits/south");
                message("vision", "门吱吱呀呀地自己合上了。\n", room);
        }
}

int do_close(string arg)
{
	 object room;
        if (!query("exits/north"))
                return notify_fail("木门已经是关着的了。\n");

        if (!arg || (arg != "door" && arg != "north" && arg != "men"))
                return notify_fail("你要关什么？\n");

        if(!( room = find_object(__DIR__"xiaojing1")) )
                room = load_object(__DIR__"xiaojing1");
	delete("exits/north");
	message_vision("$N轻轻把小木门关上了。\n", this_player());
        room->delete("exits/south");
        message("vision", "里面有人把木门关上了。\n", room);
        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/north"))
                return notify_fail("木门已经是开着了。\n");

        if (!arg || (arg != "door" && arg != "north" && arg != "men"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object(__DIR__"xiaojing1")) )
                room = load_object(__DIR__"xiaojing1");
        if(objectp(room))
        {
                set("exits/north", __DIR__"xiaojing1");
                message_vision("$N轻轻地把木门打开。\n", this_player());
                room->set("exits/south", __FILE__);
                message("vision", "吱地一声，里面有人把木门打开了。\n", room);
                remove_call_out("close_door");
                call_out("close_door", 40);
        }

        return 1;
}
/*int valid_leave(object me, string dir) 
{ 
	object *inv; 
	int i; 
	inv = all_inventory(me); 

        if ((dir == "south" || dir == "north" || dir == "west") 
             && !(int)me->query_temp("mark/马") && !wizardp(me) )
		return notify_fail("马五德喝道：扬威武馆岂能让你乱闯。\n"); 
	return ::valid_leave(me, dir); 
}             
//*///ir); 
//}             
