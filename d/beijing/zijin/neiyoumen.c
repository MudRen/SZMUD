//Cracked by Roath
// Room: /d/beijing/zijincheng/neiyoumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ͨ�����ĵ������������Ҫ�Ż�,�ɴ������ǻʵۺͺ�����
��ס�ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"qianqingmen",
  "north" : __DIR__"tongdao1",
  "west" : __DIR__"yangxindian",
  "east" : __DIR__"yuehuamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
