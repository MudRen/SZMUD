// Code of ShenZhou
// Room: /d/xixia/desert.c

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
  "west" : __DIR__"desert",
  "north" : __DIR__"jingyuan",
  "south" : __DIR__"desert1",
  "east" : __DIR__"desert",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
