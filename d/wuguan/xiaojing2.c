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
这是一条通往后山深处的林间小路，周围有许多花草和树木。再向西
走好像是一个峭壁。
LONG);

         set("exits",([ 
                "west" : __DIR__"cliff1",
                "east" : __DIR__"xiaojing1",
                 ]));

         set("outdoors", "wuguan" );
         set("cost", 1);
	 set("no_fight", 1);
         set("no_steal", 1);
         set("no_hit", 1);
     setup();
     }