//Cracked by Roath
// Room: /d/beijing/zijincheng/houyoumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������Ǭ���ţ������������ţ����̫������������ﾭ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qianqingmen",
  "south" : __DIR__"xiaodao1",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
