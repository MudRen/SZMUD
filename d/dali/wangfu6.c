// Code of ShenZhou
// Room: /d/dali/wangfu6.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ��СС�����ܾ�ɫ�����������ˡ�ͤ������һ��ʯ
��������ʯ�ʣ���������Ϣ���Ա߹������죬���ݴ��к����׷�
����ʱ�����Կ�����ֻС�޴��Ա��ܹ���
LONG
	);
	set("cost", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wangfu3.c",
]));
set("wangfu", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
