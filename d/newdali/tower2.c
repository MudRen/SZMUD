// Code of ShenZhou
// Room: /d/dali/tower2.c

inherit ROOM;

void create()
{
	set("short", "�ڶ���");
	set("long", @LONG
Ϊ�������񣬸��б��飬����¡�𣬽�ڱ��֣����Ⱪ�𣬼�������С�
LONG);
	set("exits", ([
		"up" : __DIR__"tower3",
		"down" : __DIR__"tower1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
