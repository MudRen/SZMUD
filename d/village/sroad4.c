// Code of ShenZhou
// Room: /d/village/sroad4.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村中人家不
多，而且大都生活很艰辛。这是一条南北向的碎石路，往北就是村子中心的打谷场
了，东面是村里唯一的青砖瓦房。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"square",
  "south" : __DIR__"sroad3",
  "east"  : __DIR__"bighouse1",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


