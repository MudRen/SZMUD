// Room：/u/athena/dating.c

#include <room.h>
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", YEL"大厅"NOR);
        set("long", @LONG
和别处相比这里显得有点空荡荡的，只有一些可供人们休息的桌椅散布在大厅
的角落。墙壁上挂着各种门派的独门武器，有的锈迹斑斑，有的还隐隐带着血光。
偶尔有人从展览厅走出来，却都十分安静，他们仿佛也在思考着什么，有的嘴角带
着笑容，有的却轻声叹息。
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "east" : __DIR__"jubian",
                "west" : __DIR__"renwu",
                "north" : __DIR__"cangsang",
                "out" : __DIR__"damen",
        ]));
        create_door("out", "大门", "enter", DOOR_CLOSED);
        set("cost", 1);
        setup();
}
