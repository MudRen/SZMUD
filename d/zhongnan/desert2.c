// Code of ShenZhou
// Room: /d/zhongnan/desert2.c

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
  "south" : __DIR__"desert2",
  "north" : __DIR__"desert2",
  "west" : "/d/xixia/desert3",
  "east" : __DIR__"desert1",
]));
		  set("no_clean_up", 0);

		  setup();
		  replace_program(ROOM);
}

