//Cracked by Roath
// Room: /d/beijing/zijincheng/wenyuange.c

inherit ROOM;

void create()
{
	set("short", "��Ԩ��");
	set("long", @LONG
��רΪ�ղ�Ǭ¡������Ĺ�79000���ġ��Ŀ�ȫ�顷���޽���,
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhujingdian",
  "north" : __DIR__"gzxd4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
