//Cracked by Roath
// Room: /d/beijing/east/shouhuangdian.c

inherit ROOM;

void create()
{
	set("short", "�ٻʵ�");
	set("long", @LONG
��������˻ʼ��������ڵĻ������ܵ��ų����ơ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"guoyuan",
  "north" : __DIR__"dianmen",
  "east" : __DIR__"guandedian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
