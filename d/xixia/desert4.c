// Code of ShenZhou
// Room: /d/xixia/desert4.c

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
  "north" : __DIR__"desert4",
  "west" : __DIR__"desert4",
  "south" : __DIR__"qingcheng",
  "east" : __DIR__"desert3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
