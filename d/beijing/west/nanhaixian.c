//Cracked by Roath
// Room: /d/beijing/west/nanhaixian.c

inherit ROOM;

void create()
{
	set("short", "�Ϻ�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"fuyoujie3",
  "north" : __DIR__"hubianxiaodao3",
  "south" : __DIR__"hubianxiaodao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
