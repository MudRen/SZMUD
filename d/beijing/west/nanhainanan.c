//Cracked by Roath
// Room: /d/beijing/west/nanhainanan.c

inherit ROOM;

void create()
{
	set("short", "�Ϻ��ϰ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hubianxiaodao5",
  "east" : __DIR__"hubianxiaodao6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
