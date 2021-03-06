/*-------------------------------------------------------------
** 文件名: yiliaoshi.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 武馆医疗室
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","医疗室");
	    set("long","这里是武馆的医疗室，摆设十分的简单，在靠墙的的地方放了一个很
大的药柜(yaogui)。一位年龄很大的大夫正在给受伤的人治疗，他就是
马馆主请来的神医，他救过的人不计其数，被称为“华佗再世”，但是没人
知道他有多大年纪了。
");
		set("no_fight", 1);
        set("no_steal", 1);
        set("no_hit", 1);	      
		set("valid_startroom",1);

        set("exits",([ 
                "north" : __DIR__"zoulang2",
                ]));

         set("item_desc", ([
                "yaogui" : "这是一个药铺常见的药柜，这个药柜有百余个抽屉，每个小抽屉上都写着药名，想必药品很多很全。\n",
				]));
		set("objects", ([
				__DIR__"npc/doctor" : 1,
				]));
         
        set("cost",1);

     setup();
}

