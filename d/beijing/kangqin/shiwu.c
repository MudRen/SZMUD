//Cracked by Roath
// Room: /d/beijing/kangqin/shiwu.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ���������ʯ�ݣ����������������ſ��м���
����������Ѳ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden",
  "south" : __DIR__"xiaotang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
