// workroom.c 慕容皇
// maxking by 2002.09.03 
// Room: /u/maxking/workroom.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create() 
{
set("short",BLINK+HIW"墨香居室"NOR);
set("long",
"这是一座富丽堂皇的大宅院，两头高大的石狮子镇住了大门 
两侧，大门上的朱漆足足有三寸厚。门上一张匾，上书"CYN"“"NOR""NOR+BLINK+HIG"龙府"NOR""CYN"”"NOR"
两个大字。
\n");
set("valid_startroom",1);
set("exits", ([
"maxking": "/u/maxking/workroom",
"rabit": "/u/rabit/workroom",
"cs": "/d/city/guangchang"
]));
              call_other("/clone/board/longnv_b", "???"); 
setup();
}
