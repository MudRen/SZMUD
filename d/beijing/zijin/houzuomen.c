//Cracked by Roath
// Room: /d/beijing/zijincheng/houzuomen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������Ǭ���ţ������������ţ����̫������������ﾭ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"qianqingmen",
  "south" : __DIR__"xiaodao2",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
