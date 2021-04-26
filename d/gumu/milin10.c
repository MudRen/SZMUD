// July 31,2000
// Code by April
// /gumu/milin10.c

inherit ROOM;

void create()
{
        set("short","花丛");

        set("long",@LONG
你在树林中左转右转，转过山坳，忽然一大丛红花出现在眼前。这丛
红花排开来长达数丈，密密层层，奇香扑鼻。在此花丛掩印下，似乎其间
另有所在。
LONG);


        set("exits", ([
        "north" : __DIR__"milin"+(random(2)+7),
        "west" : __DIR__"milin"+(random(2)+7),
        "south" : __DIR__"milin"+(random(2)+7),
        "east" : __DIR__"milin"+(random(2)+7),
	"enter" : __DIR__"huawu",
                      ]));

          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}
