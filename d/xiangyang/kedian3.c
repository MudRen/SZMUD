// Code of ShenZhou
// Room: /d/xiangyang/kedian3.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ��ͷ����������Ǽ򵥣�ǽ�߰���һ�Ŵ��̡������ƺ�
��Щ���ο�������һ�𣬱�¸����졣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"kedian2",
]));

	setup();
	replace_program(ROOM);
}
