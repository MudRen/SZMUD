//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","终南山武馆");
	set("long",@LONG
武馆的大门上写着几个苍劲大字[终南山武馆]，庄严气派。幕名来此拜师
的人很多，大门的两侧是两头高大的石狮子，往前走就到武馆的大院了。
LONG
	);
	set("exits",([
                "east" : __DIR__"sroad2",
		"west" : __DIR__"wgdayuan",
	]));
          set("objects", ([
          __DIR__"npc/mending" : 2,
          ]));

          set("cost", 1);

	setup();
}
