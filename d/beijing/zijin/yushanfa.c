//Cracked by Roath
// Room: /d/beijing/qianqing/yangxindian.c

inherit ROOM;

void create()
{
    set("short", "���ŷ�");
	set("long", @LONG
�ʵ۽��Ŷ������ĵ�.Ǭ�幬�ȴ�,���ŷ��������ĵ�ǰ�ܷ���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north": __DIR__"yangxind",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
