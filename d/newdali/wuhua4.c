// Code of ShenZhou
// Room: /d/dali/wuhua4.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ��ͷ�����ǽ����һ����ľ�󴲣�����ı��쾡�����壬�������ס�
���з���һ�Ű���������������������ڸ�̸���ۡ�
LONG);
	set("objects", ([
		__DIR__"npc/pucong" : 2,
		]));
	set("exits", ([
		"out" : __DIR__"wuhua8.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
