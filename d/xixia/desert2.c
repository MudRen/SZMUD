// Code of ShenZhou
// Room: /d/xixia/desert2.c

inherit ROOM;

void create()
{
	set("short", "ɳĮ");
	set("long", @LONG
����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽�����
�·�����·������ǰ��ɳ������һ����Ѩ��
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"desert2",
  "north" : __DIR__"desert3",
  "west" : __DIR__"desert1",
  "east" : __DIR__"desert2",
  "enter" : __DIR__"cave",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
