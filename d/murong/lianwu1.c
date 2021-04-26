// Code of ShenZhou
//ROOM/d/murong/lianwu1
//arthurgu 1999.9

#include "room.h"
inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
   这里是燕子坞的练武场，四周放满了十八般兵器，传说
慕容氏通晓天下武技，可能此言不虚。北边空地有一张石桌,
桌面上仿佛依稀有点浅浅的指痕。
LONG
        );
      
        set("cost", 1);
        set("exits", ([ 
        "enter" : __DIR__"huayuan3",
        "west" : __DIR__"lianwu",
        "east" : __DIR__"sishu.c",
                      ]));
        set("outdoors", "murong");
        create_door("enter","木门","out", DOOR_CLOSED);
	 setup();
}

void init()
{
        add_action("do_draw", "draw");
        add_action("do_draw", "hua");
}

int do_draw(string arg)
{
object me = this_player();
        if ( !arg || arg != "table" )
             return notify_fail( "什么？\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("什么？\n");
if ((int)me->query_skill("finger",1) <= 120 ) {
             me->improve_skill("finger", me->query("str"));
             write( "你伸出手指用力在石桌上划来划去,感到手指酸痛极了。\n");
          
me->add("jingli", -35);
} else { write( "你伸出手指在石桌上划动,石屑溅了满地。\n");
}
return 1;
}