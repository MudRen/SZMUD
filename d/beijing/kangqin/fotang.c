//Cracked by Roath
// Room: /d/beijing/kangqin/fotang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�侫�µķ��á�����񻨡�����һ������㰸�����ż����㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"mishi",
  "west" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	set("objects",([
                "/d/beijing/npc/puren.c":1,
        ]));

	setup();
	replace_program(ROOM);
}
