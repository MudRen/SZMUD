//Cracked by Roath
// Room: /d/beijing/west/zaichufang2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ɱ�����õ�����ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"huanqiu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
