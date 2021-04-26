//Cracked by Roath
// Room: /d/beijing/zijincheng/shenwumen.c

inherit ROOM;

void create()
{
	set("short", "神武门");
	set("long", @LONG
这是紫禁城的后宫门，此往北就出了紫禁城。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shunzhenmen",
  "west" : __DIR__"tongdao8",
  "north" : "/d/beijing/jingshan",
  "east" : __DIR__"tongdao7",
]));
  	set("objects", ([
		 "/d/beijing/npc/shiwei1" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        if ((dir=="south" || dir=="west" || dir=="east") && me->query("class")!="officer" && (objectp(present("yideng shiwei", environment(me)))))
                return notify_fail("银甲侍卫上前挡住你，朗声说道：皇宫禁地，禁止闲杂人等出入！\n");
        return ::valid_leave(me, dir);
}
