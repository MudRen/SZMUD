//Cracked by Roath
// Room: /d/beijing/west/zaichufang1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ɱ�����õ�����ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"qiniandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
