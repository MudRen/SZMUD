/*-------------------------------------------------------------
** 文件名: qingjiaoshi.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 请教室
**-----------------------------------------------------------*/


inherit ROOM;

void create()
{
        set("short","请教室");

        set("long",@LONG
这是一间十分大的屋子，在这里有几把椅子，武馆的几位教头正在这
里对武馆弟子指点关于棒类和暗器的武功。
LONG);

         set("exits",([ 
                "northeast" : __DIR__"zoulang1",
                 ]));
 	set("objects", ([
		__DIR__"npc/chenhu" : 1,
		__DIR__"npc/xiaofei" : 1,
	]));

          
        set("cost",0);
        set("no_steal", 1);
        set("no_hit", 1);

     setup();
}

