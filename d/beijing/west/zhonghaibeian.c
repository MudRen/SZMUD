//Cracked by Roath
// Room: /d/beijing/west/zhonghaibeian.c

inherit ROOM;

void create()
{
	set("short", "�к�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hubianxiaodao1",
  "north" : __DIR__"beihaiqianmen",
  "east" : __DIR__"hubianxiaodao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
