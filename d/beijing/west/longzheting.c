//Cracked by Roath
// Room: /d/beijing/west/longzheting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"chengxiangting",
  "west" : __DIR__"yongruiting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
