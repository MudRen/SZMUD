// Code of ShenZhou
// Room: /d/xixia/desert3.c

inherit ROOM;

void create()
{
	set("short", "ɳĮ");
	set("long", @LONG
����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽�����
�·�����·��
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"desert3",
 "west" : "/d/xixia/desert3",
  "south" : __DIR__"desert2",
  "east" : "/d/zhongnan/desert2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
