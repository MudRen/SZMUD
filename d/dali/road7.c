// Code of ShenZhou
// Room: /d/newdali/road7.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�������
Ҷ������ϡ�ɡ������ౡ�����ϰϰ��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shilin6",
  "east" : __DIR__"riverbank",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
