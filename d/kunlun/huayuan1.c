#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "花园");
		  set("long",@long
这是一个花园。园中的鲜花正怒放着，走入这里，仿佛连空气都是香的。
西面是琴房，南面是长廊，北面是条平整的石板路。
long);
		 set("exits",([
"north" : __DIR__"shilu1",
"south" : __DIR__"lang2",
"west" : __DIR__"qinshi1",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
