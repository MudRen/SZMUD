//Cracked by Roath
// Room: /d/beijing/west/chengguangdian.c

inherit ROOM;

void create()
{
	set("short", "�й��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"beihaiqianmen",
  "north" : __DIR__"yonganqiao",
  "west" : __DIR__"beihaidaqiao",
  "east" : __DIR__"hubianxiaodao7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
