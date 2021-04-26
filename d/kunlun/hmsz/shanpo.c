// shanpo.c (kunlun)

#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "山坡上");
                  set("long",@long
这里黄沙扑面，寒风透骨，却也着实难熬,你在昆仑山中转来转去，
,四面都是荒凉的戈壁滩和乱石堆,再也找不到出山的途径。
long);
                 set("exits",([
"northup" : __DIR__"conglin",
"southdown" : __DIR__"shanao",
  "eastdown" : "/d/kunlun/bayankala",
]));


set("cost", 3);
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
