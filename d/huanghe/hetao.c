// Code of ShenZhou
// Room: /d/forest/hetao.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ե����ƺӾź�������һ�ס������׵������ϵͳ�������
���֣�����ׯ�ڵĺõط���
LONG
	);
	set("cost", 3);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/xixia/qingcheng",
  "east" : __DIR__"huanghe2",
  "southwest" : __DIR__"huanghe1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
