// Code of ShenZhou
// Room: /d/zhongnan/desert1.c

inherit ROOM;

void create()
{
		  set("short", "ɳĮ");
		  set("long", @LONG
����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽�����
�·�����·��
LONG
		  );
		  set("cost", 20);
		  set("outdoors", "xixia");
		  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"desert1",
  "north" : __DIR__"desert1",
  "west" : __DIR__"desert2",
  "east" : __DIR__"shanlu30",
]));
		  set("no_clean_up", 0);

		  setup();
		  replace_program(ROOM);
}


