//Cracked by Roath
// Room: /d/beijing/west/beihaidaqiao.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beihaiximen",
  "east" : __DIR__"chengguangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
