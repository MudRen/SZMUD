// Code of ShenZhou
// Room: /d/xiangyang/kedian2.c

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
���ξ����差�͵��¥�����ȣ�ż����Щ�ÿ����ĵ������߹���
Ҳ�м������ƺ�û�ѳ����ս�·������ϣ���ɫ����öࡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"kedian3",
  "down" : __DIR__"kedian",
]));

	setup();
	replace_program(ROOM);
}
