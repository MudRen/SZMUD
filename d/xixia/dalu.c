// Code of ShenZhou
// Room: /d/xixia/dalu.c

inherit ROOM;

void create()
{
	set("short", "���д�·");
	set("long", @LONG
����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ���ӡ��·
��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������ż��������в���
���Ƽž�����·����������ת�˸��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"luorilin2",
  "north" : __DIR__"xiaolu",
  "south" : __DIR__"luorilin",
]));
	set("cost", 2);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
