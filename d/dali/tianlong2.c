// Code of ShenZhou
// Room: /d/dali/tianlong2.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
�տյ�����ͥԺ��ֻ�м�ֻС���������Ľ��ţ�����������
�Կ�������ɮ�������ּ����֡�
LONG
	);
	set("cost", 4);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tianlong6.c",
  "south" : __DIR__"tianlong3.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
